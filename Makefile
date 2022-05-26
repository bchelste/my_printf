# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 17:30:10 by bchelste          #+#    #+#              #
#    Updated: 2021/01/19 18:39:13 by bchelste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

SRCS		= ft_printf.c ft_parser.c ft_lib.c\
				ft_spec_c.c ft_spec_s.c ft_spec_p.c ft_spec_di.c \
				ft_src_spec_di.c ft_spec_u.c ft_spec_x.c ft_spec_perc.c \
				

OBJS		= $(SRCS:.c=.o)

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:		
			$(RM) $(OBJS) 
			
fclean:		clean
			$(RM) $(NAME)
			
re:			fclean $(NAME)