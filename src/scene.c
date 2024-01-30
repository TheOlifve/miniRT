/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:53:40 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/30 15:33:58 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*new_scene(void)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		err_exit(1);
	scene->width = 0;
	scene->height = 0;
	return (scene);
}

int	scene_free(t_scene *scene)
{
	if (scene->cam)
		free(scene->cam);
	if (scene->amblight)
		free(scene->amblight);
	if (scene->lights)
		dubfree(scene->lights ,NULL, NULL, NULL);
	if (scene->cylinders)
		dubfree(NULL, scene->cylinders, NULL, NULL);
	if (scene->planes)
		dubfree(NULL, NULL, scene->planes, NULL);
	if (scene->spheres)
		dubfree(NULL, NULL, NULL, scene->spheres);
	return (1);
}

int	scene_alloc(t_scene *scene, t_pars *pars)
{
	scene->cam = malloc(sizeof(t_camera));
	if (!scene->cam)
		return (scene_free(scene));
	scene->amblight = malloc(sizeof(t_amblight));
	if (!scene->amblight)
		return (scene_free(scene));
	scene->lights = malloc(pars->l * sizeof(t_light *));
	if (!scene->lights)
		return (scene_free(scene));
	scene->spheres = malloc(pars->sp * sizeof(t_sphere *));
	if (!scene->spheres)
		return (scene_free(scene));
	scene->planes = malloc(pars->pl * sizeof(t_plane *));
	if (!scene->planes)
		return (scene_free(scene));
	scene->cylinders = malloc(pars->cy * sizeof(t_cylinder *));
	if (!scene->cylinders)
		return (scene_free(scene));
	return (0);
}

int	init_amb(t_scene *scene, char **type)
{
	scene->amblight->l_ratio = my_atof(type[1]);
	scene->amblight->color = rgbtoi(type[2]);
}

int	type_check(t_scene *scene, t_pars *pars, char **type)
{
	if (!ft_strcmp(type[0], "a") && !pars->a)
		return (init_amb(scene, type));
	else if (!ft_strcmp(type[0], "c") && !pars->c)
		return (0);
	else if (!ft_strcmp(type[0], "l"))
		return (0);
	else if (ft_strcmp(type[0], "sp") == 0)
		return (0);
	else if (ft_strcmp(type[0], "pl") == 0)
		return (0);
	else if (ft_strcmp(type[0], "cy") == 0)
		return (0);
	else
		return (1);
}

int	scene_fill(t_scene *scene, t_pars *pars)
{
	int		i;
	char	**tmp;

	i = -1;
	while (pars->element && pars->element[++i])
	{
		tmp = ft_split(pars->element[i], ' ');
		
	}
}