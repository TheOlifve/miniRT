/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:53:40 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/25 13:57:15 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*new_scene(t_camera *cam, t_sphere *sphere)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!cam)
		err_exit(1);
	scene->cams = cam;
	scene->spheres = sphere;
	scene->width = 0;
	scene->height = 0;
	return (scene);
}
