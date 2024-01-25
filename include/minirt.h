/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:20:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/25 15:59:05 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "vector.h"
# include "object.h"

typedef struct s_mrt
{
	void	*mlx;
	void	*mlx_win;
}			t_mrt;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
}				t_data;

typedef struct s_pars
{
	int		A;
	int		C;
	int		L;
	int		sp;
	int		pl;
	int		cy;
}			t_pars;

int		err_print(int num);
int		my_exit(t_mrt *mrt);
int		valid_int(char *str);
int		valid_float(char *str);
int		valid_coords(char *str);
int		parser(t_scene *scene, char *file);
int		valid_file_type(char *s1, char *s2);
int		valid_color(char *str, int i, int j);
int		valid_norm_vec(char *str, int i, float j);
int		valid_element(t_pars *pars, char **element);
int		valid_file_elements(t_pars *pars, char **content);
int		valid_light(t_pars *pars, int argc, char **element);
int		valid_camera(t_pars *pars, int argc, char **element);
char	*get_next_line(int fd);
char	**read_file(int fd, char *file);
void	err_exit(int num);
void	doublefree(char **str);
void	ray_trace(t_mrt *mrt, t_scene *scene, int mlx_x, int mlx_y);
float	my_atof(char *str);
float	sphere_touch(t_camera *cam, t_vector *ray, t_sphere *spheres, float disk);

#endif