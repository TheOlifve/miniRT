/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:19:46 by rugrigor          #+#    #+#             */
/*   Updated: 2024/01/25 16:03:00 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*get_vplane(float width, float height, float fov)
{
	t_plane *plane;

	(void) fov;
	plane = malloc(sizeof(t_plane));
	if (!plane)
		err_exit(1);
	plane->width = 1;
	plane->height = 1 / (width / height);
	plane->pixel_x = plane->width / width;
	plane->pixel_y = plane->height / height;
	return (plane);
}