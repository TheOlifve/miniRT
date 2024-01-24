/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:37:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/24 16:08:49 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_trace(void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y;
	float		ang_x;
	float		ang_y;
	t_vector	*vec;
	t_plane		*plane;

	mlx_x = 0;
	mlx_y = 0;
	plane = get_vplane(scene->width, scene->hight, scene->cams->fov);
	ang_y = (scene->width / 2);
	
	ang_x = (scene->hight / 2)
}

t_plane	*get_vplane(float width, float height, float fov)
{
	t_plane *plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		err_exit(1);
	plane->width = 1;
	plane->height = 1;
}