NAME = parcer

SRC = ../gnl/get_next_line.c ../gnl/get_next_line_utils.c main.c camera.c \
	camera2.c utils.c

SRC_OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

HEADER = parcer.h

all: $(NAME)

$(NAME): $(SRC_OBJ)
	make -C ../libft
	clang  $(CFLAGS) -L../libft -lft $(SRC) -o $(NAME) -g

%.o: %.c 
	$(CC) $(CFLAGS)  -c $< -o $@ -g

clean:
	@/bin/rm -f $(SRC_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
