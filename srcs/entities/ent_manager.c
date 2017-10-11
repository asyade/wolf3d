#include "entities.h"

t_ent_manager	*ent_newenv(void)
{
	t_ent_manager	*manager;
	manager = ft_memalloc(sizeof(t_ent_manager));
	return (manager);
}

int			ent_loop(void *attr)
{
	t_ent_manager	*man;
	t_ent_abstracte	*tmp;

	man = (t_ent_manager *)attr;
	tmp = man->entities;
	while (tmp)
	{
		(tmp->refresh)(tmp);
		tmp = tmp->next;
	}
	return (0);
}

void			ent_draw(t_render *r, t_ent_manager *m, t_cam *c)
{
	t_ent_abstracte	*t;

	(void)r;
	t = m->entities;
	while (t)
	{
		t->rel_pos.x = t->pos.x - c->pos.x;
		t->rel_pos.y = t->pos.y - c->pos.y;
		t = t->next;
	}
}

void			ent_instance_register(t_ent_manager *m, t_ent_abstracte *t)
{
	t->next = m->entities;
	m->entities = t;
}

void			ent_refresh(t_ent_manager *manager)
{
	manager->thread = SDL_CreateThread(&ent_loop, "Entities thread", manager);
}