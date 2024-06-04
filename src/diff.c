/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:06:46 by rugrigor          #+#    #+#             */
/*   Updated: 2024/06/03 15:43:23 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_diff	*new_diff1(t_diff *diff1, t_sphere *sphere)
{
	t_diff	*diff;

	diff = malloc(sizeof(t_diff));
	if (!diff)
		return (NULL);
	diff->t = 0;
	diff->tipe = 1;
	diff->next = NULL;
	diff->prev = NULL;
	diff->spheres = sphere;
	diff->cylinders = NULL;
	diff->planes = NULL;
	if (!diff1)
		return (diff);
	diff1->next = diff;
	diff->prev = diff1;
	return (diff);
}

t_diff	*new_diff2(t_diff *diff1, t_plane *planes)
{
	t_diff	*diff;

	diff = malloc(sizeof(t_diff));
	if (!diff)
		return (NULL);
	diff->t = 0;
	diff->tipe = 2;
	diff->next = NULL;
	diff->prev = NULL;
	diff->spheres = NULL;
	diff->cylinders = NULL;
	diff->planes = planes;
	if (!diff1)
		return (diff);
	diff1->next = diff;
	diff->prev = diff1;
	return (diff);
}

t_diff	*new_diff3(t_diff *diff1, t_cylinder *cylinders)
{
	t_diff	*diff;

	diff = malloc(sizeof(t_diff));
	if (!diff)
		return (NULL);
	diff->t = 0;
	diff->tipe = 3;
	diff->next = NULL;
	diff->prev = NULL;
	diff->spheres = NULL;
	diff->cylinders = cylinders;
	diff->planes = NULL;
	if (!diff1)
		return (diff);
	diff1->next = diff;
	diff->prev = diff1;
	return (diff);
}
