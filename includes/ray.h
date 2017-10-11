#ifndef RAY_H
# define RAY_H

# include "map.h"
# include "render.h"
# include "cam.h"

# define RAY_SIDE_POS(d, a, b) (d < 0) ? (a - b) : (1 + (b - a))

void	ray_traceall(t_render *r, t_cam *cam, t_map *map);

#endif
