/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 02:55:57 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/24 02:28:31 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** moving some snakes...
*/

#include "header.h"

void push_key(t_env *e)
{
	int				key;
	struct timeval	tick;
	struct timeval	tack;
	t_lst			*tmp;
	int				count;

	e->bonus = 0;
	count = 0;
    while (42 == 42)
    {
		if ((e->bonus % 5 == 0) && (count % 5 == 0))
		{
			tmp = free_spot(e, 5);
			tmp->z = 4;
			e->bonus++;
			count = 0;
		}
		gettimeofday(&tick, NULL);
		if (count == (e->he + e->wi / 2) && tmp->z == 4)
			tmp->z = 0;
        key = getarrowkey();
        if (key > 0 && key < 5 && 
			!(e->way1 == 1 && key == 4) && !(e->way1 == 4 && key == 1) &&
			!(e->way1 == 2 && key == 3) && !(e->way1 == 3 && key == 2))
			e->way1 = key;
		else if (key > 4 && key < 9 &&
            !(e->way2 == 5 && key == 8) && !(e->way2 == 8 && key == 5) &&
            !(e->way2 == 6 && key == 7) && !(e->way2 == 7 && key == 6))
            e->way2 = key;
		move1(e);
		move2(e);
        system("clear");
		print_map(e);
		ft_putstr("Score: ");
		ft_putnbr(e->score);
		ft_putendl(" ");
		gettimeofday(&tack, NULL);
		if (tack.tv_usec < tick.tv_usec)
			tack.tv_usec = tick.tv_usec;
		usleep(e->sp * 1000 - (tack.tv_usec - tick.tv_usec));
		count++;
    }
}
