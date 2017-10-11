#ifndef VECT_H
# define VECT_H

# include <math.h>

typedef float	t_dec;

typedef struct  s_vec1
{
	t_dec		x;
	t_dec		y;
}				t_vec2;

typedef struct  s_vec3
{
	
	t_dec		x;
	t_dec		y;
	t_dec		z;
}				t_vec3;

typedef struct  s_vec4
{
	t_dec		x;
	t_dec		y;
	t_dec		z;
	t_dec		n;
}				t_vec4;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_point3
{
	int			x;
	int			y;
	int			z;
}				t_point3;

typedef struct  s_size
{
	int			w;
	int			h;
}				t_size;

void		vect2d_from_angle(float angle, t_vec2 *vec);
void		vec2d_from_point(float x, float y, t_vec2 *vec);
double		vec2d_angle(t_vec2 *vec);

t_point3		*point2d_quadrant(t_point3 *quadrant, t_vec2 *dir);

#endif