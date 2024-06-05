/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:30:06 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/05 17:06:01 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	err_print(int num)
{
	if (num == 0)
		write(2, "ERROR - Wrong number of parameters\n", 35);
	else if (num == 1)
		write(2, "ERROR: malloc failed\n", 21);
	else if (num == 2)
		write(2, "ERROR: wrong file type\n", 23);
	else if (num == 3)
		write(2, "ERROR: bad file descriptor\n", 27);
	else if (num == 4)
		write(2, "ERROR: wrong file\n", 18);
	return (1);
}

void	err_exit(int num)
{
	if (num == 0)
		write(2, "ERROR - Wrong number of parameters\n", 35);
	else if (num == 1)
		write(2, "ERROR: malloc failed\n", 21);
	else if (num == 2)
		write(2, "ERROR: wrong file type\n", 23);
	else if (num == 3)
		write(2, "ERROR: bad file descriptor\n", 27);
	else if (num == 4)
		write(2, "ERROR: wrong file\n", 18);
	exit(num);
}

int	my_exit(t_mrt *mrt)
{
	mlx_destroy_window(mrt->mlx, mrt->mlx_win);
	exit(0);
}
