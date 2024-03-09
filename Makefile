# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macampos <mcamposmendes@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 13:08:10 by macampos          #+#    #+#              #
#    Updated: 2024/03/06 13:13:38 by macampos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PHILO

SRC =

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = CC

$(NAME): $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)