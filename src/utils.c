/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:06:05 by hrahovha          #+#    #+#             */
/*   Updated: 2024/06/03 16:19:43 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_coords2(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return (1);
	while (str && str[++i])
		;
	if (i != 3)
	{
		doublefree(str);
		return (1);
	}
	return (0);
}

char	**read_file(int fd, char *file)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	**ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		err_exit(3);
	tmp2 = ft_strdup("");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp3 = ft_strjoin(tmp2, tmp);
		free(tmp2);
		tmp2 = ft_strdup(tmp3);
		free(tmp3);
		free(tmp);
	}
	ret = ft_split(tmp2, '\n');
	free(tmp2);
	if (ret[0] == NULL)
		err_exit(4);
	return (ret);
}

void	doublefree(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	rgbtoi(int	*color)
{
	int	r;
	int	g;
	int	b;

	r = color[0] * (256 * 256);
	g = color[1] * 256;
	b = color[2];
	return (r + g + b);
}

int	*ctoi(char	**clr)
{
	int	*i;

	i = malloc(sizeof(int) * 3);
	i[0] = ft_atoi(clr[0]);
	i[1] = ft_atoi(clr[1]);
	i[2] = ft_atoi(clr[2]);
	return (i);
}
