/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:29:07 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/22 14:10:06 by hrahovha         ###   ########.fr       */
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

t_scene		*new_scene(t_camera *cam, t_sphere *sphere);
t_sphere	*new_sphere(t_vector *center, float diameter);
t_camera	*new_cam(t_vector *center, t_vector *direction, float fov);

#endif
