/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:48:24 by rugrigor          #+#    #+#             */
/*   Updated: 2024/06/04 16:53:56 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*new_vec(double x, double y, double z)
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	if (!vec)
		err_exit(1);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vector	*vec_sum3(t_vector *vec1, t_vector *vec2)
{
	t_vector	*vec;

	vec = new_vec(vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z);
	free(vec2);
	return (vec);
}

t_vector	*vec_sum2(t_vector *vec1, t_vector *vec2)
{
	t_vector	*vec;

	vec = new_vec(vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z);
	free(vec1);
	free(vec2);
	return (vec);
}

t_vector	*vec_sum(t_vector *vec1, t_vector *vec2)
{
	t_vector	*vec;

	vec = new_vec(vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z);
	return (vec);
}

t_vector	*vec_product(t_vector *vec1, double n)
{
	t_vector	*vec2;

	vec2 = new_vec(vec1->x, vec1->y, vec1->z);
	vec2->x *= n;
	vec2->y *= n;
	vec2->z *= n;
	return (vec2);
}
