cmake_minimum_required(VERSION 3.16)
project(cub3d)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)
include_directories(mlx)

add_executable(cub3d
        mlx/man/man3/mlx.3
        mlx/man/man3/mlx_loop.3
        mlx/man/man3/mlx_new_image.3
        mlx/man/man3/mlx_new_window.3
        mlx/man/man3/mlx_pixel_put.3
        mlx/font.c
        mlx/interface.swift
        mlx/libmlx.dylib
        mlx/Makefile
        mlx/mlx_image.swift
        mlx/mlx_init.swift
        mlx/mlx_png.c
        mlx/mlx_rgb.c
        mlx/mlx_string_put.c
        mlx/mlx_window.swift
        mlx/mlx_xpm.c
        cub3d
        cub3d.c
        cub3d.h
        cub3d.o
        Makefile
        README.md)

target_link_libraries(cub3d
        "-framework AppKit"
        "-framework OpenGL"
        mlx
        )