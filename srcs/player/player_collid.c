#include "player.h"
#include "player_private.h"

int		player_apply_vel(t_player *p, double vel)
{
	t_vec2	npos;
	double	angle;
	int		n;
	double		x, y;
	double		tmp;

	tmp = p->cam->dir.x;
	x = p->cam->dir.x * cos(0) + p->cam->dir.y * sin(0);
	y = tmp * sin(0) - p->cam->dir.y * -cos(0);
	npos.x = (vel * x) + p->cam->pos.x;
	npos.y = (vel * y) + p->cam->pos.y;	
	n = 6;
	angle = 0;
	while (n--)
	{
		if (!(mapCheckCollid(p->map, (int)npos.x, (int)p->cam->pos.y) ||
			mapCheckCollid(p->map, (int)p->cam->pos.x, (int)npos.y) ||
			mapCheckCollid(p->map, (int)npos.x, (int)npos.y)))
		{
			p->cam->pos.x += vel * x;
			p->cam->pos.y += vel * y;
			return (1);
		}
		angle += 0.1;
		tmp = p->cam->dir.x;	
		if (n % 2)
		{
			x = p->cam->dir.x * cos(angle) + p->cam->dir.y * sin(angle);
			y = tmp * sin(angle) - p->cam->dir.y * -cos(angle);
			npos.x = (vel * x) + p->cam->pos.x;
			npos.y = (vel * y) + p->cam->pos.y;	
		}
		else
		{
			x = p->cam->dir.x * cos(-angle) + p->cam->dir.y * sin(-angle);
			y = tmp * sin(-angle) - p->cam->dir.y * -cos(-angle);
			npos.x = (vel * x) + p->cam->pos.x;
			npos.y = (vel * y) + p->cam->pos.y;
		}
	}
	return (0);
}