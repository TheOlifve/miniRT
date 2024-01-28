/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:29:07 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/28 16:08:06 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "minirt.h"

typedef struct s_camera
{
	float		fov;
	t_vector	*center;
	t_vector	*direction;
}			t_camera;

typedef struct s_sphere
{
	int			color;
	float		r;
	t_vector	*center;
}			t_sphere;

typedef struct s_plane
{
	int			color;
	t_vector	*point;
	t_vector	*norm_vec;
}			t_plane;

typedef struct s_cylinder
{
	int			color;
	float		r;
	float		h;
	t_vector	*center;
	t_vector	*norm_vec;
}			t_cylinder;

typedef struct s_scene
{
	t_camera	*cams;
	t_sphere	*spheres;
	float		width;
	float		height;
}			t_scene;

typedef struct s_vplane
{
	float		x_pixel;
	float		y_pixel;
	float		width;
	float		height;
}			t_vplane;

t_scene		*new_scene(t_camera *cam, t_sphere *sphere);
t_vplane	*get_vplane(float width, float height, float fov);
t_sphere	*new_sphere(t_vector *center, float diameter, char **color);
t_camera	*new_cam(t_vector *center, t_vector *direction, float fov);
t_cylinder	*new_cylinder(t_vector *cent, t_vector *nvec, char **dh, char **clr);

#endif