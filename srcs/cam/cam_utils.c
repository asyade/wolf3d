#include "cam.h"
#include "cam_private.h"

float		get_dist(int x1, int y1, int x2, int y2)//a voir si c'est vraiment utile d'utiliser les float
{
    int		x;
    int		y;
    float	dist;

	x = x1 - x2;
	y = y1 - y2;
    dist = pow(x, 2) + pow(y, 2);
	return (sqrt(dist));
}

void		point_add_dir(float dir, float vel, t_vec2 *p)
{
	p->x += (vel * cos(dir * PI / 180.0 ));
	p->y += (vel * sin(dir * PI / 180.0 ));
}

t_vec2		*cam_screen_position(t_cam *cam)
{
	return (&cam->screen);
}
