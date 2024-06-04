/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:04:08 by rugrigor          #+#    #+#             */
/*   Updated: 2024/06/04 16:56:59 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	cyl_help(double disc, double b, t_vector *v)
{
	double		t1;
	double		t2;

	t1 = (-b + sqrt(disc)) / (2 * vec_dot_product(v, v));
	t2 = (-b - sqrt(disc)) / (2 * vec_dot_product(v, v));
	free(v);
	if (disc < 0)
		return (0);
	if (t1 < t2 && t1 > 0)
		return (t1);
	else if (t1 > t2 && t2 > 0)
		return (t2);
	return (0);
}

double	cylinder_touch2(t_vector *cam, t_vector *ray, t_cylinder *cyl)
{
	t_vector	*p;
	t_vector	*v;
	double		ac;
	double		b;
	double		disc;

	v = vec_sub2(ray, vec_product(cyl->norm_vec, \
		vec_dot_product(cyl->norm_vec, ray)));
	p = vec_sub3(vec_sub(cam, cyl->center), vec_product(cyl->norm_vec, \
		vec_dot_product2(cyl->norm_vec, vec_sub(cam, cyl->center))));
	ac = vec_dot_product(v, v) * (vec_dot_product(p, p) - (cyl->r * cyl->r));
	b = 2 * (vec_dot_product(v, p));
	disc = (b * b) - (4 * ac);
	free(p);
	return (cyl_help(disc, b, v));
}

double	head_int(t_vector *cam, t_vector *ray, t_vector *vec1, t_vector *vec2)
{
	double	a;
	double	l;

	a = vec_dot_product(vec1, ray);
	if (fabs(a) < 0)
		return (0);
	l = vec_dot_product2(vec1, vec_sub(vec2, cam)) / a;
	if (l < 0)
		return (0);
	return (l);
}

int	cyl_heads(t_vector *cam, t_vector *ray, t_cylinder **cyl, double t)
{
	t_vector	*cyl2;
	t_vector	*vec;
	t_vector	*touch;

	vec = vec_sum3((*cyl)->center, vec_product((*cyl)->norm_vec, (*cyl)->h));
	touch = vec_sum3(cam, vec_product(ray, t));
	cyl2 = NULL;
	if (t > 0)
	{
		if ((*cyl)->head)
			cyl2 = vec_sub(touch, vec);
		else
			cyl2 = vec_sub(touch, (*cyl)->center);
		if (vec_dot_product2(cyl2, cyl2) < ((*cyl)->r * (*cyl)->r))
		{
			(*cyl)->head = 1;
			free(touch);
			free(vec);
			return (1);
		}
	}
	free(touch);
	free(vec);
	return (0);
}

double	cylinder_touch(t_vector *cam, t_vector *ray, t_cylinder **cyl)
{
	double		t;
	double		a;
	double		b;
	t_vector	*touch;
	t_vector	*vec;

	(*cyl)->head = 0;
	t = cylinder_touch2(cam, ray, *cyl);
	if (!t)
		return (0);
	vec = vec_sum3((*cyl)->center, vec_product((*cyl)->norm_vec, (*cyl)->h));
	touch = vec_sum3(cam, vec_product(ray, t));
	a = vec_dot_product2((*cyl)->norm_vec, vec_sub(touch, (*cyl)->center));
	b = vec_dot_product2((*cyl)->norm_vec, vec_sub(touch, vec));
	if (a > 0 && b < 0)
	{
		free(vec);
		free(touch);
		return (t);
	}
	a = head_int(cam, ray, (*cyl)->norm_vec, (*cyl)->center);
	b = head_int(cam, ray, (*cyl)->norm_vec, vec);
	t = cyl_touch_help(*cyl, a, b, t);
	free(vec);
	free(touch);
	if (cyl_heads(cam, ray, cyl, t))
		return (t);
	return (0);
}
