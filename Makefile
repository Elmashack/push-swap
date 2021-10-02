# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nluya <nluya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 20:43:42 by nluya             #+#    #+#              #
#    Updated: 2021/10/02 16:32:17 by nluya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BON = checker

FLAGS = -Wall -Wextra -Werror

SRC = push_swap.c utils.c algorithm.c swap.c sort_less_five.c push_to_a.c count_step.c index.c reverse.c rotate.c utils_for_checker.c push.c

SRC_BON = checker.c utils.c algorithm.c swap.c sort_less_five.c push_to_a.c count_step.c index.c reverse.c rotate.c utils_for_checker.c push.c

OBJ = $(SRC:%.c = %.0)

OBJ_BON = $(SRC_BON:%.c = %.0)

LIB = libft/libft.a

HEADER = push_swap.h


all: $(NAME)
 
$(NAME): lib
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB)

bonus: lib
	gcc $(FLAGS) -o $(NAME_BON) $(SRC_BON) $(LIB)
	

lib:
	@make -C libft/

clean:
	@make -C libft/ clean

fclean: clean
	rm -rf $(NAME) $(NAME_BON)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
