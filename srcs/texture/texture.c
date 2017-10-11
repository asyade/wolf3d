#include "texture_private.h"
#include "texture.h"

int		text_pixshadow(unsigned int pix, double delta)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (delta < SHADOW_START)
		return (pix);
	delta *= SHADOW_LEVEL;
	r = ((pix & 0x00ff0000) >> 16) / delta;
	g = ((pix & 0x0000ff00) >> 8) / delta;
	b = (pix & 0x000000ff) / delta;
	return (r << 16 | g << 8 | b);
}

void	text_fillLine(t_render *r, t_ray *ray, int z)
{
	t_point3	limits;
	int	y;
	int	y_block;
	int	h;
	double	x_real;
	int		x_text;
	t_texture	*text;
	int			y_text;

	if (ray->obj < TEXT_COUNT && ray->obj >= 0)
		text = texture_set()[ray->obj];
	else
		text = texture_set()[0];
	h = ray->screen_dist / ray->dist;
	limits.x = SCREEN_CY - (h >> 1);
	limits.y = limits.x + h;

	x_real = ray->pos_oppo + ray->dist * ray->dir_oppo;
	x_real -= floor(x_real);
	x_text = x_real * text->width;
	
	y = -1;
	while (y < limits.x && y++ < WIN_HEIGHT)
		render_putpix(r, ray->x, y, 0x0000ff00);
	if (h > SCREEN_HEIGHT)
		y_block = (h - SCREEN_HEIGHT) / 2;
	else
		y_block = 0;
	while (y < limits.y && y++ < WIN_HEIGHT)
	{
		y_text = (y_block++ * text->height) / h;		
		render_putpix(r, ray->x, y, text->pixs[y_text * text->width + x_text]);
	}
	while (y++ < WIN_HEIGHT)
		render_putpix(r, ray->x, y, 0x0);
}