/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/24 02:28:18 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define DEBUG { ft_putstr(__func__); ft_putstr(" - line: "); ft_putnbr(__LINE__); \
		ft_putstr("\n"); } //ToDEL
# define ARG_ERROR { ft_putendl("Usage : height, width, speed, player1 name, player2 name"); exit(0); }
# define GAK_ERROR_A { perror("Oh oh"); exit(1); }
# define GAK_ERROR_B { perror("Oh oh"); exit(2); }
# define GAME_OVER { ft_putendl("GAME OVER"); highscore(e); exit(0); }
# define YAY { ft_putendl("YAY"); exit(0); }
# include "libft/inc/libft.h"
# include <fcntl.h>
# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# include <math.h>
#include <sys/ioctl.h>
typedef struct s_env	t_env;
struct s_env
{
	int		he;
	int		wi;
	int		sp;
	int     bonus;
	t_lst	*first_l;
	t_lst	*last_l;

	t_lst	*snake1;
	t_lst	*end1;	
	char	*player1;
	int     way1; //1=left, 2=up, 3=down, 4=right
	int     score;

	t_lst   *snake2;
    t_lst   *end2;
    char    *player2;
    int     way2; //q=left, z=up, s=down, d=right
};
void    print_map(t_env *e);
int rand_a_b(int a, int b, int seed);
void push_key(t_env *e);
void init_list(t_env *e);
int getarrowkey(void);
t_lst   *free_spot(t_env *e, int seed);
void    highscore(t_env *e);
void move1(t_env *e);
void move2(t_env *e);
#endif
