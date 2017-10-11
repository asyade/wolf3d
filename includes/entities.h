#ifndef ENTITIES_H
# define ENTITIES_H

# include "vect.h"
# include "register.h"
# include "libft.h"
# include "cam.h"
# include "render.h"
# include <SDL2/SDL.h>

typedef struct				s_ent_abstracte
{
	t_vec2					pos;
	t_vec2					rel_pos;
	void					(*ctor)(struct s_ent_abstracte *o, double, double);
	void					(*dtor)(struct s_ent_abstracte *o);
	void					(*refresh)(struct s_ent_abstracte *o);
	struct s_ent_abstracte	*next;
}							t_ent_abstracte;

typedef struct				s_ent_manager
{
	t_ent_abstracte			*entities;
	SDL_Thread				*thread;
}							t_ent_manager;

t_ent_manager				*ent_newenv(void);
void						ent_draw(t_render *r, t_ent_manager *m, t_cam *c);
void						ent_refresh(t_ent_manager *manager);
void						ent_instance_register(t_ent_manager *m, t_ent_abstracte *t);

#endif