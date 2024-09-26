CFILES =	src/main.c

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -g
OBJ_DIR = Obj
OFILES = $(addprefix $(OBJ_DIR)/,$(notdir $(CFILES:.c=.o)))

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I $(LIBFT_DIR)

REPO_URL = https://github.com/codam-coding-college/MLX42
REPO_DIR = lib/MLX42
BUILD_DIR = $(REPO_DIR)/build
MLX42_LIB = $(BUILD_DIR)/libmlx42.a
MLX42_INCLUDES = -I $(REPO_DIR)/include

FRAMEWORKS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

all: $(NAME)

$(REPO_DIR):
	@echo "Cloning MLX42 repository"
	@git clone $(REPO_URL) $(REPO_DIR)

$(BUILD_DIR): $(REPO_DIR)
	@echo "Building MLX42 with CMake"
	@cmake -B $(BUILD_DIR) -S $(REPO_DIR)

$(MLX42_LIB): $(BUILD_DIR)
	@echo "Building MLX42"
	@make -C $(BUILD_DIR)

$(NAME): $(MLX42_LIB) $(OFILES) $(LIBFT) 
	@echo "Linking $(NAME)"
	@$(CC) $(OFILES) $(LIBFT) $(MLX42_LIB) -o $(NAME) $(FRAMEWORKS)
	clear
	@$(MAKE) loading
	clear

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@echo "Compiling $<"
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "Building Libft"
	@make -C $(LIBFT_DIR)

loading:
	@for i in {1..42}; do \
		printf '%s' "██"; \
		sleep 0.01; \
	done
	@echo ""

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "\033[90mclean\033[0m"
	@rm -rf $(REPO_DIR)  # Clean MLX42 build directory

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[90mfclean\033[0m"

re: fclean all

.PHONY: all clean fclean re loading libft mlx42
