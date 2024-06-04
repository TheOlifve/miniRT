/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:09:09 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/04 16:48:52 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_press(int key, t_mrt *mrt)
{
	if (key == 53)
		my_exit(mrt);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mrt	mrt;
	t_pars	pars;
	t_scene	*scene;

	if (argc != 2)
		err_exit(0);
	scene = NULL;
	if (parser(&pars, argv[1]))
	{
		err_exit(-1);
	}
	mrt.mlx = mlx_init();
	mrt.lray = NULL;
	scene = new_scene(&pars);
	scene->width = 800;
	scene->height = 600;
	mrt.mlx_win = mlx_new_window(mrt.mlx, scene->width, \
		scene->height, "miniRT");
	ray_trace(&mrt, scene);
	mlx_hook(mrt.mlx_win, 2, 1L << 0, key_press, &mrt);
	mlx_hook(mrt.mlx_win, 17, 1L << 0, my_exit, &mrt);
	mlx_loop(mrt.mlx);
	return (0);
}
