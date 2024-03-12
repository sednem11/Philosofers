# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macampos <macampos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 13:08:10 by macampos          #+#    #+#              #
#    Updated: 2024/03/11 17:38:25 by macampos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PHILO

SRC = philo.c main.c routine.c utils.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = cc

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean: rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re