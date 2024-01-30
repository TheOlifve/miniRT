/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:58:29 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/30 16:54:47 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*new_light(t_vector *coord, float bright, int color)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		err_exit(1);
	light->coord = coord;
	light->bright = bright;
	light->color = color;
	return (light);
}

t_amblight	*new_amblight(float l_ratio, int color)
{
	t_amblight	*amblight;

	amblight = malloc(sizeof(t_amblight));
	if (!amblight)
		err_exit(1);
	amblight->l_ratio = l_ratio;
	amblight->color = color;
	return (amblight);
}
