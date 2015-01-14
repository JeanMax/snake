/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:07:36 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/16 01:10:51 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne un maillon “frais”. Un tas de champs
** sont remplis. Les verifications de paramètres devraient être faites.
*/

#include "libft.h"

t_lst		*ft_lnew(int x, int y, int z)
{
	t_lst			*new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	new->x = x ? x : 0;
	new->y = y ? y : 0;
	new->z = z ? z : 0;
	new->next = NULL;
	new->prev = NULL;
	new->body = NULL;
	return (new);
}
