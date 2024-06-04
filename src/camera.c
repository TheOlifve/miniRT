/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:43:50 by hrahovha          #+#    #+#             */
/*   Updated: 2024/05/27 14:46:23 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*new_cam(char **element)
{
	char		**tmp;
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		err_exit(1);
	tmp = ft_split(element[1], ',');
	cam->center = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	tmp = ft_split(element[2], ',');
	cam->direction = new_vec(my_atof(tmp[0]), my_atof(tmp[1]), my_atof(tmp[2]));
	doublefree(tmp);
	cam->fov = my_atof(element[3]);
	return (cam);
}
