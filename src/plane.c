/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/28 15:34:00 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*new_plane(t_vector *vec, t_vector *norm_vec, char **color)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		err_exit(1);
	plane->point = vec;
	plane->norm_vec = norm_vec;
	plane->color = rgbtoi(color);
	return (plane);
}
