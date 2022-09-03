# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 15:21:17 by npiya-is          #+#    #+#              #
#    Updated: 2022/09/04 00:44:35 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = minitalk_server.c

NAME = server

$(NAME):$(SRCS)
	@make -C ../ft_printf
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -L ../ft_printf -lftprintf -I ../.

fclean:
	rm -rf $(NAME)

re:fclean $(NAME)
