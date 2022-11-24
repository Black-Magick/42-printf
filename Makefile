# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 10:19:38 by remanuel          #+#    #+#              #
#    Updated: 2022/11/24 11:42:15 by remanuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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