/*
** tetris_state_game_draw.c for tetris_state_game_draw in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Mar 19 13:24:47 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 13:24:58 2016 Berdrigue BONGOLO BETO
*/

#include "tetris.h"

void		tetris_game_draw()
{
  draw_win_score();
  draw_win_board();
  draw_win_next_preview();
  draw_win_board_debug();
}
