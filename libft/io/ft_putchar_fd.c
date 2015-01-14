/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:52:50 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:23:43 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ecrit le caractère c sur le descripteur de fichier fd.
*/

#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
