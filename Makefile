NAME = cub3d
CC = gcc -g
FLAGS = -Wall -Wextra -Werror
LIB = -I ./mlx
HEADER = headers/cub3d.h

SRC = srcs/cub3d.c \
		srcs/ft_parce_map_file_1.c \
		srcs/ft_parce_map_file_2.c \
		srcs/ft_parce_map_file_3.c \
		srcs/ft_parce_map_file_4.c \
		srcs/ft_sprite_list_1.c \
		srcs/ft_create_bitmap.c \
		srcs/ft_trace.c \
		srcs/ft_draw_world.c \
		srcs/ft_init_struct.c \
		srcs/ft_draw_sprite.c \
		srcs/ft_sprite_list_2.c \
		srcs/ft_replace_frame.c \
		srcs/ft_key_press.c \
		srcs/ft_utils.c \
		srcs/ft_lst_in_map.c \
		srcs/ft_utils_2.c \
		srcs/ft_free_all_struct.c

OBJ = $(SRC:.c=.o)

%.o: %.c
		$(CC) $(FLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) libft mlx
		cp ./mlx/libmlx.dylib ./
		$(CC) -Lmlx ./libft/libft.a -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

libft:
		$(MAKE) -C libft

mlx:
		$(MAKE) -C mlx

clean:
		/bin/rm -rf $(OBJ)
		$(MAKE) -C libft clean
		$(MAKE) -C mlx clean

fclean:
		/bin/rm -rf $(OBJ) $(NAME)
		/bin/rm -rf libmlx.dylib
		$(MAKE) -C mlx clean
		$(MAKE) -C libft fclean

re:		fclean all

.PHONY: clean fclean all re libft mlx
