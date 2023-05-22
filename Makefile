CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = so_long
imps = so_long.o so_long_utils.o get_next_line.o  get_next_line_utils.o map_contains.o valid_path.o

all : $(NAME)

$(NAME) : $(imps)
			# make -C ./libft
			$(CC) $(CFLAGS) $(imps) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c so_long.h
	$(CC) $(CFLAGS)  -c $< -o $@
	# $(CC) -Imlx $(CFLAGS) -c $<

clean :
		make clean -C ./libft
		rm -f $(imps)

fclean :
		make clean -C ./libft
		rm -f $(imps) $(NAME)

re : fclean all

.PHONY: fclean clean re all