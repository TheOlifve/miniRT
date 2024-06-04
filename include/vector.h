/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:40:19 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/04 13:26:54 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}		t_vector;

void		vec_norm(t_vector *vec);
double		vec_len(t_vector *vec);
double		vec_dot_product(t_vector *vec1, t_vector *vec2);
double		vec_dot_product2(t_vector *vec1, t_vector *vec2);
t_vector	*new_vec(double x, double y, double z);
t_vector	*vec_sub(t_vector *vec1, t_vector *vec2);
t_vector	*vec_sub2(t_vector *vec1, t_vector *vec2);
t_vector	*vec_sub3(t_vector *vec1, t_vector *vec2);
t_vector	*vec_product(t_vector *vec1, double n);
t_vector	*vec_sum(t_vector *vec1, t_vector *vec2);
t_vector	*vec_sum2(t_vector *vec1, t_vector *vec2);
t_vector	*vec_sum3(t_vector *vec1, t_vector *vec2);
t_vector	*cros_vec(t_vector *vec1, t_vector *vec2);

#endif