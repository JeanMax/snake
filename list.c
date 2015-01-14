/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:28:28 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/12 20:31:32 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rempli une liste contenant tous les éléments affichables
** x/y : pos, z : value (0=empty, 1=wall, 2=snake, 3=food)
*/

#include "header.h"
#include "libft.h"

void init_list(t_env *e)
{
	//DEBUG; //debug
	int	x;
	int	y;

	e->first_l = ft_lnew(0, 0, 1);
	e->last_l = e->first_l;
	x = 1;
	y = 0;
	while (x < e->wi)
		ft_ladd(&(e->first_l), ft_lnew(x++, y, 1));
	y++;
	while (y < e->he - 1)
	{
		x = 0;
		ft_ladd(&(e->first_l), ft_lnew(x++, y, 1));
		while (x < e->wi - 1)
			ft_ladd(&(e->first_l), ft_lnew(x++, y, 0));
		ft_ladd(&(e->first_l), ft_lnew(x, y, 1));
		y++;
	}
	x = 0;
	while (x < e->wi)
		ft_ladd(&(e->first_l), ft_lnew(x++, y, 1));
}


