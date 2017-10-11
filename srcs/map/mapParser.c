#include "map.h"
#include "map_private.h"

static void	mapDataAlloc(t_map *map)
{
	int		y;
	
	map->data = ft_salloc(sizeof(int *) * map->size.h);
	y = -1;
	while (++y < map->size.h)
	{
		map->data[y] = ft_salloc(sizeof(int *) * map->size.w);
	}
}

static int	get_flag(char c)
{
	c = c - 'a';
	return (c);
}

t_map		*mapParse(t_map_file *file)
{
	t_map	*ret;
	t_point	p;

	ret = ft_salloc(sizeof(t_map));
	ret->file = file;
	ret->size = file->bfsize;
	mapDataAlloc(ret);
	p.y = -1;
	while (++p.y < ret->size.h)
	{
		p.x = -1;
		while (++p.x < ret->size.w)
		{
			*(ret->data[p.y] + p.x) = get_flag(ret->file->buffer[p.y][p.x]);
		}
	}
	return (ret);
}