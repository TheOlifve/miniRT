/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/28 14:09:46 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vplane	*get_vplane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		err_exit(1);
	aspect_ratio = width / height;
	vplane->width = 2 * tan((fov / 2) * (M_PI / 180));
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}

float	sphere_touch(t_camera *cam, t_vector *ray, t_sphere *spheres, float disk)
{
	float		b;
	float		c;
	float		distance1;
	t_vector	*cam_sphere;
	
	distance1 = 0;
	cam_sphere = vec_sub(cam->center, spheres->center);
	c = vec_dot_product(cam_sphere, cam_sphere) - (spheres->r * spheres->r);
	b = 2 * (vec_dot_product(cam_sphere, ray));
	disk = (b * b) - (4 * c);
	free(cam_sphere);
	if (disk < 0)
		return (0);
	distance1 = (b * -1 + sqrt(disk)) / 2;
	if (distance1 > 0)
		return (1);
	return (0);
}

int	ray_trace(t_mrt *mrt, t_scene *scene)
{
	int			color;
	int			mlx_x;
	int			mlx_y;
	float		x;
	float		y;
	t_vector	*ray;
	t_vplane	*vplane;

	vplane =  get_vplane(scene->width, scene->height, scene->cams->fov);
	y = scene->height / 2;
	mlx_y = 0;
	while (y >= (-1) * (scene->height / 2))
	{
		mlx_x = 0;
		x = (scene->width / 2) * (-1);
		while (x <= scene->width / 2)
		{
			ray = new_vec(x * vplane->x_pixel, y * vplane->y_pixel, 1);
			vec_norm(ray);
			if (sphere_touch(scene->cams, ray, scene->spheres, 0))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mrt->mlx, mrt->mlx_win, mlx_x, mlx_y, color);
			x++;
			mlx_x++;
		}
		mlx_y++;
		y--;
	}
	return (0);
}