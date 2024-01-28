/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:03:17 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/28 14:29:37 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_file_type(char *s1, char *s2)
{
	int		i;
	int		j;

	if (!s1 || !s2)
		return (1);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	if (i <= j)
		return (1);
	while (j >= 0)
	{
		if (s1[i] != s2[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

int	valid_camera(t_pars *pars, int argc, char **element)
{
	int	fov;

	if (argc != 4)
		return (1);
	if (valid_coords(element[1]))
		return (1);
	if (valid_norm_vec(element[2], -1, 0))
		return (1);
	if (valid_int(element[3]))
		return (1);
	fov = ft_atoi(element[3]);
	if (fov < 0 || fov > 180)
		return (1);
	pars->C += 1;
	return (0);
}

int	valid_light(t_pars *pars, int argc, char **element)
{
	float	brightness;

	if (argc != 4)
		return (1);
	if (valid_coords(element[1]))
		return (1);
	if (valid_float(element[2]))
		return (1);
	brightness = my_atof(element[2]);
	if (brightness < 0.0 || brightness > 1.0)
		return (1);
	if (valid_color(element[3], -1, 0))
		return (1);
	pars->L += 1;
	return (0);
}

int	valid_file_elements(t_pars *pars, char **content)
{
	int		i;
	char	**element;

	i = -1;
	while (content && content[++i])
	{
		element = ft_split(content[i], ' ');
		if (valid_element(pars, element))
		{
			doublefree(element);
			return (err_print(4));
		}
		doublefree(element);
	}
	return (0);
}
