/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:43:39 by rugrigor          #+#    #+#             */
/*   Updated: 2024/05/27 14:49:40 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*new_light(char **element)
{
	char		**tmp;
	t_light		*light;

	light = malloc(sizeof(t_light));
	tmp = ft_split(element[1], ',');
	light->center = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	light->intence = my_atof(element[2]);
	tmp = ft_split(element[3], ',');
	light->color = ctoi(tmp);
	doublefree(tmp);
	return (light);
}

int	*new_amb(double intence, char *color)
{
	int		*clr;
	char	**color2;

	clr = malloc(sizeof(int) * 3);
	color2 = ft_split (color, ',');
	clr[0] = my_atof(color2[0]) * intence;
	clr[1] = my_atof(color2[1]) * intence;
	clr[2] = my_atof(color2[2]) * intence;
	doublefree(color2);
	if (clr[0] > 255)
		clr[0] = 255;
	if (clr[1] > 255)
		clr[1] = 255;
	if (clr[2] > 255)
		clr[2] = 255;
	return (clr);
}
