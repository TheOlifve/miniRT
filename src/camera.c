/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:43:50 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/30 19:45:53 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*new_cam(t_vector *center, t_vector *direction, float fov)
{
	t_camera	*cam;

	// cam = NULL;
	// (void)center;
	// (void)direction;
	// (void)fov;
	cam = malloc(sizeof(t_camera));
	if (!cam)
		err_exit(1);
	cam->center = center;
	cam->direction = direction;
	cam->fov = fov;
	return (cam);
}
