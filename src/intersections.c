/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/04 13:59:39 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	sphere_touch(t_vector *cam, t_vector *ray, t_sphere *sphere, \
	t_vector *vec)
{
	double		b;
	double		c;
	double		disc;
	double		t1;
	double		t2;	

	t1 = 0;
	t2 = 0;
	disc = 0;
	vec = vec_sub(cam, sphere->center);
	c = vec_dot_product(vec, vec) - (sphere->r * sphere->r);
	b = 2 * (vec_dot_product(vec, ray));
	disc = (b * b) - (4 * c);
	free(vec);
	if (disc < 0)
		return (0);
	t1 = (-b + sqrt(disc)) / 2;
	t2 = (-b - sqrt(disc)) / 2;
	if (t1 < t2 && t1 > 0)
		return (t1);
	else if (t1 > t2 && t2 > 0)
		return (t2);
	return (0);
}

double	planes_touch(t_vector *cam, t_vector *ray, t_plane *planes)
{
	double		num;
	double		t;
	t_vector	*vec;

	num = 0;
	vec = vec_sub(planes->point, cam);
	num = vec_dot_product(vec, planes->norm_vec);
	t = num / vec_dot_product(ray, planes->norm_vec);
	free(vec);
	if (t < 0)
		return (0);
	return (t);
}

double	cyl_touch_help(t_cylinder *cyl, double a, double b, double t)
{
	if (a > b)
		cyl->head = 1;
	if (a < b && a > 0)
		t = a;
	else if (b < a && b > 0)
		t = b;
	return (t);
}
