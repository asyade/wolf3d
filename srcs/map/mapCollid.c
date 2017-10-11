#include "map.h"
#include "map_private.h"

int			mapCheckCollid(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->size.w || y < 0 || y >= map->size.h)
		return (0);
	return (map->data[y][x]);
}