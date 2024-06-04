/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:29:07 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/03 15:53:06 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "minirt.h"

typedef struct s_ambient
{
	int		*color;
	double	intence;
}			t_ambient;

typedef struct s_light
{
	int				*color;
	double			intence;
	t_vector		*center;
}			t_light;

typedef struct s_camera
{
	double		fov;
	t_vector	*center;
	t_vector	*direction;
}			t_camera;

typedef struct s_sphere
{
	int			*color;
	double		r;
	t_vector	*center;
}			t_sphere;

typedef struct s_plane
{
	int			*color;
	t_vector	*point;
	t_vector	*norm_vec;
}			t_plane;

typedef struct s_cylinder
{
	int			*color;
	double		r;
	double		h;
	int			head;
	t_vector	*center;
	t_vector	*norm_vec;
}			t_cylinder;

typedef struct s_vplane
{
	double		x_pixel;
	double		y_pixel;
	double		width;
	double		height;
}			t_vplane;

typedef struct s_diff
{
	int				tipe;
	t_sphere		*spheres;
	t_plane			*planes;
	t_cylinder		*cylinders;
	double			t;
	double			lt;
	struct s_diff	*next;
	struct s_diff	*prev;
}			t_diff;

typedef struct s_scene
{
	t_diff		*diff;
	t_diff		*obj;
	t_light		*light;
	t_plane		**planes;
	t_camera	*cam;
	t_vplane	*vplane;
	t_sphere	**spheres;
	t_cylinder	**cylinders;
	t_ambient	*ambient;
	int			tipe;
	double		x;
	double		lx;
	int			*amb;
	double		width;
	double		height;
}			t_scene;

int			*new_amb(double intence, char *color);
t_plane		*new_plane(char *info);
t_vplane	*get_vplane(double width, double height, double fov);
t_sphere	*new_sphere(char *info);
t_camera	*new_cam(char **element);
t_cylinder	*new_cylinder(char *info);

#endif