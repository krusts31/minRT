NAME = parcer

SRC = ../gnl/get_next_line.c ../gnl/get_next_line_utils.c main.c camera.c \
	camera2.c utils.c utils2.c utils3.c utils4.c parce.c Amb.c Res.c \
	light.c light2.c sphere.c sphere2.c plane.c plane2.c squar.c \
	squar2.c triangle.c triangle2.c cylinder.c cylinder2.c

SRC_OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

HEADER = parcer.h

all: $(NAME)

$(NAME): $(SRC_OBJ)
	make -C ../libft
	clang  $(CFLAGS) -L../libft -lft $(SRC) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	@/bin/rm -f $(SRC_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
