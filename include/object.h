/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:29:07 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/24 16:08:17 by rugrigor         ###   ########.fr       */
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
	float		hight;
}			t_scene;

typedef struct s_plane
{
	float width;
	float height;
}				t_plane;

t_scene		*new_scene(t_camera *cam, t_sphere *sphere);
t_sphere	*new_sphere(t_vector *center, float diameter);
t_camera	*new_cam(t_vector *center, t_vector *direction, float fov);

#endif
