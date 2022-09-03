# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <npiya-is@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 22:33:02 by npiya-is          #+#    #+#              #
#    Updated: 2022/06/30 00:13:12 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = minitalk_client.c

SRCS2 = test.c

NAME = client

NAME2 = test

$(NAME):$(SRCS)
	make -C ../ft_printf
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -L ../ft_printf -lftprintf -I ../.

$(NAME2):$(SRCS2)
	make -C ../ft_printf
	$(CC) $(CFLAGS) -o $(NAME2) $(SRCS2) -L ../ft_printf -lftprintf -I ../.

fclean:
	rm -rf $(NAME)

re:fclean $(NAME)