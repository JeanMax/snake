/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 18:54:23 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/28 13:45:52 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** print some stuff on stdout...
*/

#include "header.h"

t_lst	*free_spot(t_env *e, int seed)
{
	t_lst	*tmp;
	t_lst	*save;

	tmp = e->first_l;
	while (tmp->z != 0)
	{
		tmp = ft_lat(&(e->first_l), rand_a_b(e->wi, (e->wi * e->he - e->wi), seed));
		save = tmp;
		while (tmp->z != 0 && tmp->next)
			tmp = tmp->next;
		if (tmp->z != 0)
		{
			tmp = save;
			while (tmp->z != 0 && tmp->prev)
				tmp = tmp->prev;
			if (tmp->z != 0)
				YAY;
		}
	}
	return (tmp);
}

int rand_a_b(int a, int b, int seed) //bugged?
{
	srand(time(NULL) * seed);
	return rand()%(b-a) +a;
}

void	print_map(t_env *e)
{
	t_lst	*tmp;

	tmp = e->last_l;
	while (tmp)
	{
		if (tmp->z == 0)
			ft_putchar(' ');
		else if (tmp->z == 1)
            ft_putchar_clr('#', "zboub");
		else if (tmp->z == 2 && tmp != e->snake1 && tmp != e->snake2)
            ft_putchar_clr('s', "gr");
		else if (tmp->z == 2)
            ft_putchar_clr('S', "gr");
		else if (tmp->z == 3)
            ft_putchar_clr('o', "sk");
		else if (tmp->z == 4)
            ft_putchar_clr('x', "re");
		if (tmp->x == e->wi - 1)
			ft_putchar('\n');
		tmp = tmp->prev;
	}
}

