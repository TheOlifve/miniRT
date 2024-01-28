/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/28 14:43:37 by hrahovha         ###   ########.fr       */
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
	c = vec_dot_product(cam_sphere, cam_sphere) - (spheres->r * spheres->r);
	b = 2 * (vec_dot_product(cam_sphere, ray));
	disc = (b * b) - (4 * c);
	free(cam_sphere);
	if (disc < 0)
		return (0);
	root = (b * -1 + sqrt(disc)) / 2;
	if (root > 0)
		return (1);
	return (0);
}

int	ray_trace(t_mrt *mrt, t_scene *scene)
{
	int			color;
	float		x;
	float		y;
	t_vector	*ray;
	t_vplane	*vplane;

	vplane = get_vplane(scene->width, scene->height, scene->cams->fov);
	y = scene->height / 2;
	mrt->y = 0;
	while (y >= (-1) * (scene->height / 2))
	{
		mrt->x = 0;
		x = (scene->width / 2) * (-1);
		while (x <= scene->width / 2)
		{
			ray = new_vec(x * vplane->x_pixel, y * vplane->y_pixel, 1);
			vec_norm(ray);
			if (sphere_touch(scene->cams, ray, scene->spheres))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mrt->mlx, mrt->mlx_win, mrt->x, mrt->y, color);
			x++;
			mrt->x++;
		}
		mrt->y++;
		y--;
	}
	return (0);
}
