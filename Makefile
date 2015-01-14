#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2014/12/24 02:14:31 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = snake

SRCC =  main.c getarrowkey.c list.c print.c move.c move1.c move2.c

SRCO = zboub

FLAG = -Wall -Werror -Wextra

.PHONY: all lib brute clean fclean re

all: $(NAME)

$(NAME):
	@rm -f $(NAME)
	@gcc $(FLAG) $(SRCC) -o $(NAME) -I ./libft/inc/ -I ./ libft/libft.a

lib:
	@cd libft; make re; cd ..

brute: lib all

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean all
