/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_clr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:53:08 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/27 01:07:01 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Affiche le caractère c sur la sortie standard (coloré).
** Clr= yellow, blue, red, green, pink, sky, white, (default=grey)
*/

#include "libft.h"

void	ft_putchar_clr(char c, char *clr)
{

	char str[] = "\033[30;01mX\033[0m";

	str[8] = c;
	str[3] = (clr[0] == 'r' ? '1' : str[3]);
	str[3] = (clr[0] == 'g' ? '2' : str[3]);
	str[3] = (clr[0] == 'y' ? '3' : str[3]);
	str[3] = (clr[0] == 'b' ? '4' : str[3]);
	str[3] = (clr[0] == 'p' ? '5' : str[3]);
	str[3] = (clr[0] == 's' ? '6' : str[3]);
	str[3] = (clr[0] == 'w' ? '7' : str[3]);
	write(1, str, 13);
}

