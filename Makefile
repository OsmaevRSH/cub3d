NAME = cub3d
CC = gcc -g
#FLAGS = -Wall -Wextra -Werror
LIB = -I ./mlx
HEADER = ./cub3d.h

SRC = cub3d.c parce_map_file.c ft_sprite_list_1.c ft_create_bitmap.c ft_trace.c ft_draw_world.c ft_init_struct.c ft_draw_sprite.c \
		ft_sprite_list_2.c ft_replace_frame.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft:
		$(MAKE) -C libft

$(NAME): $(OBJ) libft
		$(CC) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(FLAGS) $(LIB) -c $< -o $@

clean:
		/bin/rm $(OBJ)
		$(MAKE) -C libft clean

fclean:
		/bin/rm $(OBJ) $(NAME)
		$(MAKE) -C libft fclean


re:		fclean all

.PHONY: clean fclean all re libft