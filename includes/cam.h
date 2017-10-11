#ifndef CAM_H
# define CAM_H

# include "map.h"
# include "register.h"
# include "texture.h"
# include "render.h"
# include "cam.h"

//typedef struct s_cam	t_cam;


typedef struct	s_cam
{
	t_vec2		pos;
	t_vec2		screen;	
	int			screen_dist;
	t_vec2		dir;
	int			z;
	int			fov[3];
	double		lineDist[WIN_WIDTH];
}				t_cam;

t_cam		*cam_init(double x, double y);
t_vec2		*cam_pos(t_cam *cam);
void		cam_applyVel(t_cam *cam, double vel);
t_vec2		*cam_screen_position(t_cam *cam);
void		cam_applyAngle(t_cam *cam, double coss, double sins);

#endif