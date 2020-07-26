NAME = cub3d
CC = gcc -g
#FLAGS = -Wall -Wextra -Werror
LIB = -I ./mlx

SRC = cub3d.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) $(LIB) -c $< -o $@

clean:
		/bin/rm $(OBJ)

fclean:
		/bin/rm $(OBJ) $(NAME)

re:		fclean all