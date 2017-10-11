#ifndef MAP_PRIVATE_H
# define MAP_PRIVATE_H

# include "libft.h"
# include "vect.h"

typedef struct	s_map_file
{
    char		**buffer;
	t_size		bfsize;
	char		*path;
	int			fd;
}				t_map_file;

#endif