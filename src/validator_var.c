/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:36:55 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/28 14:28:15 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_int(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	valid_coords(char *str)
{
	char	**coords;

	coords = ft_split(str, ',');
	if (coords[0] == NULL)
		return (1);
	if (coords[0] != NULL && coords[1] != NULL && coords[2] != NULL)
	{
		if (!valid_float(coords[0]) && !valid_float(coords[1])
			&& !valid_float(coords[2]))
			doublefree(coords);
		else
		{
			doublefree(coords);
			return (1);
		}
	}
	else
	{
		doublefree(coords);
		return (1);
	}
	return (0);
}

int	valid_float(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (str[i] == '.')
		return (1);
	while (str && str[i] && str[i] != '.')
	{
		if (!ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	if (str[i] == '.')
		i++;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	valid_color(char *str, int i, int j)
{
	char	**clr;

	clr = ft_split(str, ',');
	if (!clr)
		return (1);
	if (clr[0] != NULL && clr[1] != NULL && clr[2] != NULL)
	{
		while (++i < 3)
		{
			if (valid_int(clr[i]))
			{
				doublefree(clr);
				return (1);
			}
			j = ft_atoi(clr[i]);
			if (j < 0 || j > 255)
			{
				doublefree(clr);
				return (1);
			}
		}
	}
	doublefree(clr);
	return (0);
}

int	valid_norm_vec(char *str, int i, float j)
{
	char	**vec;

	vec = ft_split(str, ',');
	if (!vec)
		return (1);
	if (vec && vec[0] != NULL && vec[1] != NULL && vec[2] != NULL)
	{
		while (++i < 3)
		{
			if (valid_float(vec[i]))
			{
				doublefree(vec);
				return (1);
			}
			j = my_atof(vec[i]);
			if (j < -1.0 || j > 1.0)
			{
				doublefree(vec);
				return (1);
			}
		}
	}
	doublefree(vec);
	return (0);
}
