/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:48:24 by rugrigor          #+#    #+#             */
/*   Updated: 2024/06/04 13:47:43 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*vec_sub3(t_vector *vec1, t_vector *vec2)
{
	t_vector	*vec;

	vec = new_vec(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	free(vec2);
	free(vec1);
	return (vec);
}

t_vector	*vec_sub2(t_vector *vec1, t_vector *vec2)
{
	t_vector	*vec;

	vec = new_vec(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	free(vec2);
	return (vec);
}

double	vec_dot_product2(t_vector *vec1, t_vector *vec2)
{
	double	num;

	num = (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z);
	free(vec2);
	return (num);
}
