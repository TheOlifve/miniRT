/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vplane.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:16:04 by hrahovha          #+#    #+#             */
/*   Updated: 2024/05/27 14:24:51 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vplane	*get_vplane(double width, double height, double fov)
{
	t_vplane	*vplane;
	double		aspect_ratio;

	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		err_exit(1);
	aspect_ratio = width / height;
	vplane->width = 2 * tan((fov / 2) * (M_PI / 180));
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}
