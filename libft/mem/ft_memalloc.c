/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:24:25 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:30:36 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne une zone de mémoire “fraiche”. La mémoire
** allouée est initialisée à 0. Si l’allocation échoue, la fonction renvoie NULL
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!size)
		return (0);
	ptr = (void *)malloc(sizeof(*ptr) * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size);
	return (ptr);
}
