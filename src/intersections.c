/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/02/05 11:24:23 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	sphere_touch(t_camera *cam, t_vector *ray, t_sphere *spheres)
{
	float		b;
	float		c;
	float		disc;
	float		root;
	t_vector	*cam_sphere;

	root = 0;
	disc = 0;
	cam_sphere = vec_sub(cam->center, spheres->center);
	c = vec_dot(cam_sphere, cam_sphere) - (spheres->r * spheres->r);
	b = 2 * (vec_dot(cam_sphere, ray));
	disc = (b * b) - (4 * c);
	free(cam_sphere);
	if (disc < 0)
		return (0);
	root = (b * -1 + sqrt(disc)) / 2;
	if (root > 0)
		return (1);
	return (0);
}
