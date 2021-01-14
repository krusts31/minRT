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

NAME = a.out

CFLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

LIB = -Lminilibx -lmlx -framework OpenGL -framework AppKit
PRINTF = -Lft_printf -lftprintf

SRC = main.c gnl/get_next_line.c gnl/get_next_line_utils.c pixel.c circle.c \
	square.c triangle.c hexagon.c

SRC_OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	make -C ft_printf
	gcc $(CFLAGS) $(LIB) $(PRINTF) $(SRC) -o $(NAME) -g -I .

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ -g

clean:
	make clean -C ft_printf
	@/bin/rm -f $(SRC_OBJ)

fclean: clean
	make fclean -C ft_printf
	@/bin/rm -f $(NAME)

re: fclean all
