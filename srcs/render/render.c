#include "render.h"
#include "render_private.h"

t_render		*render_init()
{
	t_render	*ret;

	ret = ft_salloc(sizeof(t_render));
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putendl("Can't init sdl !");
		exit(1);
	}
	ret->win = SDL_CreateWindow("Wolf3d", 0, 0, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	ret->rend = SDL_CreateRenderer(ret->win, -1, SDL_RENDERER_ACCELERATED);
	ret->text = SDL_CreateTexture(ret->rend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WIN_WIDTH, WIN_HEIGHT);
	ret->data = ft_salloc(sizeof(int) * (WIN_WIDTH * WIN_HEIGHT));
	ret->stat = ST_REFRESH;
	return (ret);
}

void			render_done(t_render *render)
{
	SDL_DestroyTexture(render->text);
	SDL_DestroyRenderer(render->rend);
	SDL_DestroyWindow(render->win);
	free(render->data);
	SDL_Quit();
	exit(1);
}

void	render_present(t_render *r)
{
	SDL_UpdateTexture(r->text, NULL, r->data, WIN_WIDTH * sizeof(int));
	SDL_RenderCopy(r->rend, r->text, NULL, NULL);
	SDL_RenderPresent(r->rend);
}

void	render_setflag(t_render *r, unsigned int flag)
{
	r->stat |= flag;
}

static int	render_int_loop(t_render *r)
{
	if (!(r->cb)(r->attr))
		render_done(r);
	render_present(r);
	r->stat = 0;
	return (1);
}

/*
** Un peut de ménage a faire ici
*/

void			render_loop(t_render *r, t_renderCallBack cb, void *attr)
{
	r->cb = cb;
	r->attr = attr;
	while (1)
	{
		SDL_PollEvent(&r->event);
		if (r->hook)
			(r->hook)(&r->event, r->attr);
		if (r->stat & ST_REFRESH)
		{
			r->stat &= ~ST_REFRESH;
			render_int_loop(r);
		}
	}
}

void			render_hook(t_render *r, t_renderEvent cb, void *attr)
{
	r->hookAttr = attr;
	r->hook = cb;
}

void			render_clear(t_render *r)
{
	ft_bzero(r->data, TEX_HEIGHT * TEX_WIDTH * 4);	
}

void			render_putpix2(t_render *r, int i, int col)
{
	if (i >= 0 && i < TEX_SIZE)
		r->data[i] = col;
}

void			render_putpix(t_render *r, int x, int y, int col)
{
	if (x < WIN_WIDTH && y < WIN_HEIGHT && x >= 0 && y >= 0)
		r->data[x + (y * TEX_WIDTH)] = col;
}