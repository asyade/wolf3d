#ifndef PLAYER_H
# define PLAYER_H

# include "cam.h"
# include "render.h"
# include "map.h"

typedef struct s_player	t_player;

int			player_apply_vel(t_player *p, double vel);
t_player	*player_init(t_render *r, t_cam *c, t_map *m);
void		player_motion(t_player *p);
int			player_update(t_player *p, SDL_Event *event);
void		player_free(t_player *player);

#endif