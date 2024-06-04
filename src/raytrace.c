/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/04 16:58:15 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	help_func(t_mrt *mrt, t_scene *scene, t_vector *cam, t_diff *diff)
{
	double		n;
	t_sphere	*sphere;

	if (diff->tipe == 1)
	{
		sphere = diff->spheres;
		n = (cam->x - sphere->center->x) * (cam->x - sphere->center->x)
			+ (cam->y - sphere->center->y) * (cam->y - sphere->center->y)
			+ (cam->x - sphere->center->z) * (cam->x - sphere->center->z);
		if (n < (sphere->r * sphere->r))
		{
			scene->tipe = -1;
			mrt->color = rgbtoi(scene->diff->spheres->color);
			return (1);
		}
	}
	else if (diff->tipe == 2 && diff->t)
		mrt->color = rgbtoi(scene->diff->planes->color);
	else if (diff->tipe == 3)
	{
		mrt->color = rgbtoi(scene->diff->cylinders->color);
	}
	return (0);
}

void	get_help(t_scene *scene)
{
	if ((scene->x == 0 && scene->diff->t)
		|| (scene->x && scene->diff->t && scene->diff->t < scene->x))
	{
		scene->obj = scene->diff;
		scene->x = scene->diff->t;
	}
}

void	get_object(t_mrt *mrt, t_scene *scene, t_vector *ray)
{
	while (scene->diff)
	{
		scene->diff->t = 0;
		if (scene->diff->tipe == 1)
			scene->diff->t = sphere_touch(scene->cam->center, \
				ray, scene->diff->spheres, NULL);
		else if (scene->diff->tipe == 2)
			scene->diff->t = planes_touch(scene->cam->center, \
				ray, scene->diff->planes);
		else if (scene->diff->tipe == 3)
			scene->diff->t = cylinder_touch(scene->cam->center, \
				ray, &scene->diff->cylinders);
		get_help(scene);
		help_func(mrt, scene, scene->cam->center, scene->diff);
		if (scene->diff->next)
			scene->diff = scene->diff->next;
		else
			break ;
	}
	while (scene->diff->prev)
		scene->diff = scene->diff->prev;
	if (scene->tipe == 0 && scene->x > 0)
		get_color(mrt, scene, ray);
	else if (scene->tipe == 0)
		mrt->color = 0;
}

t_vector	*ray_dir(t_scene *scene, double x, double y)
{
	t_vector	*up;
	t_vector	*right;
	t_vector	*other;
	t_vector	*dir;

	scene->obj = NULL;
	scene->x = 0;
	if (scene->cam->direction->x == 0 && scene->cam->direction->z == 0
		&& (scene->cam->direction->y == 1 || scene->cam->direction->y == -1))
		up = new_vec(0, 0, 1);
	else
		up = new_vec(0, 1, 0);
	right = cros_vec(scene->cam->direction, up);
	vec_norm(right);
	free(up);
	up = cros_vec(right, scene->cam->direction);
	vec_norm(up);
	other = vec_sum2(vec_product(right, x), vec_product(up, y));
	dir = vec_sum(other, scene->cam->direction);
	vec_norm(dir);
	free(other);
	free(right);
	free(up);
	return (dir);
}

int	ray_trace(t_mrt *mrt, t_scene *scene)
{
	double		x;
	double		y;
	t_vector	*ray;
	t_vplane	*vplanes;

	vplanes = get_vplane(scene->width, scene->height, scene->cam->fov);
	y = scene->height / 2;
	mrt->y = 0;
	while (y >= (-1) * (scene->height / 2))
	{
		mrt->x = 0;
		x = (scene->width / 2) * (-1);
		while (x <= scene->width / 2)
		{
			ray = ray_dir(scene, x * vplanes->x_pixel, y * vplanes->y_pixel);
			get_object(mrt, scene, ray);
			mlx_pixel_put(mrt->mlx, mrt->mlx_win, mrt->x, mrt->y, mrt->color);
			x++;
			mrt->x++;
			free(ray);
		}
		mrt->y++;
		y--;
		// if (y == 50)
		// {
		// 	printf("!");
		// 	exit(0);
		// }
	}
	list_free(scene->diff);
	free(vplanes);
	return (0);
}
