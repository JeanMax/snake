/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:01:33 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:24:13 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ecrit la chaine s sur le descripteur de fichier fd suivi d’un ’\n’.
*/

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
