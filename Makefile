SRCS	= ft_printf.c num.c word.c

OBJS		= $(SRCS:.c=.o)

CC				= gcc
RM 				= /bin/rm -f
CFLAGS 		= -Wall -Wextra -Werror

NAME		= libftprintf.a

ARCHIVE			= ar -rc

all:		$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:			
			$(RM) $(OBJS)

fclean: 	clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re bonus