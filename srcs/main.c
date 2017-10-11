#include "wolf.h"

int		refresh(void *av)
{
	t_wolf	*w;

	w = (t_wolf *)av;

	ray_traceall(w->render, w->cam, w->map);
	return (1);
}

int		key_pressed(SDL_Event *event, void *av)
{
	t_wolf	*w;

	w = (t_wolf *)av;
	if (event->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		render_done(w->render);
	else
		player_update(w->player, event);
	return (1);
}

int		main(int ac, char **av)
{

	t_map_file	*file;
	t_wolf		env;

	if (ac != 2)
	{
		ft_putendl("Invalide arguments !");
		return (1);
	}
	if (!(file = mapFileRead(av[1])))
	{
		ft_putendl("Invalide map !");
		return (1);
	}
	text_load();
	env.map = mapParse(file);
	env.render = render_init();
	env.cam = cam_init(-1, -1);
	env.player = player_init(env.render, env.cam, env.map);
	render_hook(env.render, key_pressed, &env);
	render_loop(env.render, &refresh, &env);
}