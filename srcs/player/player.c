#include "player.h"
#include "player_private.h"

t_player	*player_init(t_render *r, t_cam *c, t_map *m)
{
	t_player	*p;

	p = ft_salloc(sizeof(t_player));;
	p->cam = c;
	p->render = r;
	p->map = m;
	p->key = (char *)SDL_GetKeyboardState(NULL);
	return (p);
}

int			player_motion_mouse(t_player *p)
{
	static int		last_x = 0;
	double			x_diff;
	int				x;
	int				y;

	x = 0;
	y = 0;
	SDL_GetMouseState(&x, &y);
	x_diff = last_x - x;
	if (x_diff != 0)
	{
		x_diff /= 500;
		last_x = x;
		cam_applyAngle(p->cam, cos(x_diff), sin(x_diff));
	}
	else
		return (0);
	if (x < SCREEN_CX - 10 || x > SCREEN_CX + 10 || y < SCREEN_CY - 10 || y > SCREEN_CY + 10)
	{
		last_x = SCREEN_CX;
		SDL_WarpMouseInWindow(NULL, SCREEN_CX, SCREEN_CY);
	}
	return 1;
}

void		player_motion(t_player *p)
{
	int		re;

	re = 0;
	re = player_motion_mouse(p);
	if (p->key[PK_LEFT])
	{
		re = 1;
		cam_applyAngle(p->cam, cos(-CAM_SIDE_DELTA), sin(-CAM_SIDE_DELTA));
		player_apply_vel(p, -.2);
		cam_applyAngle(p->cam, cos(CAM_SIDE_DELTA), sin(CAM_SIDE_DELTA));
	}
	if (p->key[PK_RIGHT])
	{
		re = 1;
		cam_applyAngle(p->cam, cos(CAM_SIDE_DELTA), sin(CAM_SIDE_DELTA));
		player_apply_vel(p, -.2);
		cam_applyAngle(p->cam, cos(-CAM_SIDE_DELTA), sin(-CAM_SIDE_DELTA));
	}
	if (p->key[PK_UP])
	{
		re = 1;
		player_apply_vel(p, .2);
	}
	if (p->key[PK_DOWN])
	{
		re = 1;
		player_apply_vel(p, -.2);
	}
	if (re)
		render_setflag(p->render, ST_REFRESH);
}

int			player_update(t_player *p, SDL_Event *event)
{
	(void)event;
	if (p->key[SDLK_ESCAPE])
		exit(1);//todo faire sa bien
	player_motion(p);
	return (1);
}

void		player_free(t_player *player)
{
	free(player);
}