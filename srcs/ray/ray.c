#include "ray_private.h"
#include "texture_private.h"
#include "ray.h"

double	*ray_postable(void)
{
	static double	table[WIN_WIDTH];
	static int		init = 0;
	int				x;

	if (!init)
	{
		init = 1;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			table[x] = x / (double)SCREEN_CX - 1;
		}
	}
	return (table);
}

void	ray_quadrant(t_ray *ray)
{
	ray->side.x = (RAY_SIDE_POS(ray->dir.x, ray->pos.x, ray->rounded.x));
	ray->side.x *= ray->delta.x;
	ray->side.y = (RAY_SIDE_POS(ray->dir.y, ray->pos.y, ray->rounded.y));
	ray->side.y *= ray->delta.y;
}

void	ray_delta(t_ray *ray)
{
	t_vec2		d2;

	d2.x = ray->dir.x * ray->dir.x;
	d2.y = ray->dir.y * ray->dir.y;
	ray->delta.x = sqrt(1 + d2.y / d2.x);
	ray->delta.y = sqrt(1 + d2.x / d2.y);
}

void	ray_dir(t_ray *ray, t_cam *cam)
{
	ray->dir.x = cam->dir.x + cam->screen.x * ray->cam_x;
	ray->dir.y = cam->dir.y + cam->screen.y * ray->cam_x;
}

void	ray_pos(t_ray *ray, t_cam *cam)
{
	ray->pos.x = cam->pos.x;
	ray->pos.y = cam->pos.y;
	ray->rounded.x = ray->origin.x;
	ray->rounded.y = ray->origin.y;
}

int		ray_trace(t_ray *ray, t_map *map)
{
	int		hit;
	int		obj;

	hit = 400;
	while (hit--)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->rounded.x += ray->quadrant.x;
			ray->from = 1;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->rounded.y += ray->quadrant.y;
			ray->from = 0;
		}
		if ((obj = mapCheckCollid(map, ray->rounded.x, ray->rounded.y)))
			return (obj);
	}
	return (-1);
}

void	ray_dist(t_ray *ray)
{
	if (ray->from)
	{
		ray->quadrant.z = (1 - ray->quadrant.x) >> 1;
		ray->pos_from = ray->pos.x;
		ray->dir_from = ray->dir.x;
		ray->dir_oppo = ray->dir.y;
		ray->pos_oppo = ray->pos.y;
		ray->rounded_from = ray->rounded.x;
	}
	else
	{
		ray->quadrant.z = (1 - ray->quadrant.y) >> 1;
		ray->pos_from = ray->pos.y;
		ray->dir_from = ray->dir.y;
		ray->pos_oppo = ray->pos.x;
		ray->dir_oppo = ray->dir.x;
		ray->rounded_from = ray->rounded.y;
	}
	ray->dist = (ray->rounded_from - ray->pos_from + ray->quadrant.z) / ray->dir_from;
}

void	ray_traceall(t_render *r, t_cam *cam, t_map *map)
{
	int		x;
	t_ray	ray;

	ray.origin.x = (int)cam->pos.x;
	ray.origin.y = (int)cam->pos.y;
	ray.screen_dist = cam->screen_dist;
	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		ray.cam_x = ray_postable()[x];
		ray.x = x;
		ray_pos(&ray, cam);
		ray_dir(&ray, cam);
		ray_delta(&ray);
		point2d_quadrant(&ray.quadrant, &ray.dir);
		ray_quadrant(&ray);
		if ((ray.obj = ray_trace(&ray, map)))
		{
			ray_dist(&ray);
			cam->lineDist[x] = ray.dist;
			text_fillLine(r, &ray, cam->z);
		}
	}
}