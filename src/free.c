/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:42:48 by rugrigor          #+#    #+#             */
/*   Updated: 2024/06/05 16:03:55 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	list_free(t_diff *diff)
{
	t_diff *tmp;

	tmp = NULL;
	while (diff->prev != NULL)
		diff = diff->prev;
	while (diff && diff->next != NULL)
	{
		if (diff->next == NULL)
			break ;
		else
		{
			tmp = diff->next;
			free(diff);
			diff = tmp;
		}
	}
	free(diff);
}
