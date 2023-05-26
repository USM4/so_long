CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
HEADERS= ./includes/so_long.h ./includes/get_next_line.h
SOURCES = ./src/main.o ./src/util/util.o ./src/util/ft_strnstr.o ./src/gnl/get_next_line.o ./src/gnl/get_next_line_utils.o ./src/parsing/map_contains.o ./src/parsing/check_walls.o \
./src/parsing/valid_path.o ./src/parsing/error_handler.o ./src/parsing/parsing.o ./src/handle_events/move_down.o ./src/handle_events/move_up.o ./src/handle_events/move_left.o  \
./src/handle_events/move_right.o ./src/handle_events/draw_image.o ./src/handle_events/close_window.o 

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	rm -f $(SOURCES)

fclean :
	rm -f $(SOURCES) $(NAME)

re : fclean all

.PHONY: fclean clean re all