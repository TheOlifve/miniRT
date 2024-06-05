/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:20:10 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/05 11:25:39 by rugrigor         ###   ########.fr       */
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
	int			color;
	int			x;
	int			y;
	void		*mlx;
	void		*mlx_win;
	t_vector	*lray;
}			t_mrt;

typedef struct s_pars
{
	int		a;
	int		c;
	int		l;
	int		sp;
	int		pl;
	int		cy;
	char	**element;
	char	*spheres;
	char	*cylinders;
	char	*planes;
	char	*light;
	char	*camera;
	char	*ambient;
}			t_pars;

int		*ctoi(char	**clr);
int		err_print(int num);
int		my_exit(t_mrt *mrt);
int		rgbtoi(int	*color);
int		valid_int(char *str);
int		valid_double(char *str);
int		valid_coords(char *str);
int		valid_coords2(char **str);
int		parser(t_pars *pars, char *file);
int		cylinder2(int argc, char **element);
int		valid_file_type(char *s1, char *s2);
int		valid_color(char *str, int i, int j);
int		valid_norm_vec(char *str, int i, double j);
int		valid_file_elements(t_pars *pars, char **content);
int		get_lray(t_scene *scene, t_vector *ray, t_mrt *mrt);
int		ray_trace(t_mrt *mrt, t_scene *scene, double x, double y);
int		valid_element(t_pars *pars, char *content, char **element);
int		valid_light(t_pars *pars, int argc, char *content, char **element);
int		valid_camera(t_pars *pars, int argc, char *content, char **element);
char	*get_next_line(int fd);
char	**read_file(int fd, char *file);
void	err_exit(int num);
void	doublefree(char **str);
void	list_free(t_diff *diff);
void	get_help(t_scene *scene);
void	light_vers(t_mrt *mrt, int *color1, int *color2);
void	get_color(t_mrt *mrt, t_scene *scene, t_vector *ray);
void	hard_vers(t_scene *scene, t_mrt *mrt, int *color, double intence);
double	my_atof(char *str);
double	a_b_help(t_vector	*vec, t_vector *touch, double t);
double	planes_touch(t_vector *cam, t_vector *ray, t_plane *planes);
double	cyl_touch_help(t_cylinder *cyl, double a, double b, double t);
double	cylinder_touch(t_vector *cam, t_vector *ray, t_cylinder **cyl);
double	sphere_touch(t_vector *cam, t_vector *ray, t_sphere *sphere, \
		t_vector *vec);
t_diff	*new_diff2(t_diff *diff1, t_plane *planes);
t_diff	*new_diff1(t_diff *diff1, t_sphere *sphere);
t_diff	*new_diff3(t_diff *diff1, t_cylinder *cylinders);
t_scene	*new_scene(t_pars *pars);
t_light	*new_light(char **content);

#endif