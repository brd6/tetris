/*
** game_engine.h for game_engine in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/include
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Feb 23 18:09:00 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 00:43:18 2016 Berdrigue BONGOLO BETO
*/

#ifndef GAME_ENGINE_H_
# define GAME_ENGINE_H_

# define WIN_WIDTH 80
# define WIN_HEIGHT 24

typedef enum		e_state
{
  QUIT,
  RUNNING,
  PAUSED
}			t_state;

typedef struct		s_game_engine
{
  t_state		game_state;
  int			(*init)(void);
  void			(*cleanup)(void);
  void			(*pause)(void);
  void			(*handleevents)(void);
  void			(*update)(void);
  void			(*draw)(void);
}			t_game_engine;

extern t_game_engine	g_game_engine;
#endif /* !GAME_ENGINE_H_ */
