/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:16:04 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/03 12:28:42 by hrahovha         ###   ########.fr       */
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
	pars->light = NULL;
	pars->camera = NULL;
	pars->ambient = NULL;
	pars->planes = ft_strdup("|");
	pars->spheres = ft_strdup("|");
	pars->cylinders = ft_strdup("|");
}

int	parser(t_pars *pars, char *file)
{
	if (valid_file_type(file, ".rt"))
		err_exit(2);
	parser_init(pars);
	pars->element = read_file(-1, file);
	if (valid_file_elements(pars, pars->element))
	{
		doublefree(pars->element);
		free(pars->planes);
		free(pars->spheres);
		free(pars->cylinders);
		free(pars->light);
		free(pars->camera);
		free(pars->ambient);
		return (1);
	}
	return (0);
}
