/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:37:59 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/03 17:39:41 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	light_vers(t_mrt *mrt, int *color1, int *color2)
{
	int	color[3];

	color[0] = color1[0] * color2[0] / 255;
	color[1] = color1[1] * color2[1] / 255;
	color[2] = color1[2] * color2[2] / 255;
	mrt->color = rgbtoi(color);
}

void	hard_vers(t_scene *scene, t_mrt *mrt, int *color, double intence)
{
	int	color1[3];
	int	color2[3];

	color2[0] = scene->light->color[0] * intence;
	color2[1] = scene->light->color[1] * intence;
	color2[2] = scene->light->color[2] * intence;
	if (color2[0] > 255)
		color2[0] = 255;
	if (color2[1] > 255)
		color2[1] = 255;
	if (color2[2] > 255)
		color2[2] = 255;
	color1[0] = scene->amb[0] + color2[0];
	color1[1] = scene->amb[1] + color2[1];
	color1[2] = scene->amb[2] + color2[2];
	if (color1[0] > 255)
		color1[0] = 255;
	if (color1[1] > 255)
		color1[1] = 255;
	if (color1[2] > 255)
		color1[2] = 255;
	light_vers(mrt, color1, color);
}
