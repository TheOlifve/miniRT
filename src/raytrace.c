/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/27 21:04:36 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	printf("%f\n",distance1);
	if (distance1 > 0)
		return (1);
	return (0);
}

t_vplane	*get_vplane(float width, float hight, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	(void)fov;
	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		err_exit(1);
	aspect_ratio = width / hight;
	vplane->width = tan((fov / 2) * (M_PI / 180));
	vplane->width *= 2;
	vplane->hight = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->hight / hight;
	return (vplane);
}

int	ray_tracing(t_mrt *mrt, t_scene *scene)
{
	// int			mlx_x;
	// int			mlx_y;
	int			color;
	float		x;
	float		y;
	t_vector	*ray;
	t_vplane	*vplane;

	vplane =  get_vplane(scene->width, scene->hight, scene->cams->fov);
	// mlx_x = 0;
	// mlx_y = 0;
	y = 0;
	printf("%f - %f\n",vplane->x_pixel,vplane->y_pixel);
	while (y <= scene->hight)
	{
		x = 0;
		while (x <= scene->width)
		{
			ray = new_vec(x * vplane->x_pixel, y * vplane->y_pixel, 1);
			if (sphere_touch(scene->cams, ray, scene->spheres, 0))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mrt->mlx, mrt->mlx_win, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}