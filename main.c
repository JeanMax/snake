/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 18:31:42 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/28 13:55:45 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ceci est un main...
*/

#include "header.h"


static int get_all(int const fd, char **a)
{
	int i;
	char buf[1024];

	if (!a || fd < 0)
		return (0);
	*a = ft_strnew(1);
	while ((i = read(fd, buf, 1024)) > 0)
	{
		buf[i] = '\0';
		*a = (char *)ft_realloc((void *)*a, ft_strlen(*a), ft_strlen(*a) + i);
		ft_strcat(*a, buf);
	}
	if (!*a || i < 0)
		return (0);
	return (1);
}

void	highscore(t_env *e)
{
	int	fd;
	char *previous;
	char *useless;

	fd = open("highscore", O_RDWR);
	get_all(fd, &previous);
	if (ft_atoi(previous) > e->score)
	{
		ft_putnbr_fd(e->score, fd);
		ft_putstr_fd(" ", fd);
		ft_putstr_fd(e->player1, fd);
		ft_putstr_fd("&", fd);
		ft_putstr_fd(e->player2, fd);
		ft_putstr_fd(" (in ", fd);
		ft_putnbr_fd(e->wi, fd);
		ft_putstr_fd("x", fd);
		ft_putnbr_fd(e->he, fd);
		ft_putstr_fd(" at ", fd);
		ft_putnbr_fd(e->sp, fd);
		ft_putendl_fd("ms/fps)", fd);
	}
	else
	{
		close(fd);
		fd = open("highscore", O_WRONLY);
		ft_putnbr_fd(e->score, fd);
        ft_putstr_fd(" ", fd);
        ft_putstr_fd(e->player1, fd);
		ft_putstr_fd("&", fd);
        ft_putstr_fd(e->player2, fd);
        ft_putstr_fd(" (in ", fd);
        ft_putnbr_fd(e->wi, fd);
        ft_putstr_fd("x", fd);
        ft_putnbr_fd(e->he, fd);
        ft_putstr_fd(" at ", fd);
        ft_putnbr_fd(e->sp, fd);
        ft_putendl_fd("ms/fps)", fd);
		get_all(fd, &useless);
		ft_putstr_fd(previous, fd);

	}
	close(fd);
	fd = open("highscore", O_RDWR);
	get_all(fd, &previous);
	ft_putendl(previous);
}

int main(int argc, char **argv)
{
	//DEBUG; //debug
	t_env	e;
	t_lst	*tmp;

	if (argc != 6)
		ARG_ERROR;
	e.he = ft_atoi(argv[1]);
	e.wi = ft_atoi(argv[2]);
	e.sp = ft_atoi(argv[3]);
	e.score = 0;
	e.player1 = argv[4];
	e.player2 = argv[5];
	e.first_l = NULL;
	init_list(&e);
	tmp = free_spot(&e, 2);
	tmp->z = 2; //adding snake
	e.snake1 = tmp;
	e.end1 = e.snake1;
	tmp = free_spot(&e, 2);
    tmp->z = 2; //adding snake
    e.snake2 = tmp;
    e.end2 = e.snake2;
	tmp = free_spot(&e, 3);
	tmp->z = 3; //adding food
	print_map(&e);
	push_key(&e);
	return (0);
}
