#include "map.h"
#include "map_private.h"

static int	mapFileExtende(size_t size, t_map_file *f)
{
	char	**tmp;

	tmp = ft_salloc(size * sizeof(char *));
	ft_memcpy(tmp, f->buffer, (size / 2) * sizeof(char *));
	free(f->buffer);
	f->buffer = tmp;
	return (1);
}

t_map_file	*mapFileRead(char *path)
{
	t_map_file	*ret;
	char		*line;
	int			len;
	int			size;

	ret = ft_salloc(sizeof(t_map_file));
	if ((ret->fd = open(path, O_RDONLY)) <= 0)
		return (NULL);
	ret->bfsize.h = 0;
	ret->bfsize.w = 0;
	line = NULL;
	len = 0;
	size = 1024;
	ret->buffer = ft_salloc(sizeof(char *) * size);
	while (get_next_line(ret->fd, &line) > 0)
	{
		len = ft_strlen(line);
		
		if (ret->bfsize.w == 0)
			ret->bfsize.w = len;
		if ((ret->bfsize.h >= size - 1 && !mapFileExtende(size *= 2, ret)) ||
			ret->bfsize.w != len)
		{
			mapFileFree(ret);
			return (NULL);
		}
		ret->buffer[ret->bfsize.h++] = line;
	}
	close(ret->fd);
	return (ret);
}

void		mapFileFree(t_map_file *file)
{
	(void)file;
}
