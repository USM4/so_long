CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = libft.a
imps = ft_atoi.o ft_calloc.o ft_isalpha.o ft_isdigit.o ft_memcmp.o ft_memmove.o ft_strchr.o ft_strlcat.o ft_strnstr.o ft_tolower.o\
ft_bzero.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_memcpy.o ft_memchr.o ft_memset.o ft_strdup.o ft_strncmp.o ft_strrchr.o \
ft_toupper.o ft_strlcpy.o ft_itoa.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_substr.o ft_strjoin.o ft_strlen.o \
ft_strtrim.o ft_strmapi.o ft_striteri.o ft_split.o
bonus_imps =  ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o

sources = $(imps:.o=.c)
sources_bonus = $(bonus_imps:.o=.c)

all : $(NAME)

 $(NAME) : $(imps)
			ar -rc $(NAME) $(imps)

 bonus : $(bonus_imps)
			ar -rc $(NAME) $(bonus_imps)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $<

clean :
		rm -f *.o

fclean :
		rm -f *.a *.o

re : fclean all

.PHONY: fclean clean re all bonus