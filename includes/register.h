#ifndef REGISTER_H
# define REGISTER_H

# include "vect.h"

/*
** Map settings
*/

# define 	PPB				64

# define	PI 3.14159265358979323846
# define	FROM_ANGLE(angle)(angle * PI / 180.0)
# define	SLOPE(a) ((sin(a) / cos(a)))
# define	ROUNDED_POS(p, d) ((d > 1 ? floor(p) : round(p)))

/*
**	Texture settings
*/

# define	SHADOW_LEVEL	1
# define	SHADOW_START	1

# define	TEXT_COUNT		2
# define	TEXT_DEFAULT	0

# define	TEXT_PATH_1		"text1.ppm"
# define	TEXT_PATH_2		"text2.ppm"

/*
**	Collid directions
*/

# define	F_LTR	0x01
# define	F_RTL	0x02
# define	F_TTB	0x04
# define	F_BTT	0x08

/*
** Screen settings
*/

# define TEX_WIDTH	1900
# define TEX_HEIGHT	1024
# define WIN_WIDTH	TEX_WIDTH
# define WIN_HEIGHT	TEX_HEIGHT
# define TEX_SIZE	(TEX_WIDTH * TEX_HEIGHT)

# define SCREEN_WIDTH		TEX_WIDTH
# define SCREEN_HEIGHT		TEX_HEIGHT
# define SCREEN_CX			(SCREEN_WIDTH / 2)
# define SCREEN_CY			(SCREEN_HEIGHT / 2)

/*
**	Camera settings
*/

# define CAM_X				SCREEN_CX
# define CAM_Y				SCREEN_CY
# define RAY_INT			(60.00 / TEX_WIDTH) //(CAM_FOV / 640)
# define RAY_LEN			400
# define CAM_HEIGHT			64
# define CAM_FOV			60
# define CAM_DEL			(CAM_FOV / 2)
# define WALL_SIZE(dst)((dst * 16) / CAM_HEIGHT)
# define POINTX_DIR(angle, len)(len * cos(FROM_ANGLE(angle)))
# define POINTY_DIR(angle, len)(len * sin(FROM_ANGLE(angle)))

/*
** Public data def
*/

typedef struct	t_ray
{
	double		cam_x;
	int			screen_dist;
	t_point		rounded;
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		delta;
	t_vec2		side;
	int			rounded_from;
	double		pos_from;
	double		dir_from;
	double		pos_oppo;
	double		dir_oppo;
	t_point		origin;
	t_point3	quadrant;
	double		hitX;
	int			from;
	int			x;
	double		dist;
	int			obj;
}				t_ray;

#endif