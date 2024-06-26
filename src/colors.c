/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:05:25 by rugrigor          #+#    #+#             */
/*   Updated: 2024/06/05 11:23:08 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*help_get_norm2(t_scene *scene, t_vector *ray, t_vector *touch)
{
	t_vector	*all;
	double		a;

	if (scene->obj->cylinders->head == 1)
	{
		if (vec_dot_product(scene->obj->cylinders->norm_vec, ray) > 0)
			return (vec_product(scene->obj->cylinders->norm_vec, -1));
		else
			return (new_vec(scene->obj->cylinders->norm_vec->x, \
				scene->obj->cylinders->norm_vec->y, \
					scene->obj->cylinders->norm_vec->z));
	}
	else
	{
		all = vec_sub(touch, scene->obj->cylinders->center);
		a = vec_dot_product(all, scene->obj->cylinders->norm_vec);
		free(all);
		return (vec_sub2(touch, (vec_sum3(scene->obj->cylinders->center, \
			vec_product(scene->obj->cylinders->norm_vec, a)))));
	}
	return (NULL);
}

t_vector	*help_get_norm(t_scene *scene, t_vector *ray, t_vector *touch)
{
	if (scene->obj->tipe == 1)
		return (vec_sub(touch, scene->obj->spheres->center));
	else if (scene->obj->tipe == 2)
	{
		if (vec_dot_product(scene->obj->planes->norm_vec, ray) > 0)
			return (vec_product(scene->obj->planes->norm_vec, -1));
		else
		{
			return (new_vec(scene->obj->planes->norm_vec->x, \
			scene->obj->planes->norm_vec->y, scene->obj->planes->norm_vec->z));
		}
	}
	else if (scene->obj->tipe == 3)
		return (help_get_norm2(scene, ray, touch));
	return (NULL);
}

double	get_norm(t_scene *scene, t_vector *ray)
{
	t_vector	*p;
	t_vector	*touch;
	t_vector	*sur_norm;
	double		intence;

	intence = 0;
	touch = vec_sum3(scene->cam->center, vec_product(ray, scene->obj->t));
	p = vec_sub(scene->light->center, touch);
	vec_norm(p);
	sur_norm = help_get_norm(scene, ray, touch);
	if (sur_norm)
	{
		vec_norm(sur_norm);
		intence = vec_dot_product(sur_norm, p);
		if (intence < 0)
			intence = 0;
	}
	free(p);
	free(touch);
	free(sur_norm);
	return (intence);
}

void	light_help(t_mrt *mrt, t_scene *scene)
{
	if (scene->obj->tipe == 1)
		light_vers(mrt, scene->obj->spheres->color, scene->amb);
	else if (scene->obj->tipe == 2)
		light_vers(mrt, scene->obj->planes->color, scene->amb);
	else if (scene->obj->tipe == 3)
		light_vers(mrt, scene->obj->cylinders->color, scene->amb);
}

void	get_color(t_mrt *mrt, t_scene *scene, t_vector *ray)
{
	int			a;
	t_vector	*lvec;

	lvec = new_vec(ray->x, ray->y, ray->z);
	if (scene->obj && scene->obj->cylinders && scene->obj->cylinders->head)
		a = scene->obj->cylinders->head;
	if (get_lray(scene, lvec, mrt))
	{
		if (scene->obj->tipe == 1)
			hard_vers(scene, mrt, scene->obj->spheres->color, \
				get_norm(scene, ray));
		else if (scene->obj->tipe == 2)
			hard_vers(scene, mrt, scene->obj->planes->color, \
				get_norm(scene, ray));
		else if (scene->obj->tipe == 3)
		{
			scene->obj->cylinders->head = a;
			hard_vers(scene, mrt, scene->obj->cylinders->color, \
				get_norm(scene, ray));
		}
	}
	else
		light_help(mrt, scene);
	free(lvec);
}
