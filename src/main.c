/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:09:09 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/28 15:37:26 by hrahovha         ###   ########.fr       */
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
	
	(void)argc;
	(void)argv;
	// if (argc != 2)
	// 	err_exit(0);
	// scene = NULL;
	// if (parser(scene, argv[1]))
	// 	err_exit(-1);
	t_mrt		mrt;
	char		*color[4];
	t_camera	*cam;
	t_sphere	*sphere;  
	t_vector	*sphere_center;
	t_vector	*cam_center;
	t_vector	*cam_direction;

	mrt.mlx = mlx_init();
	sphere_center = new_vec(0, 0, 10);
	color[3] = "RGB";
	color[1] = "200";
	color[2] = "2";
	color[3] = "25";
	sphere = new_sphere(sphere_center, 2, color);
	cam_center  = new_vec(0, 0, 0);
	cam_direction = new_vec(0, 0, 1);
	cam = new_cam(cam_center, cam_direction, 70);
	scene = new_scene(cam, sphere);
	scene->width = 800;
	scene->height = 600;
	mrt.mlx_win = mlx_new_window(mrt.mlx, scene->width, scene->height, "miniRT");
	// while (scene->width >= 0)
	// {
	// 	scene->height = 600;
	// 	while (scene->height >= 0)
	// 	{
	// 		if (scene->height >= 0 && scene->height <= 100)
	// 			mlx_pixel_put(mrt.mlx, mrt.mlx_win, scene->width, scene->height, 16777215);
	// 		scene->height--;
	// 	}
	// 	scene->width--;
	// }
	// ray_trace(&mrt, scene, 0, 0);
	ray_trace(&mrt, scene);
	mlx_hook(mrt.mlx_win, 2, 1L << 0, key_press, &mrt);
	mlx_hook(mrt.mlx_win, 17, 1L << 0, my_exit, &mrt);
	mlx_loop(mrt.mlx);
	system("leaks minirt");
	return (0);
}