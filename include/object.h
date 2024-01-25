/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:29:07 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/25 13:57:00 by rugrigor         ###   ########.fr       */
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
	float		r;
	t_vector	*center;
}			t_sphere;

typedef struct s_scene
{
	t_camera	*cams;
	t_sphere	*spheres;
	float		width;
	float		height;
}			t_scene;

typedef struct s_plane
{
	float width;
	float height;
	float pixel_x;
	float pixel_y;
}				t_plane;

t_scene		*new_scene(t_camera *cam, t_sphere *sphere);
t_sphere	*new_sphere(t_vector *center, float diameter);
t_plane		*get_vplane(float width, float height, float fov);
t_camera	*new_cam(t_vector *center, t_vector *direction, float fov);

#endif
