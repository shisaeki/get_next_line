# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shisaeki <shisaeki@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 17:53:24 by shisaeki          #+#    #+#              #
#    Updated: 2023/05/28 14:24:31 by shisaeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=get_next_line

CC=gcc

CFLAGS=-g -Wall -Wextra -Werror

SRCS=main.c \
		get_next_line.c \
		get_next_line_utils.c \

INCLUDES=get_next_line.h \

MEMORY_CHECK=-g -fsanitize=address

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) -I $(INCLUDES) $(SRCS)
mc:
	$(CC) $(CFLAGS) -o $(NAME) $(MEMORY_CHECK) -I $(INCLUDES) $(SRCS)
clean:
	rm -f $(NAME)
re: clean all
