/*
** tetris_state_game.c for tetris_state_game in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/include
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Feb 23 19:08:06 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 14:55:08 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "game_engine.h"
#include "tetris.h"

int		tetris_game_init()
{
  if (g_tetris.nb_tetriminos == 0 || !init_gameboard())
    return (0);
  if (!init_ncurses())
    return (g_game_engine.cleanup(), 0);
  gen_tetriminos_rotation();
  set_term_mode(1);
  srand(time(NULL));
  g_tetris.curr_tetriminos = rand_nbr(0, g_tetris.nb_tetriminos);
  g_tetris.next_tetriminos = rand_nbr(0, g_tetris.nb_tetriminos);
  print_logo();
  create_win_score();
  create_win_board();
  create_win_next_preview();
  create_win_board_debug();
  draw_win_score();
  draw_win_board();
  draw_win_next_preview();
  draw_win_board_debug();
  print_copyright();
  wclear(g_tetris.win_next_preview);
  return (1);
}

void		tetris_game_cleanup()
{
  if (g_game_engine.game_state == QUIT)
    {
      delwin(g_tetris.win_score);
      delwin(g_tetris.win_next_preview);
      delwin(g_tetris.win_board);
      delwin(g_tetris.win_board_debug);
      free(g_tetris.gamepad.user_key_left);
      free(g_tetris.gamepad.user_key_right);
      free(g_tetris.gamepad.user_key_turn);
      free(g_tetris.gamepad.user_key_drop);
      free(g_tetris.gamepad.user_key_quit);
      free(g_tetris.gamepad.user_key_pause);
      free_alloc_2d((void **)g_tetris.gameboard, g_tetris.map_size.y);
      free_tetriminos();
    }
  endwin();
  set_term_mode(0);
}

void		tetris_game_pause()
{
  if (g_tetris.game_over)
    show_game_over();
  else
    {
      show_pause();
      print_logo();
      usleep(g_tetris.game_tick * 3);
      draw_win_score();
      draw_win_board();
      draw_win_next_preview();
      draw_win_board_debug();
      print_copyright();
    }
  gamepad_action_pause(my_getch(), 1);
}

void		tetris_game_handleEvents()
{
  char		*s;

  s = my_getch();
  gamepad_action(s);
}

void		tetris_game_update()
{
  t_point	nxt_pos;

  if ((g_tetris.game_tick = (GAME_SPEED_2 - (g_tetris.level) * GAME_SPEED)) < 0)
    g_tetris.game_tick = 0;
  g_tetris.game_timer += g_tetris.game_tick;
  usleep(g_tetris.game_tick);
  if (g_tetris.game_run > GAME_RUN_SPEED)
    {
      nxt_pos.x = g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left.x;
      nxt_pos.y = g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left.y;
      nxt_pos.y++;
      if (check_nxt_pos(g_tetris.tetriminos[g_tetris.curr_tetriminos],
			  nxt_pos))
  	{
  	  g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left.y++;
  	  wclear(g_tetris.win_board);
  	}
      check_all_complete_line();
      g_tetris.game_run = 0;
    }
  g_tetris.game_run++;
}
