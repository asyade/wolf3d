#include "texture.h"
#include "texture_private.h"

static t_texture	*text_cancel(t_texture *text)
{
	free(text->data);
	free(text);
	return (NULL);
}

t_texture	*text_convert(t_texture *t)
{
	unsigned int	*tmp;
	int				i;
	int				j;

	tmp = ft_salloc(t->width * t->height * sizeof(unsigned int));
	i = 0;
	j = 0;
	while (j < t->width * t->height)
	{
		tmp[j++] = t->img[i + 2] << 28 | (t->img[i + 1] << 16) | (t->img[i] << 8);
		i += 3;
	}
	t->pixs = tmp;
	return (t);
}

t_texture	*text_parse(t_texture *t)
{
	char	*p;
	char	*f;

	p = ((char *)t->data) + 3; //a voire
	if (!(f = ft_strchr(p, ' ')))
		return (text_cancel(t));
	if (f - p > 12)
		return (text_cancel(t));
	t->width = ft_atoi(p);
	p = f + 1;
	if (!(f = ft_strchr(p, '\n')))
		return (text_cancel(t));
	t->height = ft_atoi(p);
	f += 5;
	t->img = (unsigned char *)f;
	if ((t->height < PPB || t->width < PPB) || (t->height * t->width * 3 > (int)(t->size - (int)((long int)f - (long int)t->data))))
		return (text_cancel(t));
	return (text_convert(t));
}

t_texture	*text_read(char *path)
{
	int			fd;
	char		head[3];
	t_texture	*text;
	size_t		bfs;
	size_t		rd;

	if ((fd = open(path, O_RDONLY)) <= 0)
		return (NULL);
	read(fd, head, 3);
	if (!ft_strnequ("P6\n", head, 3))
		return (NULL);
	text = ft_salloc(sizeof(t_texture));
	bfs = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	rd = 0;
	text->size = bfs;
	text->data = ft_salloc(bfs + 1);
	text->data[bfs - 1] = '\0';
	while ((rd += read(fd, text->data + rd, bfs)) < bfs)
		;
	return (bfs > 64 ? text_parse(text) : text_cancel(text));
}