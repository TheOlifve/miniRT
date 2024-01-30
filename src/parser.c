/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:16:04 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/30 15:22:50 by hrahovha         ###   ########.fr       */
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
	if (scene_alloc(scene, &pars))
	{
		doublefree(pars.element);
		return (1);
	}	
	return (0);
}
