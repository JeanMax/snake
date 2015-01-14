/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 02:55:57 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/24 02:33:45 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** moving some snakes...
*/

#include "header.h"

static void move_h2(t_env *e)
{
	t_lst	*tmp;

	if (e->way2 == 8) //right
    {
		if (e->snake2->prev->z == 2)
        {
            GAME_OVER;
        }
        else if (e->snake2->prev->z == 1)
        {
            tmp = e->first_l;
            while (tmp && !(tmp->x == 1 && tmp->y == e->snake2->y))
                tmp = tmp->next;
            if (!tmp || tmp->z == 2)
                GAME_OVER;
			e->snake2 = tmp;
        }
		else
			e->snake2 = e->snake2->prev;
    }
    else if (e->way2 == 5) //left  
    {
		if (e->snake2->next->z == 2)
        {
            GAME_OVER;
        }
        else if (e->snake2->next->z == 1)
        {
            tmp = e->first_l;
            while (tmp && !(tmp->x == e->wi - 2 && tmp->y == e->snake2->y))
                tmp = tmp->next;
            if (!tmp || tmp->z == 2)
                GAME_OVER;
            e->snake2 = tmp;
        }
        else
			e->snake2 = e->snake2->next;
    }
}

static void move_v2(t_env *e)
{
	t_lst	*tmp;

	if (e->way2 == 6) //up                                                   
    {
        tmp = e->snake2->next;
        while (tmp && tmp->x != e->snake2->x && tmp->y != e->snake2->y + 1)
            tmp = tmp->next;
        if (!tmp || tmp->z == 2)
		{
            GAME_OVER;
		}
		else if (tmp->z == 1)
		{
			tmp = e->first_l;
			while (tmp && !(tmp->x == e->snake2->x && tmp->y == e->he - 2))
				tmp = tmp->next;
			if (!tmp || tmp->z == 2)
				GAME_OVER;
		}
		e->snake2 = tmp;
    }
    else if (e->way2 == 7) //down 
    {
        tmp = e->snake2->prev;
        while (tmp && tmp->x != e->snake2->x && tmp->y != e->snake2->y - 1)
            tmp = tmp->prev;
        if (!tmp || tmp->z == 2)
        {
            GAME_OVER;
        }
        else if (tmp->z == 1)
        {
            tmp = e->first_l;
            while (tmp && !(tmp->x == e->snake2->x && tmp->y == 1))
                tmp = tmp->next;
            if (!tmp || tmp->z == 2)
				GAME_OVER;
        }
		e->snake2 = tmp;
    }
}

static void move_it2(t_env *e, t_lst *save)
{
	t_lst   *tmp;

	if (save->body == NULL)
	{
		tmp = save;
		e->end2 = tmp;
		e->end2->body = NULL;
		while (tmp->body)
			tmp = tmp->body;
		tmp->z = 0;
		if (save->z != 0)
			e->snake2->body = save;
	}
	else
	{
		e->snake2->body = save;
		while (save->body->body)
			save = save->body;
		e->end2 = save;
		e->end2->body->z = 0;
		e->end2->body = NULL;
	}
}

void move2(t_env *e)
{
	t_lst	*tmp;
	t_lst	*save;

	save = e->snake2;
	(e->way2 == 8 || e->way2 == 5) ? move_h2(e) : move_v2(e);
	if (e->snake2->z == 3 || e->snake2->z == 4)
	{
		e->score++;
		e->snake2->body = save;
		while (save->body)
            save = save->body;
		e->end2 = save;
		tmp = free_spot(e, 4);
		if (e->snake2->z == 3)
			tmp->z = 3; //adding food
		else
			e->score++;
		e->bonus++;
	}
	else
		move_it2(e, save);
	e->snake2->z = 2;
}
