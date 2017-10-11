#ifndef ENT_POWERUP_H
# define ENT_POWERUP_H

# include "entities.h"

typedef struct		s_ent_powerup
{
	t_vec2			pos;
	t_vec2			rel_pos;
	void			(*ctor)(t_ent_abstracte *o, double, double);
	void			(*dtor)(t_ent_abstracte *o);
	void			(*refresh)(t_ent_abstracte *o);
	t_ent_abstracte	*next;
}					t_ent_powerup;

t_ent_abstracte		*ent_get_powerup();
void				ent_powerup_refresh(t_ent_abstracte *ent);
void				ent_powerup_ctor(t_ent_abstracte *ent, double x, double y);
void				ent_powerup_dtor(t_ent_abstracte *ptr);

#endif