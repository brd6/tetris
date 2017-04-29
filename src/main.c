/*
** main.c for tetris in /home/franco_k/Projets/PSU/PSU_2015_tetris
**
** Made by Matthieu FSC
** Login   <franco_k@epitech.net>
**
** Started on  Mon Feb 22 13:15:57 2016 Matthieu FSC
** Last update Sun Mar 20 22:00:13 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <sys/ioctl.h>
#include <signal.h>
#include "my.h"
#include "my_printf.h"
#include "game_engine.h"
#include "tetris.h"

t_game_engine	g_game_engine;
t_tetris	g_tetris;

int		show_option_help(char *prog_name)
{
  my_printf("Usage: %s [options]\nOptions:\n", prog_name);
  my_putstr("  --help\t\t Display this help\n");
  my_putstr("  -l --level={num}\t Start Tetris at level num\n");
  my_putstr("  -kl --key-left={K}\t Move tetrimino on LEFT with key K\n");
  my_putstr("  -kr --key-right={K}\t Move tetrimino on RIGHT with key K\n");
  my_putstr("  -kt --key-turn={K}\t Turn tetrimino with key K\n");
  my_putstr("  -kd --key-drop={K}\t Set default DROP on key K\n");
  my_putstr("  -kq --key-quit={K}\t Quit program when press key K\n");
  my_putstr("  -kp --key-pause={K}\t Pause and restart game when press key K");
  my_putstr("\n  --map-size={row,col}\t Set game size at row, col\n");
  my_putstr("  -w --without-next\t Hide next tetrimino\n");
  my_putstr("  -d --debug\t\t Debug mode\n");
  return (-1);
}

int		init_game_state()
{
  g_game_engine.init = tetris_game_init;
  g_game_engine.cleanup = tetris_game_cleanup;
  g_game_engine.pause = tetris_game_pause;
  g_game_engine.handleevents = tetris_game_handleEvents;
  g_game_engine.update = tetris_game_update;
  g_game_engine.draw = tetris_game_draw;
  g_game_engine.game_state = QUIT;
  return (1);
}

void			debug_tetriminos(t_tetriminos tetrimino)
{
  int			l;
  int			k;
  int			q;

  l = 0;
  while (l < 5)
    {
      k = 0;
      my_printf("[%d]\n", l);
      while (k < tetrimino.size)
	{
	  q = 0;
	  while (q < tetrimino.size)
	    {
	      my_printf("%d ", tetrimino.shape[l][k][q]);
	      q++;
	    }
	  my_printf("\n");
	  k++;
	}
      my_printf("\n");
      l++;
    }
}

int		check_tetriminos_grid()
{
  t_point	grid_max;

  grid_max = get_tetrimino_max_grid();
  if (grid_max.x > g_tetris.map_size.x || grid_max.y > g_tetris.map_size.y)
    return (my_putstr(TETRIMINO_GRID_SIZE_ERROR), 0);
  return (1);
}

int		main(int ac, char **av, char **env)
{
  int		is_help;

  signal(SIGINT, sig_handler_sigint);
  signal(SIGWINCH, sig_handle_resize);
  if ((g_tetris.term_name = get_user_term(env)) == NULL ||
      setupterm(NULL, 1, NULL) != OK ||
      ioctl(STDIN_FILENO, TCGETS, &g_tetris.user_term) == -1 ||
      (is_help = get_user_option(ac, av)) <= 0)
    return (is_help == -1 ? 0 : 1);
  if (tetrimino_parse() > -1 && g_tetris.enable_debug)
    show_debug();
  if (!init_game_state() || !check_tetriminos_grid() || !g_game_engine.init())
    return (1);
  while (g_game_engine.game_state != QUIT)
    {
      g_game_engine.handleevents();
      if (g_game_engine.game_state != PAUSED && check_win())
  	{
  	  g_game_engine.update();
  	  g_game_engine.draw();
  	}
      else
  	g_game_engine.pause();
    }
  return (g_game_engine.cleanup(), 0);
}
