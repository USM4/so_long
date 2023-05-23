CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = so_long
HEADERS= ./includes/so_long.h ./includes/get_next_line.h
SOURCES = ./src/main.o ./src/util/util.o ./src/gnl/get_next_line.o ./src/gnl/get_next_line_utils.o ./src/parsing/map_contains.o ./src/parsing/check_walls.o ./src/parsing/valid_path.o

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@
	# $(CC) -Imlx $(CFLAGS) -c $<

clean :
	rm -f $(SOURCES)

fclean :
	rm -f $(SOURCES) $(NAME)

re : fclean all

.PHONY: fclean clean re all