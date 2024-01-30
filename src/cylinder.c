/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/30 15:42:11 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*new_cylinder(t_vector *cent, t_vector *nvec, char **dh, char *clr)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(cylinder));
	if (!cylinder)
		err_exit(1);
	cylinder->center = cent;
	cylinder->norm_vec = nvec;
	cylinder->r = my_atof(dh[0]) / 2;
	cylinder->h = my_atof(dh[1]);
	cylinder->color = rgbtoi(clr);
	return (cylinder);
}
