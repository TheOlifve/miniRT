/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:53:40 by hrahovha          #+#    #+#             */
/*   Updated: 2024/02/04 20:52:29 by hrahovha         ###   ########.fr       */
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


int	init_cam(t_scene *scene, char **info)
{
	char		**tmp;
	t_vector	*center;
	t_vector	*direction;

	tmp = ft_split(info[1], ',');
	center = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	tmp = ft_split(info[2], ',');
	direction = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	scene->cam = new_cam(center, direction, ft_atoi(info[3]));
	return (0);
}

int	init_light(t_scene *scene, t_pars *pars, char **info)
{
	char		**tmp;
	t_vector	*coord;

	tmp = ft_split(info[1], ',');
	coord = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	scene->lights[pars->l - 1] = new_light(coord, my_atof(info[2]),
		rgbtoi(info[3]));
	pars->l--;
	return (0);
}

int	init_amb(t_scene *scene, char **info)
{
	scene->amblight = new_amblight(my_atof(info[1]), rgbtoi(info[2]));
	return (0);
}

int	init_sphere(t_scene *scene, t_pars *pars, char **info)
{
	char		**tmp;
	t_vector	*center;

	tmp = ft_split(info[1], ',');
	center = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	scene->spheres[pars->sp - 1] = new_sphere(center,
		my_atof(info[2]), info[3]);
	pars->sp--;
	return (0);
}

int	init_plane(t_scene *scene, t_pars *pars, char **info)
{
	char		**tmp;
	t_vector	*point;
	t_vector	*norm_vec;

	tmp = ft_split(info[1], ',');
	point = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	tmp = ft_split(info[2], ',');
	norm_vec = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	scene->planes[pars->pl - 1] = new_plane(point, norm_vec, info[3]);
	pars->pl--;
	return (0);
}

int	init_cylinder(t_scene *scene, t_pars *pars, char **info)
{
	char		**tmp;
	char		**dh;
	t_vector	*center;
	t_vector	*norm_vec;

	tmp = ft_split(info[1], ',');
	center = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	tmp = ft_split(info[2], ',');
	norm_vec = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	dh = malloc(sizeof(char *) * 3);
	dh[0] = ft_strdup(info[3]);
	dh[1] = ft_strdup(info[4]);
	dh[2] = NULL;
	scene->cylinders[pars->cy - 1] = new_cylinder(center, norm_vec, dh, info[5]);
	doublefree(dh);
	pars->cy--;
	return (0);
}

int	type_check(t_scene *scene, t_pars *pars, char **type)
{
	if (!ft_strcmp(type[0], "A"))
		return (init_amb(scene, type));
	else if (!ft_strcmp(type[0], "C"))
		return (init_cam(scene, type));
	else if (!ft_strcmp(type[0], "L"))
		return (init_light(scene, pars, type));
	else if (ft_strcmp(type[0], "sp") == 0)
		return (init_sphere(scene, pars, type));
	else if (ft_strcmp(type[0], "pl") == 0)
		return (init_plane(scene, pars, type));
	else if (ft_strcmp(type[0], "cy") == 0)
		return (init_cylinder(scene, pars, type));
	return (0);
}

int	scene_fill(t_scene *scene, t_pars *pars)
{
	int		i;
	char	**tmp;

	i = -1;
	while (pars->element && pars->element[++i])
	{
		tmp = ft_split(pars->element[i], ' ');
		if (type_check(scene, pars, tmp))
		{
			doublefree(tmp);
			return (1);
		}
		doublefree(tmp);
	}
	return (0);
}

int	scene_alloc(t_scene *scene, t_pars *pars)
{
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
	return (scene_fill(scene, pars));
}
