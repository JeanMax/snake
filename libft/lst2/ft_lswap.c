/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 16:50:46 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/24 16:49:52 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Echange la position de deux élements dans la liste
*/

#include "libft.h"

void	ft_lswap(t_lst *lst1, t_lst *lst2)
{
	t_lst	*target;
	t_lst	*swap;

	if (ft_lisfirst(&lst1))
	{
		swap = lst2;
		lst2 = lst1;
		lst1 = swap;
	}
	if (lst1->prev != lst2)
		target = lst1->prev;
	else
		target = lst1->prev->prev;
	ft_ldellink(lst1);
	ft_lrplc(lst2, lst1);
	ft_linser(&target, lst2);
}
