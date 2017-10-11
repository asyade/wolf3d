#ifndef PLAYER_PRIVATE_H
# define PLAYER_PRIVATE_H

# include <SDL2/SDL.h>

# define KM_KEYS	1
# define KM_MOUSE	2

# define CAM_SIDE_DELTA	1.6

# define COLLID_MAX_FRICTION	10

# define PK_LEFT 4
# define PK_UP 26
# define PK_RIGHT 7
# define PK_DOWN 22

typedef struct	s_player
{
	t_render	*render;
	t_cam		*cam;
	t_map		*map;
	char		*key;	
}				t_player;

#endif