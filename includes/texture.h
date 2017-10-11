#ifndef TEXTURE_H
# define TEXTURE_H

# include "render.h"
# include "register.h"

typedef struct s_texture	t_texture;

void	text_fillLine(t_render *r, t_ray *ray, int y);
t_texture	*text_read(char *path);

t_texture	**texture_set(void);
void		text_load(void);

#endif