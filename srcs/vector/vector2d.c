#include "vect.h"

void		vect2d_from_angle(float angle, t_vec2 *vec)
{
	vec->x = cos(angle);
	vec->y = sin(angle);
}

void		vec2d_from_point(float x, float y, t_vec2 *vec)
{
	vec->x = x;
	vec->y = y;
}

double		vec2d_angle(t_vec2 *vec)
{
	return (atan2(vec->x, vec->y));
}
