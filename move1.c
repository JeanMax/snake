/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 02:55:57 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/24 02:21:09 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** moving some snakes...
*/

#include "header.h"

static void move_h1(t_env *e)
{
	t_lst	*tmp;

	if (e->way1 == 4) //right
    {
		if (e->snake1->prev->z == 2)
        {
            GAME_OVER;
        }
        else if (e->snake1->prev->z == 1)
        {
            tmp = e->first_l;
            while (tmp && !(tmp->x == 1 && tmp->y == e->snake1->y))
                tmp = tmp->next;
            if (!tmp || tmp->z == 2)
                GAME_OVER;
			e->snake1 = tmp;
        }
		else
			e->snake1 = e->snake1->prev;
    }
    else if (e->way1 == 1) //left  
    {
		if (e->snake1->next->z == 2)
        {
            GAME_OVER;
        }
        else if (e->snake1->next->z == 1)
        {
            tmp = e->first_l;
            while (tmp && !(tmp->x == e->wi - 2 && tmp->y == e->snake1->y))
                tmp = tmp->next;
            if (!tmp || tmp->z == 2)
                GAME_OVER;
            e->snake1 = tmp;
        }
        else
			e->snake1 = e->snake1->next;
    }
}

static void move_v1(t_env *e)
{
	t_lst	*tmp;

	if (e->way1 == 2) //up                                                   
    {
        tmp = e->snake1->next;
        while (tmp && tmp->x != e->snake1->x && tmp->y != e->snake1->y + 1)
            tmp = tmp->next;
        if (!tmp || tmp->z == 2)
		{
            GAME_OVER;
		}
		else if (tmp->z == 1)
		{
			tmp = e->first_l;
			while (tmp && !(tmp->x == e->snake1->x && tmp->y == e->he - 2))
				tmp = tmp->next;
			if (!tmp || tmp->z == 2)
				GAME_OVER;
		}
		e->snake1 = tmp;
    }
    else if (e->way1 == 3) //down 
    {
        tmp = e->snake1->prev;
        while (tmp && tmp->x != e->snake1->x && tmp->y != e->snake1->y - 1)
            tmp = tmp->prev;
        if (!tmp || tmp->z == 2)
        {
            GAME_OVER;
        }
        else if (tmp->z == 1)
        {
            tmp = e->first_l;
            while (tmp && !(tmp->x == e->snake1->x && tmp->y == 1))
                tmp = tmp->next;
            if (!tmp || tmp->z == 2)
				GAME_OVER;
        }
		e->snake1 = tmp;
    }
}

static void move_it1(t_env *e, t_lst *save)
{
	t_lst   *tmp;

	if (save->body == NULL)
	{
		tmp = save;
		e->end1 = tmp;
		e->end1->body = NULL;
		while (tmp->body)
			tmp = tmp->body;
		tmp->z = 0;
		if (save->z != 0)
			e->snake1->body = save;
	}
	else
	{
		e->snake1->body = save;
		while (save->body->body)
			save = save->body;
		e->end1 = save;
		e->end1->body->z = 0;
		e->end1->body = NULL;
	}
}

void move1(t_env *e)
{
	t_lst	*tmp;
	t_lst	*save;

	save = e->snake1;
	(e->way1 == 4 || e->way1 == 1) ? move_h1(e) : move_v1(e);
	if (e->snake1->z == 3 || e->snake1->z == 4)
	{
		e->score++;
		e->snake1->body = save;
		while (save->body)
            save = save->body;
		e->end1 = save;
		tmp = free_spot(e, 4);
		if (e->snake1->z == 3)
			tmp->z = 3; //adding food
		else
			e->score++;
		e->bonus++;
	}
	else
		move_it1(e, save);
	e->snake1->z = 2;
}
