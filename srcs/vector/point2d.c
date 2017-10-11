#include "vect.h"

t_point3		*point2d_quadrant(t_point3 *quadrant, t_vec2 *dir)
{
	quadrant->x = (dir->x < 0) ? -1 : 1;
	quadrant->y = (dir->y < 0) ? -1 : 1;
	return (quadrant);
}