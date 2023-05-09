CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
imps = so_long.o so_long_utils.o get_next_line.o get_next_line_utils.o

all : $(NAME)

$(NAME) : $(imps)
			# make -C ./libft
			$(CC) $(imps) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
			$(CC) $(imps) -L ./get_next_line -L./libft -lft  -o $(NAME)

%.o : %.c so_long.h
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
	$(CC) $(CFLAGS) -c $<

clean :
		make clean -C ./libft
		rm -f $(imps)

fclean :
		make clean -C ./libft
		rm -f $(imps) $(NAME)

re : fclean all

.PHONY: fclean clean re all