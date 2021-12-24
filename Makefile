SRC_NAME  = draw_map.c \
			ft_itoa.c	\
			ft_split.c	\
			ft_split2.c	\
			helper_functions.c \
			init_game.c \
			map_validation.c \
			mov_player.c \
			read_map_file.c \
			move_zombi.c \
			main.c

BNS_SRC_NAME  = draw_map_bonus.c \
			ft_itoa_bonus.c	\
			ft_split_bonus.c	\
			ft_split2_bonus.c	\
			helper_functions_bonus.c \
			init_game_bonus.c \
			map_validation_bonus.c \
			mov_player_bonus.c \
			read_map_file_bonus.c \
			move_zombi_bonus.c \
			main_bonus.c

OBJ_NAME = $(SRC_NAME:.c=.o)
BNS_OBJ_NAME = $(BNS_SRC_NAME:.c=.o)
CC			=	gcc
CFLAGS   = -Wall -Wextra -Werror 
MLX_FLAGS  =./mlx/libmlx.a -framework OpenGL -framework AppKit
NAME 	 = so_long
BNS_NAME 	 = so_long_bonus

all: $(NAME)

bonus: $(BNS_NAME)

$(NAME):  	$(OBJ_NAME)
			$(MAKE) -C ./mlx
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ_NAME) -o $(NAME)		

$(BNS_NAME): $(BNS_OBJ_NAME)
			$(MAKE) -C ./mlx
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(BNS_OBJ_NAME) -o $(BNS_NAME)	

clean	:
		  rm -rf $(OBJ_NAME)
		  rm -rf $(BNS_OBJ_NAME)	 

fclean	: clean
		  rm -rf $(NAME)
		  rm -rf $(BNS_NAME)
		  $(MAKE) clean -C ./mlx
		  rm -rf ./mlx/libmlx.a

re		: fclean all
 