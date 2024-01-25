/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/25 15:47:13 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	sphere_touch(t_camera *cam, t_vector *ray, t_sphere *spheres, float disk)
{
	float		b;
	float		c;
	float		distance1;
	float		distance2;
	t_vector	*cam_sphere;
	
	distance1 = 0;
	distance2 = 0;
	cam_sphere = vec_sub(cam->center, spheres->center);
	c = vec_scal(cam_sphere, cam_sphere) - (spheres->r * spheres->r);
	b = 2 * (vec_scal(cam_sphere, ray));
	disk = (b * b) - (4 * c);
	free(cam_sphere);
	if (disk < 0)
		return (0);
	distance1 = (b * -1 + sqrt(disk)) / 2;
	distance2 = (b * -1 - sqrt(disk)) / 2;
	if (distance1 > 0)
		return (1);
	return (0);
}

void	ray_trace(t_mrt *mrt, t_scene *scene, int mlx_x, int mlx_y)
{
	float		ang_x;
	float		ang_y;
	int			color;
	t_vector	*ray;
	t_plane		*plane;

	plane = get_vplane(scene->width, scene->height, scene->cams->fov);
	ang_y = scene->height;
	while (ang_y >= 0)
	{
		ang_x = 0;
		mlx_x = 0;
		while (ang_x <= scene->width)
		{
			ray = new_vec(ang_x * plane->pixel_x, ang_y * plane->pixel_y, 1);
			vec_norm(ray);
			if (sphere_touch(scene->cams, ray, scene->spheres, 0))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mrt->mlx, mrt->mlx_win, mlx_x, mlx_y, color);
			free(ray);
			ang_x++;
			mlx_x++;
		}
		ang_y--;
		mlx_y++;
	}
}
