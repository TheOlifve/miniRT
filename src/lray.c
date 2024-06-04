/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lray.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:06:29 by rugrigor          #+#    #+#             */
/*   Updated: 2024/06/04 14:03:29 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_diff	*use_help(t_scene *scene, t_diff *obj)
{
	if ((scene->lx == 0 && scene->diff->lt)
		|| (scene->lx && scene->diff->lt && scene->diff->lt < scene->lx))
	{
		obj = scene->diff;
		scene->lx = scene->diff->lt;
	}
	return (obj);
}

int	use_lray(t_scene *scene, t_mrt *mrt, t_diff *obj)
{
	while (scene->diff)
	{
		scene->diff->lt = 0;
		if (scene->diff->tipe == 1)
			scene->diff->lt = sphere_touch(scene->light->center, \
				mrt->lray, scene->diff->spheres, NULL);
		else if (scene->diff->tipe == 2)
			scene->diff->lt = planes_touch(scene->light->center, \
				mrt->lray, scene->diff->planes);
		else if (scene->diff->tipe == 3)
			scene->diff->lt = cylinder_touch(scene->light->center, \
				mrt->lray, &scene->diff->cylinders);
		obj = use_help(scene, obj);
		if (scene->diff->next)
			scene->diff = scene->diff->next;
		else
			break ;
	}
	while (scene->diff->prev)
		scene->diff = scene->diff->prev;
	if (scene->obj == obj)
		return (1);
	return (0);
}

int	get_lray(t_scene *scene, t_vector *ray, t_mrt *mrt)
{
	t_vector	*touch;

	touch = vec_sum3(scene->cam->center, vec_product(ray, scene->x));
	free(mrt->lray);
	mrt->lray = vec_sub(touch, scene->light->center);
	vec_norm(mrt->lray);
	scene->lx = 0;
	free(touch);
	if (use_lray(scene, mrt, NULL))
		return (1);
	return (0);
}
