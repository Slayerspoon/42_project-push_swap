# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 21:32:34 by aionescu          #+#    #+#              #
#    Updated: 2021/11/13 19:18:29 by aionescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

SRC = error_check.c ft_strtonum.c operations_a.c operations_b.c \
		push_swap_utils_i.c push_swap_utils_ii.c push_swap_upto_3.c \
		push_swap_upto_5.c push_swap_unlimited_v6.c main.c

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) -Wall -Wextra -Werror $(SRC) $(LIBFT) -o $(NAME)
	rm -f *.o
	chmod 777 $(NAME)

$(LIBFT):
	cd libft && $(MAKE) fclean
	cd libft && $(MAKE)
	mv ./libft/libft.a libft.a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
