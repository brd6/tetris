/*
** print_logo.c for Tetris in /home/franco_k/Projets/PSU/PSU_2015_tetris/src
** 
** Made by Matthieu FSC
** Login   <franco_k@epitech.net>
** 
** Started on  Sat Mar 19 17:32:01 2016 Matthieu FSC
** Last update Sat Mar 19 17:32:02 2016 Matthieu FSC
*/

#include "tetris.h"

void		print_logo_first()
{
  print_colored_string(1, 1, COLOR_COLOR_RED, "***");
  print_colored_string(2, 2, COLOR_COLOR_RED, "*");
  print_colored_string(2, 3, COLOR_COLOR_RED, "*");
  print_colored_string(2, 4, COLOR_COLOR_RED, "*");
  print_colored_string(2, 5, COLOR_COLOR_RED, "*");
  print_colored_string(6, 1, COLOR_COLOR_BLUE, "***");
  print_colored_string(6, 2, COLOR_COLOR_BLUE, "*");
  print_colored_string(6, 3, COLOR_COLOR_BLUE, "**");
  print_colored_string(6, 4, COLOR_COLOR_BLUE, "*");
  print_colored_string(6, 5, COLOR_COLOR_BLUE, "***");
  print_colored_string(11, 1, COLOR_COLOR_YELLOW, "***");
  print_colored_string(12, 2, COLOR_COLOR_YELLOW, "*");
  print_colored_string(12, 3, COLOR_COLOR_YELLOW, "*");
  print_colored_string(12, 4, COLOR_COLOR_YELLOW, "*");
  print_colored_string(12, 5, COLOR_COLOR_YELLOW, "*");
}

void		print_logo()
{
  print_logo_first();
  print_colored_string(16, 1, COLOR_COLOR_GREEN, "***");
  print_colored_string(16, 2, COLOR_COLOR_GREEN, "* *");
  print_colored_string(17, 3, COLOR_COLOR_GREEN, "**");
  print_colored_string(16, 4, COLOR_COLOR_GREEN, "* *");
  print_colored_string(16, 5, COLOR_COLOR_GREEN, "* *");
  print_colored_string(21, 1, COLOR_COLOR_BLUE, "*");
  print_colored_string(21, 3, COLOR_COLOR_BLUE, "*");
  print_colored_string(21, 4, COLOR_COLOR_BLUE, "*");
  print_colored_string(21, 5, COLOR_COLOR_BLUE, "*");
  print_colored_string(24, 1, COLOR_COLOR_MAGENTA, "***");
  print_colored_string(24, 2, COLOR_COLOR_MAGENTA, "*");
  print_colored_string(24, 3, COLOR_COLOR_MAGENTA, "***");
  print_colored_string(24, 4, COLOR_COLOR_MAGENTA, "  *");
  print_colored_string(24, 5, COLOR_COLOR_MAGENTA, "***");
}
