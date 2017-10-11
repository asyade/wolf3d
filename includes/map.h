#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <unistd.h>
# include "vect.h"
# include "register.h"

typedef struct  s_map_file  t_map_file;

# define		T_COUNT		1
# define		T_GROUND	(0)
# define		T_WALL		(1<<0)

typedef struct  s_obj
{
    int			type;
}				t_obj;

typedef struct	s_map
{
	t_map_file	*file;
	t_size		size;
	int			**data;
}				t_map;

int			mapCheckCollid(t_map *map, int x, int y);
void		mapFileFree(t_map_file *file);
t_map_file	*mapFileRead(char *path);
t_map		*mapParse(t_map_file *file);

#endif