/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:47:27 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/04 14:54:40 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_dot_product(t_vector *vec1, t_vector *vec2)
{
	double	num;

	num = (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z);
	return (num);
}

t_vector	*cros_vec(t_vector *vec1, t_vector *vec2)
{
	t_vector	*vec;

	vec = new_vec(0, 0, 0);
	vec->x = vec1->y * vec2->z - vec1->z * vec2->y;
	vec->y = vec1->z * vec2->x - vec1->x * vec2->z;
	vec->z = vec1->x * vec2->y - vec1->y * vec2->x;
	return (vec);
}

void	vec_norm(t_vector *vec)
{
	double	len;

	len = vec_len(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

t_vector	*vec_sub(t_vector *vec1, t_vector *vec2)
{
	t_vector	*vec;

	vec = new_vec(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	return (vec);
}

double	vec_len(t_vector *vec)
{
	double	len;

	len = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (len);
}
