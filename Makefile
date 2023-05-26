NAME=get_next_line

CC=gcc

CFLAGS=-Wall -Wextra -Werror

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
