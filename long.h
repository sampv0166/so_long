#ifndef LONG_H
# define LONG_H

# include"./mlx/mlx.h"
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>

# define TILES 100
# define PATH_E "./assets/empty.xpm"
# define PATH_P "./assets/player.xpm"
# define PATH_P2 "./assets/player2.xpm"
# define PATH_P3 "./assets/player3.xpm"
# define PATH_P4 "./assets/player4.xpm"
# define PATH_P5 "./assets/player5.xpm"
# define PATH_P6 "./assets/player6.xpm"
# define PATH_P7 "./assets/player7.xpm"
# define PATH_P8 "./assets/player8.xpm"
# define PATH_P9 "./assets/player9.xpm"
# define PATH_EX_OPEN "./assets/exit_open.xpm"
# define PATH_M1 "./assets/alien1.xpm"
# define PATH_M2 "./assets/alien2.xpm"
# define PATH_M3 "./assets/alien3.xpm"
# define PATH_C "./assets/collect.xpm"
# define PATH_W "./assets/wall.xpm"
# define PATH_EX "./assets/exit.xpm"

typedef struct s_position
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_data
{
	void	*img_p[10];
	void	*img_m[3];
	void	*img;
	char	*pixel;
	t_pos	pos;
	t_pos	size;
	int		bpp;
	int		line_size;
	int		endian;
}			t_data;

typedef struct s_img
{
	t_data	wall;
	t_data	emp;
	t_data	exit;
	t_data	player;
	t_data	item;
	t_data	enemy;
	t_data	exit_open;
	t_data	monster;
}			t_img;

typedef struct s_map
{
	t_pos		player;
	t_pos		monster;
	size_t		colum;
	size_t		line;
	char		**map;
}				t_map;

typedef struct s_zomb
{
	int		zomb_x;
	int		zomb_y;
	int		direction;
}	t_zomb;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		steps;
	int		side;
	int		collect_count;
	int		exit_x;
	int		exit_y;
	int		sprite_count;
	int		img_count;
	int		enemy_sprite_count;
	int		enemy_img_count;
	int		zomb_count_save;
	int		zomb_count;
	char	*steps_string;
	t_zomb	*zombis;

}				t_game;

int		close_win(t_game *game);
int		key_hook(int keycode, t_game *game);
char	**ft_split(char const *str, char c);
size_t	ft_strlen(const char *s);
char	**get_map(t_game *game, int argc, char **av);
char	*read_file(t_game *game, int i, char **av);
char	*ft_itoa(int n, char *s);
void	error(void);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *str, size_t n);
void	*ft_memset(void *ptr, int x, size_t n);
void	free_me(char **str);
char	*allocate_memmory(char *s);
void	init_game(t_game *game);
void	init_images(t_game *game);
void	init_player_image(t_game *game);
int		init_sprites(t_game *game);
int		init_enemy_sprites(t_game *game);
void	replace_image(t_game *game, int x, int y);
void	reset_map_and_update_player_pos(t_game *game, int x, int y);
void	update_steps(t_game *game);
void	move_player(t_game *game, int x, int y);
int		action(int keycode, t_game *game);
void	draw_map(t_game *game);
void	print_10p(t_game *game, int line, int col);
void	print_ec(t_game *game, int line, int col);
void	move_zombi(t_game *game, int i);

#endif