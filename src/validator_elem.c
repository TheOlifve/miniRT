/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:36:53 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/30 17:03:48 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ambient_lightning(t_pars *pars, int argc, char **element)
{
	float	light_ratio;

	if (argc != 3)
		return (1);
	if (!valid_float(element[1]))
		light_ratio = my_atof(element[1]);
	else
		return (1);
	if (light_ratio < 0.0 || light_ratio > 1.0)
		return (1);
	if (valid_color(element[2], -1, 0))
		return (1);
	pars->a += 1;
	return (0);
}

int	sphere(t_pars *pars, int argc, char **element)
{
	float	diameter;

	if (argc != 4)
		return (1);
	if (valid_coords(element[1]))
		return (1);
	if (valid_float(element[2]))
		return (1);
	diameter = my_atof(element[2]);
	if (diameter <= 0.0)
		return (1);
	if (valid_color(element[3], -1, 0))
		return (1);
	pars->sp += 1;
	return (0);
}

int	cylinder(t_pars *pars, int argc, char **element)
{
	float	size;

	if (argc != 6)
		return (1);
	if (valid_coords(element[1]))
		return (1);
	if (valid_norm_vec(element[2], -1, 0))
		return (1);
	if (!valid_float(element[3]) && !valid_float(element[4]))
	{
		size = my_atof(element[3]);
		if (size <= 0.0)
			return (1);
		size = my_atof(element[3]);
		if (size <= 0.0)
			return (1);
	}
	else
		return (1);
	if (valid_color(element[5], -1, 0))
		return (1);
	pars->cy += 1;
	return (0);
}

int	plane(t_pars *pars, int argc, char **element)
{
	if (argc != 4)
		return (1);
	if (valid_coords(element[1]))
		return (1);
	if (valid_norm_vec(element[2], -1, 0))
		return (1);
	if (valid_color(element[3], -1, 0))
		return (1);
	pars->pl += 1;
	return (0);
}

int	valid_element(t_pars *pars, char **element)
{
	int	argc;

	argc = -1;
	while (element && element[++argc])
		;
	if (!ft_strcmp(element[0], "A") && !pars->a)
		return(ambient_lightning(pars, argc, element));
	else if (!ft_strcmp(element[0], "C") && !pars->c)
		return(valid_camera(pars, argc, element));
	else if (!ft_strcmp(element[0], "L"))
		return (valid_light(pars, argc, element));
	else if (ft_strcmp(element[0], "sp") == 0)
		return (sphere(pars, argc, element));
	else if (ft_strcmp(element[0], "pl") == 0)
		return (plane(pars, argc, element));
	else if (ft_strcmp(element[0], "cy") == 0)
		return (cylinder(pars, argc, element));
	else
		return (1);
	return (0);
}
