cmake_minimum_required(VERSION 3.9)
project(fdf)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/libft/includes)
include_directories(${CMAKE_SOURCE_DIR}/includes)

add_executable(fdf
        src/main.c
        src/fdf_draw_map.c
        src/fdf_init_map_matrix.c
        src/fdf_read_map.c
        src/fdf_rotate.c
        src/graphics
        src/hooks.c
      #  src/swap_points.c
        src/fdf_get_result_map.c
        src/fdf_rotate.c
        src/fdf_map_point_colors.c
        src/hooks2.c

        src/graphics/additional_functions.c
       # src/graphics/draw_line.c
        src/graphics/init_img_struct.c
        src/graphics/put_pixel_to_img.c
        src/graphics/rgb_get_color.c
        src/graphics/rgb_get_rvalue.c
        src/graphics/draw_gradient_line.c
       # src/graphics/get_fraction.c
        src/graphics/init_mlx_and_img.c
        src/graphics/rgb_get_bvalue.c
        src/graphics/rgb_get_gvalue.c


        Makefile)

add_library(libft STATIC IMPORTED) # Создание статической библиотеки
set_property(TARGET libft PROPERTY
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(fdf libft)  # Линковка программы с библиотекой

find_library(_mlx mlx)
find_library(_m m)
find_library(_openGL OpenGL)
find_library(_appkit AppKit)

target_link_libraries(fdf ${_mlx})
target_link_libraries(fdf ${_m})
target_link_libraries(fdf ${_openGL})
target_link_libraries(fdf ${_appkit})

set(TARGETS test_maps/42.fdf)


