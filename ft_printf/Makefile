# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 17:56:41 by npiya-is          #+#    #+#              #
#    Updated: 2022/08/10 16:29:59 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
LIBC = libft.a

INCS_DIR = ./srcs/include
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/$(LIBC)

BUILD_DIR = build
SRC_DIR = ./srcs
SRCS = ft_printf.c \
       ft_printf_format.c \
       ft_printf_format2.c \
       ft_printf_utils.c \
       ft_printf_utils2.c \
       ft_format_placeholder.c \
       ft_scan_placeholder.c \
       ft_putstr_utils.c \
       ft_putstr_utils2.c \

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all:$(NAME)

$(NAME):$(OBJS) $(LIBFT)
	@ar rc $(NAME) $(OBJS)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	@make bonus -C  $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

bonus: all

clean:
	@make clean -C $(LIBFT_DIR)
	rm -rf $(BUILD_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)

re: fclean all
