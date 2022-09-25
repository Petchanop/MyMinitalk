# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 17:56:41 by npiya-is          #+#    #+#              #
#    Updated: 2022/09/25 23:17:34 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk
SERVER	= server
CLIENT	= client
PRINTF = printf

PRINTF_DIR = ft_printf

SRCSSERVER	= minitalk_server.c \

SRCSCLIENT	= minitalk_client.c \

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra
RM	= rm -f

SERVER_OBJS	= $(SRCSSERVER:.c=.o)
CLIENT_OBJS	= $(SRCSCLIENT:.c=.o)

all:$(NAME)

$(NAME):$(PRINTF) $(SERVER) $(CLIENT) 

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -L$(PRINTF_DIR) -lftprintf -o $(SERVER) 

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -L$(PRINTF_DIR) -lftprintf -o $(CLIENT)

clean:
	@make -C ft_printf clean
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	@make -C ft_printf fclean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: norminette all re fclean clean
