SRC_NAME  = draw_map.c \
			ft_itoa.c	\
			ft_split.c	\
			ft_split2.c	\
			helper_functions.c \
			init_game.c \
			map_validation.c \
			move_player.c \
			read_map_file.c \
			main.c
CFLAGS   = -Wall -Wextra -Werror
MLX_FLAGS  =-L./mlx -lmlx -framework OpenGL -framework AppKit
NAME 	 = so_long
MLX_PATH = ./mlx

all: ${NAME}

${NAME}: gcc $(CFLAGS) $(MLX_FLAGS) $(SRC_NAME) -o $(NAME)



