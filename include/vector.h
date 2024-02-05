/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:40:19 by hrahovha          #+#    #+#             */
/*   Updated: 2024/02/04 20:21:45 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}		t_vector;

void		vec_norm(t_vector *vec);
float		vec_len(t_vector *vec);
float		vec_dot(t_vector *vec1, t_vector *vec2);
t_vector	*vec_mul(t_vector *vec, float num);
t_vector	*new_vec(float x, float y, float z);
t_vector	*vec_sum(t_vector *vec1, t_vector *vec2);
t_vector	*vec_sub(t_vector *vec1, t_vector *vec2);

#endif