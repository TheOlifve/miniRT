/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:15:07 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/03 15:39:34 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	cylinder2(int argc, char **element)
{
	if (argc != 6)
		return (1);
	if (valid_coords(element[1]))
		return (1);
	if (valid_norm_vec(element[2], -1, 0))
		return (1);
	return (0);
}

t_cylinder	*new_cylinder(char *info)
{
	char		**tmp;
	char		**tmp2;
	t_cylinder	*obj;

	obj = malloc(sizeof(t_cylinder));
	if (!obj)
		err_exit(1);
	tmp = ft_split(info, ' ');
	tmp2 = ft_split(tmp[1], ',');
	obj->center = new_vec(my_atof(tmp2[0]), my_atof(tmp2[1]), \
		my_atof(tmp2[2]));
	doublefree(tmp2);
	tmp2 = ft_split(tmp[2], ',');
	obj->norm_vec = new_vec(my_atof(tmp2[0]), my_atof(tmp2[1]), \
		my_atof(tmp2[2]));
	vec_norm(obj->norm_vec);
	obj->r = my_atof(tmp[3]) / 2;
	obj->h = my_atof(tmp[4]);
	doublefree(tmp2);
	tmp2 = ft_split(tmp[5], ',');
	obj->color = ctoi(tmp2);
	obj->head = 0;
	doublefree(tmp2);
	doublefree(tmp);
	return (obj);
}
