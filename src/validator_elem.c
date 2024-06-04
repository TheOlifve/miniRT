/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:36:53 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/03 15:48:00 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ambient_lightning(t_pars *pars, int argc, char *content, char **element)
{
	double	light_ratio;

	if (argc != 3)
		return (1);
	if (!valid_double(element[1]))
		light_ratio = my_atof(element[1]);
	else
		return (1);
	if (light_ratio < 0.0 || light_ratio > 1.0)
		return (1);
	if (valid_color(element[2], -1, 0))
		return (1);
	pars->a += 1;
	pars->ambient = ft_strdup(content);
	return (0);
}

int	sphere(t_pars *pars, char *content, int argc, char **element)
{
	char	*tmp;
	double	diameter;

	if (argc != 4)
		return (1);
	if (valid_coords(element[1]))
		return (1);
	if (valid_double(element[2]))
		return (1);
	diameter = my_atof(element[2]);
	if (diameter <= 0.0)
		return (1);
	if (valid_color(element[3], -1, 0))
		return (1);
	tmp = ft_strjoin(pars->spheres, "|");
	free(pars->spheres);
	pars->spheres = ft_strjoin(tmp, content);
	free(tmp);
	pars->sp += 1;
	return (0);
}

int	cylinder(t_pars *pars, char *content, int argc, char **element)
{
	char	*tmp;
	double	size;

	if (cylinder2(argc, element))
		return (1);
	if (!valid_double(element[3]) && !valid_double(element[4]))
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
	tmp = ft_strjoin(pars->cylinders, "|");
	free(pars->cylinders);
	pars->cylinders = ft_strjoin(tmp, content);
	free(tmp);
	pars->cy += 1;
	return (0);
}

int	plane(t_pars *pars, char *content, int argc, char **element)
{
	char	*tmp;

	if (argc != 4)
		return (1);
	if (valid_coords(element[1]))
		return (1);
	if (valid_norm_vec(element[2], -1, 0))
		return (1);
	if (valid_color(element[3], -1, 0))
		return (1);
	tmp = ft_strjoin(pars->planes, "|");
	free(pars->planes);
	pars->planes = ft_strjoin(tmp, content);
	free(tmp);
	pars->pl += 1;
	return (0);
}

int	valid_element(t_pars *pars, char *content, char **element)
{
	int	argc;

	argc = -1;
	while (element && element[++argc])
		;
	if (!ft_strcmp(element[0], "A") && !pars->a)
		return (ambient_lightning(pars, argc, content, element));
	else if (!ft_strcmp(element[0], "C") && !pars->c)
		return (valid_camera(pars, argc, content, element));
	else if (!ft_strcmp(element[0], "L") && !pars->l)
		return (valid_light(pars, argc, content, element));
	else if (ft_strcmp(element[0], "sp") == 0)
		return (sphere(pars, content, argc, element));
	else if (ft_strcmp(element[0], "pl") == 0)
		return (plane(pars, content, argc, element));
	else if (ft_strcmp(element[0], "cy") == 0)
		return (cylinder(pars, content, argc, element));
	else
		return (1);
	return (0);
}
