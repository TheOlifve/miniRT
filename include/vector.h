/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:40:19 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/25 11:55:46 by rugrigor         ###   ########.fr       */
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
float		vec_scal(t_vector *vec1, t_vector *vec2);
t_vector	*new_vec(float x, float y, float z);
t_vector	*vec_sub(t_vector *vec1, t_vector *vec2);

#endif