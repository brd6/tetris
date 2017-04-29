/*
** signal_handler.c for signal_handler in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Feb 24 19:48:12 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 15:50:54 2016 Berdrigue BONGOLO BETO
*/

#include <signal.h>
#include "game_engine.h"
#include "tetris.h"

void		sig_handle_resize(int code)
{
  if (code == SIGWINCH)
    g_game_engine.game_state = PAUSED;
}

void		sig_handler_sigint(int code)
{
  if (code == SIGINT)
    g_game_engine.game_state = QUIT;
}
