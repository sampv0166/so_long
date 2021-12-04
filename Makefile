NAME = so_long.a

SRC_NAME = main.c 

OBJE_NAME = $(SRC_NAME:.c=.O)
FLAG = -Wall -Wextra -Werror
DBG_FLAGS = -framework openGl -framework AppKit

.PHONY:all clean fclean re

all:$(NAME)

LIBFT_LOCATION = ./libft
MINILIB_LOCATIION = ./minilib

LIBFT_LIB = ./libft/libft.a
MINI_LIB = ./minilibx/libmlx.a

${NAME}:${OBJ_NAME}
		$(MAKE) -C $(LIBFT_LOCATION) all
		$(MAKE) -C $(MINILIB_LOCATIION) all
		gcc -c $(FLAG) $(SRC_NAME)
		ar -r $(NAME) $(OBJ_NAME)
		libtool -static -o $(NAME) $(MINI_LIB $(LIBFT_LIB) $(NAME)

clean:
	rm -rf $(OBJ_NAME)
	$(MAKE) -c $(LIBFT_LOCATION) clean
	$(MAKE) -c $(MINILIB_LOCATIION) clean

fclean:clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB) $(MINI_LIB)

re:fclean all



