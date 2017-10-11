#ifndef TEXTURE_PRIVATE_H
# define TEXTURE_PRIVATE_H

# include <fcntl.h>
# include <stdio.h>

typedef struct		s_texture
{
	int				width;
	int				height;
	unsigned char	*data;
	unsigned char	*img;
	unsigned int	*pixs;
	size_t			size;
}					t_texture;

#endif