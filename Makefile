##
## Makefile for tetris in /home/bongol_b/Epitech-rendu/PSU_2015_tetris
## 
## Made by Berdrigue BONGOLO BETO
## Login   <bongol_b@epitech.net>
## 
## Started on  Mon Feb 22 16:52:27 2016 Berdrigue BONGOLO BETO
## Last update Mon Mar 21 00:21:13 2016 Berdrigue BONGOLO BETO
##

CC	= 	gcc

RM	= 	rm -f

NAME	= 	tetris

SRCS	= 	src/main.c \
		src/arg_options.c \
		src/utils.c \
		src/arg_options_utils.c \
		src/arg_options_utils2.c \
		src/tetris_state_game.c \
		src/init_defaut_option.c \
		src/ncurses_utils.c \
		src/print_logo.c \
		src/callback_options.c \
		src/signal_handler.c \
		src/tetris_draw.c \
		src/tetris_windows.c \
		src/print_copyright.c \
		src/gameboard.c \
		src/tetriminos.c \
		src/tetrimino_file_parser.c \
		src/tetrimino_file_parser_utils.c \
		src/debug_info.c \
		src/tetrimino_file_parser_utils2.c \
		src/env_utils.c\
		src/setup_user_term.c \
		src/gamepad_action.c \
		src/actions.c \
		src/tetriminos_utils.c \
		src/shape_rotation.c \
		src/gen_tetriminos_rotation.c \
		src/register_hight_score.c \
		src/debug_info_utils.c \
		src/tetris_state_game_draw.c \
		src/gameboard_utils.c \
		src/utils2.c \

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Werror -pedantic
CFLAGS	+=	-I./include/ -I./lib/include/

LDFLAGS +=	-L./lib -lmy -L./lib/my_printf -lmyprintf
LDFLAGS +=	-lncurses

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean, mrproper, re, all, fclean
