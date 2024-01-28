/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:16:04 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/28 15:51:31 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parser_init(t_pars *pars)
{
	pars->a = 0;
	pars->c = 0;
	pars->l = 0;
	pars->sp = 0;
	pars->pl = 0;
	pars->cy = 0;
	pars->element = NULL;
}

int	scene_alloc(t_scene *scene, t_pars *pars)
{
	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (err_print(1));
	scene->cams = malloc(sizeof(t_camera));
	if (!scene->cams)
	{
		free(scene->cams);
		return (err_print(1));
	}
	scene->spheres = malloc(sizeof(t_sphere) * pars->sp);
	if (!scene->spheres)
	{
		free(scene);
		free(scene->cams);
		return (err_print(1));
	}
	return (0);
}

int	parser(t_scene *scene, char *file)
{
	t_pars	pars;

	(void)scene;
	if (valid_file_type(file, ".rt"))
		err_exit(2);
	parser_init(&pars);
	pars.element = read_file(-1, file);
	if (valid_file_elements(&pars, pars.element))
	{
		doublefree(pars.element);
		return (1);
	}
	return (0);
}
