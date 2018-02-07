NAME = fdf
CC = gcc
FLAGS = -Wall -Werror -Wextra
O_FILES = $(addprefix $(OBJ_DIR)/, $(C_FILES:src/%.c=%.o))
C_FILES = $(addprefix $(SRC_DIR)/, main.c init_img_struct.c init_mlx_and_img.c \
			put_pixel_to_img.c)
OBJ_DIR = objects
SRC_DIR = src
INCLUDES = -lmlx -lm -framework OpenGL -framework AppKit -I includes/

all: $(NAME)
$(NAME): $(OBJ_DIR) $(O_FILES)
	$(CC) $(FLAGS) $(O_FILES) -o $(NAME) $(INCLUDES)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -o $@ -c $<
clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean
	make
run:
	@make
	./fdf