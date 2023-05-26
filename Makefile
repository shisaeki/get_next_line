NAME=get_next_line

SRCS=main.c \
		get_next_line.c \
		get_next_line_utils.c \

INCLUDES=get_next_line.h \

all: $(NAME)

$(NAME): $(SRCS)
	gcc -o $(NAME) -I $(INCLUDES) $(SRCS)
clean:
	rm -f $(NAME)
re: clean all
