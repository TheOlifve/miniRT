/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <rugrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:42:48 by rugrigor          #+#    #+#             */
/*   Updated: 2024/06/03 15:43:26 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	list_free(t_diff *diff)
{
	int		x;

	x = 0;
	while (diff->prev != NULL)
	{
		diff = diff->prev;
		x++;
	}
	while (x-- != 0)
		diff = diff->next;
	while (diff->prev != NULL)
	{
		if (diff->next)
			free(diff->next);
		diff = diff->prev;
	}
	free(diff);
}
