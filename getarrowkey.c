/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarrowkey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 18:39:07 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/24 02:12:43 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return value:
** 0 si l'utilisateur n'appuye sur rien.
** 1 si l'utilisateur appuye sur Fleche de gauche.
** 2 si l'utilisateur appuye sur Fleche du haut.
** 3 si l'utilisateur appuye sur Fleche du bas.
** 4 si l'utilisateur appuye sur  fleche de droite.
** (cf : a utiliser dans une boucle infinie, voir main d'exemple)
*/

#include "header.h"
#include <sys/termios.h>
#include <termios.h>

static int kbhit(void)
{
	//DEBUG; //debug
	struct termios	oldt;
	struct termios	newt;
	int				ch;
	int				oldf;
 
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if(ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}
	return 0;
}

int getarrowkey(void)
{
	//DEBUG; //debug
	struct termios	line_police;
	char			c;

	if (ioctl(0, TIOCGETD, &line_police) < 0)
		GAK_ERROR_A;
	if (line_police.c_lflag &= ~(ICANON | ECHO))
		if ((ioctl(0, TIOCSETD, &line_police)) < 0)
			GAK_ERROR_B;
	if (kbhit())
	{
		while ((c = fgetc(stdin)))
		{
			if (c == 68)
				return (1);
			else if (c == 65)
				return (2);
			else if (c == 66)
				return (3);
			else if (c == 67)
				return (4);
			else if (c == 'q')
                return (5);
			else if (c == 'z')
                return (6);
			else if (c == 's')
                return (7);
			else if (c == 'd')
                return (8);
		}
	}
	return (0);
}
