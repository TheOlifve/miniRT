/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:53:40 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/05 16:45:32 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vector.h"

t_diff	*init_objs2(t_scene *scene, t_diff *diff, t_pars *pars)
{
	int		i;
	char	**elements;

	i = -1;
	elements = ft_split(pars->planes, '|');
	while (++i < pars->pl)
	{
		scene->planes[i] = new_plane(elements[i]);
		diff = new_diff2(diff, scene->planes[i]);
	}
	doublefree(elements);
	return (diff);
}

t_diff	*init_objs(t_scene *scene, t_diff *diff, t_pars *pars)
{
	int		i;
	char	**elements;

	i = -1;
	elements = ft_split(pars->spheres, '|');
	while (++i < pars->sp)
	{
		scene->spheres[i] = new_sphere(elements[i]);
		diff = new_diff1(diff, scene->spheres[i]);
	}
	i = -1;
	doublefree(elements);
	elements = ft_split(pars->cylinders, '|');
	while (++i < pars->cy)
	{
		scene->cylinders[i] = new_cylinder(elements[i]);
		diff = new_diff3(diff, scene->cylinders[i]);
	}
	doublefree(elements);
	diff = init_objs2(scene, diff, pars);
	return (diff);
}

void	init_light(t_scene *scene, t_pars *pars, char **element)
{
	element = ft_split(pars->ambient, ' ');
	scene->amb = new_amb(my_atof(element[1]), element[2]);
	doublefree(element);
	element = ft_split(pars->light, ' ');
	scene->light = new_light(element);
	doublefree(element);
	element = ft_split(pars->camera, ' ');
	scene->cam = new_cam(element);
	doublefree(element);
}

void	init_scene(t_scene *scene, t_pars *pars)
{
	t_diff	*diff;

	diff = NULL;
	scene->cylinders = malloc(sizeof(t_cylinder *) * pars->cy);
	scene->planes = malloc(sizeof(t_plane *) * pars->pl);
	scene->spheres = malloc(sizeof(t_sphere *) * pars->sp);
	diff = init_objs(scene, diff, pars);
	init_light(scene, pars, NULL);
	scene->diff = diff;
	scene->tipe = 0;
}

t_scene	*new_scene(t_pars *pars)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	scene->diff = NULL;
	init_scene(scene, pars);
	return (scene);
}
