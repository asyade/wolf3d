#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "map.h"
# include "render.h"
# include "cam.h"
# include "ray.h"
# include "player.h"
# include "entities.h"

# include "ent_powerup.h"

typedef struct	s_wolf
{
	t_map			*map;
	t_render		*render;
	t_cam			*cam;
	t_player		*player;
	t_ent_manager	*ent;
}				t_wolf;

#endif