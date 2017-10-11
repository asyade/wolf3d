#include "ent_powerup.h"

void			ent_powerup_refresh(t_ent_abstracte *ent)
{
	(void)ent;
}

void			ent_powerup_ctor(t_ent_abstracte *ent, double x, double y)
{
	ent->pos.x = x;
	ent->pos.y = y;
}

t_ent_abstracte	*ent_get_powerup()
{
	t_ent_powerup	*ret;

	ret = ft_memalloc(sizeof(t_ent_powerup));
	ret->ctor = &ent_powerup_ctor;
	ret->dtor = &ent_powerup_dtor;
	ret->refresh = &ent_powerup_refresh;
	return (t_ent_abstracte *)ret;
}

void			ent_powerup_dtor(t_ent_abstracte *ptr)
{
	free(ptr);
}