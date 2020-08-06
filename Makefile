NAME = cub3d
CC = gcc -g
#FLAGS = -Wall -Wextra -Werror
LIB = -I ./mlx
HEADER = headers/cub3d.h headers/ft_trace.h

SRC = srcs/cub3d.c \
		srcs/parce_map_file.c \
		srcs/ft_sprite_list_1.c \
		srcs/ft_create_bitmap.c \
		srcs/ft_trace.c \
		srcs/ft_draw_world.c \
		srcs/ft_init_struct.c \
		srcs/ft_draw_sprite.c \
		srcs/ft_sprite_list_2.c \
		srcs/ft_replace_frame.c \
		srcs/ft_key_press.c \
		srcs/ft_utils.c

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