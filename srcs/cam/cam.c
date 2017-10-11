#include "cam.h"
#include "cam_private.h"

t_cam		*cam_init(double x, double y)
{
	t_cam	*cam;

	cam = ft_salloc(sizeof(t_cam));
	cam->pos.x = x;
	cam->pos.y = y;
	cam->screen.x = 0;
	cam->screen.y = 0.6;
	cam->screen_dist = SCREEN_CX / tan(FROM_ANGLE(30));
	cam->dir.x = -1;
	cam->dir.y = 0;
	cam->z = SCREEN_CY;
	return (cam);
}

void		cam_free(t_cam *cam)
{
	if (cam)
		free(cam);
}

void		cam_applyAngle(t_cam *cam, double coss, double sins)
{
	double		tmp;

	tmp = cam->dir.x;
	cam->dir.x = cam->dir.x * coss - cam->dir.y * sins;
	cam->dir.y = tmp * sins + cam->dir.y * coss;
	tmp = cam->screen.x;
	cam->screen.x = cam->screen.x * coss - cam->screen.y * sins;
	cam->screen.y = tmp * sins + cam->screen.y * coss;
}

void		cam_applyVel(t_cam *cam, double vel)
{
	cam->pos.x += vel * cam->dir.x;
	cam->pos.y += vel * cam->dir.y;
}

t_vec2		*cam_pos(t_cam *c)
{
	return (&c->pos);
}

t_vec2		*cam_dir(t_cam *c)
{
	return (&c->dir);
}
