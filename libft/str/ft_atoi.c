/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:19:53 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/10 17:14:45 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The atoi() function converts the initial portion of the string  pointed
**   to by nptr to int.
*/

#include "libft.h"

int		ft_atoi(char *str)
{
	int		sign;
	int		num;

	sign = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = 42;
	if (*str == '-' || *str == '+')
		str++;
	num = 0;
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (sign)
		num = -num;
	return (num);
}
