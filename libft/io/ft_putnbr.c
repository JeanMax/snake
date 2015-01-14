/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:54:09 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/13 18:29:58 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Affiche l’entier n sur la sortie standard.
*/

#include "libft.h"

void	ft_putnbr(int nbr)
{
	ft_putstr(ft_itoa(nbr));
}
