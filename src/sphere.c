/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:35:40 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/03 15:47:51 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*new_sphere(char *info)
{
	char		**tmp;
	char		**tmp2;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		err_exit(1);
	tmp = ft_split(info, ' ');
	tmp2 = ft_split(tmp[1], ',');
	sphere->center = new_vec(my_atof(tmp2[0]), my_atof(tmp2[1]), \
		my_atof(tmp2[2]));
	sphere->r = my_atof(tmp[2]) / 2;
	doublefree(tmp2);
	tmp2 = ft_split(tmp[3], ',');
	sphere->color = ctoi(tmp2);
	doublefree(tmp2);
	doublefree(tmp);
	return (sphere);
}
