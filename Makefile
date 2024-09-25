CFILES =	src/main.c \

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -g
LDFLAGS = -L$(LIBFT_DIR) -lft -lreadline
MLXFLAGS = -L $(MLX)/build -lmlx42 -ldl -L /usr/local/lib/ -lglfw -pthread -lm
OBJ_DIR = Obj
OFILES = $(addprefix $(OBJ_DIR)/,$(notdir $(CFILES:.c=.o)))

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX = lib/MLX42

$(NAME): $(LIBFT) $(OBJ_DIR) $(OFILES)
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
	@$(CC) $(OFILES) $(LDFLAGS) $(MLXFLAGS) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	clear
	@$(MAKE)	loading
	clear


$(OBJ_DIR)/%.o: src/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: src/builtins/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)



loading:
	@for i in {1..42}; do \
		printf '%s' "██"; \
		sleep 0.01; \
	done

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(OFILES)
	@make -C $(LIBFT_DIR) clean
	@echo "\033[90mclean\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@echo "\033[90mand\033[0m"
	@echo "\033[90mfclean\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re, loading, libft
