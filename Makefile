NAME = fdf
CC = gcc
FLAGS = -Wall -Werror -Wextra
O_FILES = $(addprefix $(OBJ_DIR)/, $(C_FILES:src/%.c=%.o))
C_FILES = $(addprefix $(SRC_DIR)/, main.c init_img_struct.c init_mlx_and_img.c \
			put_pixel_to_img.c draw_line.c fdf_change_alpha_in_argb.c fdf_get_argb.c \
			get_fraction.c swap_points.c hooks.c)
OBJ_DIR = objects
SRC_DIR = src
INCLUDES = -lmlx -lm -L./libft -lft -framework OpenGL -framework AppKit -I includes/ -I libft/includes
map = test

all: $(NAME)
$(NAME): $(OBJ_DIR) $(O_FILES)
	@$(MAKE) -C libft
	@$(CC) $(FLAGS) $(O_FILES) -o $(NAME) $(INCLUDES)
	@echo "\033[34m$(NAME) compiled\033[0m"
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -o $@ -c $<
clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJ_DIR)
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
re: fclean all
run:
	@make
	./fdf $(map)