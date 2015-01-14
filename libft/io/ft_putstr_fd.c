/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:56:38 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:25:31 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ecrit la chaine s sur le descripteur de fichier fd.
*/

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
