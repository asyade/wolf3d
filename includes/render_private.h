#ifndef RENDER_PRIVATE_H
# define RENDER_PRIVATE_H

# include "libft.h"
# include "vect.h"
# include "render.h"

typedef struct			s_render
{
	unsigned int		stat;
	SDL_Event			event;	
	SDL_Window			*sdl;
	SDL_Renderer		*rend;
	SDL_Texture			*text;
	void				*win;
	void				*attr;
	t_renderCallBack	cb;
	unsigned int		*data;
	t_renderEvent		hook;
	void				*hookAttr;
}						t_render;

#endif