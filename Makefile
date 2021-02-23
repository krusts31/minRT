# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts <alkrust@student.codam.nl>          +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 16:50:00 by alkrusts      #+#    #+#                  #
#    Updated: 2020/12/28 14:11:27 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =miniRT

ifdef DEBUG
	CASE = debug
	CFLAGS =-Wall -Werror -Wextra -g -fsanitize=address
else ifdef FAST
	CASE = fast
	CFLAGS =-Wall -Werror -Wextra -O3
else
	CASE = 
	CFLAGS =-Wall -Werror -Wextra
endif

SRC = src/utils/Amb.c \
	src/utils/cylinder.c \
	src/utils/utils.c \
	src/utils/Res.c \
	src/utils/cylinder2.c \
	src/utils/light.c \
	src/utils/sphere2.c \
	src/utils/utils2.c \
	src/utils/camera.c \
	src/utils/light2.c \
	src/utils/plane.c \
	src/utils/squar.c \
	src/utils/triangle.c \
	src/utils/utils3.c \
	src/utils/camera2.c \
	src/utils/get_task.c \
	src/utils/parce.c \
	src/utils/plane2.c \
	src/utils/squar2.c \
	src/utils/triangle2.c \
	src/utils/utils4.c \
	src/utils/colors.c \
	src/utils/hit_list.c \
	src/utils/ray.c \
	src/utils/vector.c \
	src/utils/vector_2.c \
	src/utils/free_render.c \
	src/utils/pixel.c \
	src/utils/sphere.c \
	src/utils/sphere3.c \
	src/utils/vector_1.c \
	src/utils/get_next_line.c \
	src/utils/get_next_line_utils.c \
	src/utils/sphereCore.c \
	src/utils/cameraCore.c \
	src/utils/print_res.c \
	src/utils/colors2.c \
	src/utils/camera3.c \
	src/utils/utils5.c \
	src/utils/main.c 

SRC_OBJ = $(SRC:.c=.o)

LIBFT =-Lsrc/libs/libft -lft

MINLIB =-Lsrc/libs/minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC_OBJ)
	make -C src/libs/libft
	$(CC) $(CFLAGS) $(LIBFT) $(MINLIB) $(SRC_OBJ) -o $(NAME)
%.o: %.c
	$(CC) -c $(CFLAGS) -Imlx -o $@ $<

debug: fclean
	make debug -C src/libs/libft
	make DEBUG=1

fast: fclean
	make fast -C src/libs/libft
	make FAST=1
clean:
	rm -rf $(SRC_OBJ)	
	make clean -C src/libs/libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C src/libs/libft

re: fclean all
