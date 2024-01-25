/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:47:27 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/25 16:00:45 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*new_vec(float x, float y, float z)
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

t_vector	*vec_sub(t_vector *vec1, t_vector *vec2)
{
	t_vector	*vec;

	vec = new_vec(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	return (vec);
}

float	vec_len(t_vector *vec)
{
	float	len;

	len = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (len);
}

float	vec_scal(t_vector *vec1, t_vector *vec2)
{
	float	num;

	num = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (num);
}

void	vec_norm(t_vector *vec)
{
	float	len;

	len = vec_len(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}
