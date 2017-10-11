#ifndef RENDER_H
# define RENDER_H

# include "register.h"
# include "libft.h"
# include <SDL2/SDL.h>

# define	ST_NONE		0
# define	ST_REFRESH	(1)
# define	ST_QUIT		(1<<1)

typedef struct	s_render t_render;

typedef int		(*t_renderCallBack)(void *attr);
typedef int		(*t_renderEvent)(SDL_Event *, void *);

void			render_present(t_render *r);
t_render		*render_init();
void			render_done(t_render *render);
void			render_loop(t_render *r, t_renderCallBack cb, void *attr);
void			render_putpix2(t_render *r, int i, int col);
void			render_clear(t_render *r);
void			render_putpix(t_render *r, int x, int y, int col);
void			render_hook(t_render *r, t_renderEvent cb, void *attr);
void			render_setflag(t_render *r, unsigned int flag);

#endif