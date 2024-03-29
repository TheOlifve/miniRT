/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/28 15:35:31 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
				color = scene->spheres->color;
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
