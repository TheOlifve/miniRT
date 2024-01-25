/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:09:09 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/25 16:02:15 by rugrigor         ###   ########.fr       */
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
	t_mrt		mrt;
	// t_data		img;
	t_scene		*scene;
	t_camera	*cam;
	t_sphere	*sphere;
	t_vector	*sphere_center;
	t_vector	*cam_center;
	t_vector	*cam_direction;

	// if (argc != 2)
	// 	err_exit(0);
	(void) argv;
	(void) argc;
	mrt.mlx = mlx_init();
	sphere_center = new_vec(12, 15, 32);
	sphere = new_sphere(sphere_center, 12);
	cam_center  = new_vec(0, 0, 0);
	cam_direction = new_vec(0, 0, 1);
	cam = new_cam(cam_center, cam_direction, 70);
	scene = new_scene(cam, sphere);
	// if (parser(scene, argv[1]))
	// 	err_exit(-1);
	scene->width = 800;
	scene->height = 600;
	mrt.mlx_win = mlx_new_window(mrt.mlx, scene->width, scene->height, "miniRT");
	// img.img = mlx_new_image(mrt.mlx, scene->width, scene->height);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	ray_trace(&mrt, scene, 0, 0);
	// mlx_put_image_to_window(mrt.mlx, mrt.mlx_win, img.img, 0, 0);
	mlx_hook(mrt.mlx_win, 2, 1L << 0, key_press, &mrt);
	mlx_hook(mrt.mlx_win, 17, 1L << 0, my_exit, &mrt);
	mlx_loop(mrt.mlx);
	return (0);
}