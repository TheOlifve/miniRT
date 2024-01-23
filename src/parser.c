/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:16:04 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/23 22:14:31 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parser_init(t_pars *pars)
{
	pars->A = 0;
	pars->C = 0;
	pars->L = 0;
	pars->sp = 0;
	pars->pl = 0;
	pars->cy = 0;
}

int	parser(t_scene *scene, char *file)
{
	t_pars	pars;
	char	**content;
	
	(void)scene;
	if (valid_file_type(file, ".rt"))
		err_exit(2);
	content = read_file(-1, file);
	parser_init(&pars);
	if (valid_file_elements(&pars, content))
	{
		doublefree(content);
		return (1);
	}
	doublefree(content);
	return (0);
}