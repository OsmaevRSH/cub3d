cmake_minimum_required(VERSION 3.16)
project(cub3d)

set (CMAKE_C_FLAGS "-L. -lmlx -framework OpenGL -framework AppKit")

include_directories(.)
include_directories(mlx)

add_executable(cub3d
        mlx/man/man3/mlx.3
        mlx/man/man3/mlx_loop.3
        mlx/man/man3/mlx_new_image.3
        mlx/man/man3/mlx_new_window.3
        mlx/man/man3/mlx_pixel_put.3
        mlx/font.c
        mlx/interface.o
        mlx/interface.swift
        mlx/libmlx.dylib
        mlx/Makefile
        mlx/mlx.h
        mlx/mlx_image.o
        mlx/mlx_image.swift
        mlx/mlx_image.swiftdoc
        mlx/mlx_image.swiftmodule
        mlx/mlx_init.o
        mlx/mlx_init.swift
        mlx/mlx_init.swiftdoc
        mlx/mlx_init.swiftmodule
        mlx/mlx_png.c
        mlx/mlx_png.o
        mlx/mlx_rgb.c
        mlx/mlx_string_put.c
        mlx/mlx_string_put.o
        mlx/mlx_window.o
        mlx/mlx_window.swift
        mlx/mlx_window.swiftdoc
        mlx/mlx_window.swiftmodule
        mlx/mlx_xpm.c
        mlx/mlx_xpm.o
        CMakeLists.txt
        cub3d.c
        cub3d.h
        Makefile
        README.md parce_map_file.c libft/ft_isdigit_from_string.c libft/ft_check_file_extension.c ft_sprite_list.c ft_create_bitmap.c ft_trace.c ft_trace.h ft_draw_world.c)
