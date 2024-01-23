/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:14:26 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/22 20:14:54 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	after_dot(char *str)
{
	int		i;
	float	res;

	i = 0;
	res = 0.0;
	while (str[i])
	{
		res = res * 10.0 + str[i] - '0';
		i++;
	}
	while (i--)
		res /= 10;
	return (res);
}

float	before_dot(char *str)
{
	int		i;
	float	res;

	i = 0;
	res = 0.0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

float	my_atof(char *str)
{
	float	res;
	int		i;
	float	sign;

	res = 0;
	i = 0;
	sign = 1.0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		++str;
	}
	res = before_dot(str);
	while (str[i] && str[i] != '.')
		i++;
	if (str[i])
		res += after_dot(str + i + 1);
	return (res * sign);
}
