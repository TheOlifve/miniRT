/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:09:09 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/23 19:13:34 by hrahovha         ###   ########.fr       */
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
	t_scene		*scene;
	
	if (argc != 2)
		err_exit(0);
	scene = NULL;
	if (parser(scene, argv[1]))
		err_exit(-1);
	// t_mrt		mrt;
	// t_camera	*cam;
	// t_sphere	*sphere;
	// t_vector	*sphere_center;
	// t_vector	*cam_center;
	// t_vector	*cam_direction;

	// mrt.mlx = mlx_init();
	// sphere_center = new_vec(4, 4, 10);
	// cam_center  = new_vec(0, 0, 0);
	// cam_direction = new_vec(0, 0, 1);
	// sphere = new_sphere(sphere_center, 12);
	// cam = new_cam(cam_center, cam_direction, 90);
	// scene->width = 800;
	// scene->hight = 600;
	// mrt.mlx_win = mlx_new_window(mrt.mlx, scene->width, scene->hight, "miniRT");
	// mlx_hook(mrt.mlx_win, 2, 1L << 0, key_press, &mrt);
	// mlx_hook(mrt.mlx_win, 17, 1L << 0, my_exit, &mrt);
	// mlx_loop(mrt.mlx);
	system("leaks minirt");
	return (0);
}