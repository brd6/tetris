/*
** my.h for tetris in /home/franco_k/Projets/PSU/PSU_2015_tetris/include
**
** Made by Matthieu FSC
** Login   <franco_k@epitech.net>
**
** Started on  Mon Feb 22 13:16:46 2016 Matthieu FSC
** Last update Sat Apr 29 11:07:05 2017 root
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# define GET_MAX(nb1, nb2) ((nb1 > nb2) ? (nb1) : (nb2))
# define TEST_SPACE(str) (str[0] == ' ' ? ("(space)") : (str))
# define OPTIONS_NB_MAX 12
# define OPTION_ERROR_FORMAT "Options: Format error\n"
# define OPTION_ERROR_MALLOC "Options: Malloc error\n"
# define WINDOW_SIZE_ERROR "The window's size is too small. Please extend it\n"
# define NO_COLOR_ERROR "Your terminal does not support color\n"
# define TERM_VAR_NOFOUND "TERM variable is not found on your environnment\n"
# define TERM_SETUP_FAIL "Unable to setup the new term\n"
# define TERM_SETUP_FAIL2 "Unable to get the term's attributs\n"
# define TETRIMINO_GRID_SIZE_ERROR "The map size is too small for tetriminos\n"
# define TETRIMINOS_DIRECTORY "./tetriminos"
# define COLOR_COLOR_BLACK 0
# define COLOR_COLOR_RED 1
# define COLOR_COLOR_GREEN 2
# define COLOR_COLOR_YELLOW 3
# define COLOR_COLOR_BLUE 4
# define COLOR_COLOR_MAGENTA 5
# define COLOR_COLOR_CYAN 6
# define COLOR_COLOR_WHITE 7
# define MAX_LEVEL 99
# define GAME_SPEED 500
# define GAME_SPEED_2 18000
# define GAME_RUN_SPEED 15
# define NB_TETRIMINOS_SHAPE 5
# define HIGHT_SCORE_FILENAME "hight_score.save"
# define TETRIMINOS_FILE_EXT ".tetrimino"

# include <curses.h>
# include <term.h>

typedef struct	s_option
{
  char		*key;
  char		*key_l;
  int		(*init)(char *value, char *key_l);
}		t_option;

typedef struct	s_gamepad
{
  char		*user_key_left;
  char		*user_key_right;
  char		*user_key_turn;
  char		*user_key_drop;
  char		*user_key_quit;
  char		*user_key_pause;
}		t_gamepad;

typedef struct	s_point
{
  int		x;
  int		y;
}		t_point;

typedef struct	s_tetriminos
{
  int		***shape;
  int		color;
  t_point	top_left;
  int		size;
  t_point	grid;
}		t_tetriminos;

typedef struct		s_tetris
{
  SCREEN		*screen_main;
  WINDOW		*win_score;
  WINDOW		*win_board;
  WINDOW		*win_board_debug;
  WINDOW		*win_next_preview;
  t_gamepad		gamepad;
  t_point		map_size;
  t_option		options[OPTIONS_NB_MAX];
  int			without_next;
  int			enable_debug;
  int			enable_help;
  int			level;
  int			score;
  int			line;
  int			high_score;
  long			game_timer;
  int			game_tick;
  int			game_run;
  int			game_over;
  int			**gameboard;
  int			nb_tetriminos;
  t_tetriminos		*tetriminos;
  int			curr_shape;
  int			curr_tetriminos;
  int			next_tetriminos;
  char			*term_name;
  struct termios	user_term;
  int			multi_init_map_size;
}			t_tetris;

extern t_tetris		g_tetris;

int		parse_option(int ac, char **av);
int		print_err_msg(char *msg, int code_return);
int		is_option_valid(t_option *options, char *str);
int		get_option_index(t_option *options, char *key);
int		show_option_help(char *prog_name);
int		check_option_bool(char *value, t_option *options, int key);
int		is_option_mask(char *value_mask, char *value);
int		get_user_option(int ac, char **av);
void		init_defaut_option(t_option *options);
void		free_options(t_option *options);
int		check_win(void);
void		init_ncurses_color();
void		print_colored_string(int x, int y, int color, char *str);
void		print_logo(void);
WINDOW		*create_new_win(int n_lines, int n_cols, int pos_x, int pos_y);
void		sig_handle_resize(int code);
void		sig_handler_sigint(int code);
void		create_win_board(void);
void		create_win_score(void);
void		create_win_next_preview(void);
void		draw_win_score(void);
void		draw_win_board(void);
void		draw_win_next_preview(void);
void		print_copyright(void);
int		init_ncurses();
int		init_gameboard();
void		create_win_board_debug();
void		draw_win_board_debug();
int		***alloc_3d_int(int x, int y, int z);
void		free_alloc_3d_int(void ***data, int x, int y);
int		init_tetriminos();
void		show_next_preview_title();
int		check_nxt_pos(t_tetriminos tetriminos, t_point nxt_pos);
void		draw_preview_tetriminos(t_tetriminos *tetriminos);
void		draw_curr_tetriminos(t_tetriminos tetriminos);
void		draw_curr_tetriminos_debug(t_tetriminos tetriminos);
char		*concat_rep_str(char *str1, char *str2);
int		cpt_number(char *line, int *i);
int		count_file_in_dir(char *directory);
int		set_head_info(char *line, int *row, int *col, int *color);
void		init_empty_tetriminos(t_tetriminos tetrimino);
void		show_debug();
int		check_first_line(char *line);
int		check_second_line(char *line, int col);
int		check_tetrimino_file(char *filename, int *row, int *col, int *);
int		rand_nbr(int min, int max);
int		is_game_over();
void		free_alloc_2d(void **data, int x);
int		**alloc_2d_int(int x, int y);
void		free_alloc_3d(void ***data, int x, int y);
int		check_user_colision(t_tetriminos tetrimino, t_point nxt_pos);
int		check_complete_line(int row);
int		check_all_complete_line();
char		*get_user_term(char **env);
int		set_term_mode(int flag);
char		*my_getch();
char		*my_getch2();
void		show_pause();
void		gamepad_action_pause(char *s, int paused);
void		gamepad_action(char *s);
void		action_left();
void		action_right();
void		action_drop();
void		action_turn();
void		free_tetriminos();
void		send_next_tetrimino();
int		draw_tetrimino_to_board(t_tetriminos tetrimino);
void		show_game_over();
void		print_term_touch(char *title, char *term_touch);
t_point		get_tetrimino_max_grid();
int		shape_rotation(int **shape_0, int size, int **final_shape);
void		gen_tetriminos_rotation();
void		register_hight_score();
int		get_hight_score();
int		check_file_ext(char *filename, char *ext);
void		print_tetrimino_shape(int fd, t_point row_col);
char		**get_files_in_dir(char *dir);
int		tetrimino_parse(void);
int		check_tetrimino_grid(int x, int y);

int		cbk_init_option_key(char *value, char *key_l);
int		cbk_init_option(char *value, char *key_l);
int		cbk_init_option_mapsize(char *value, char *key_l);

int		tetris_game_init(void);
void		tetris_game_cleanup(void);
void		tetris_game_pause(void);
void		tetris_game_resume(void);
void		tetris_game_handleEvents(void);
void		tetris_game_update(void);
void		tetris_game_draw(void);
#endif /* !TETRIS_H_ */
