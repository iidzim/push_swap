# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 14:24:43 by iidzim            #+#    #+#              #
#    Updated: 2021/06/22 10:34:07 by iidzim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1			=	checker
NAME2			=	push_swap

SRCS			=	./push_swap/push_swap.c
					# ./push_swap/

# SRCB			=	

OBJS			=	$(SRCS:.c=.o)

# OBJB			=	$(SRCB:.c=.o)

CC				= 	gcc
FLAGS           =  -Wall -Wextra -Werror
RM				= 	rm -f

all:			$(NAME)

$(NAME1):		$(OBJS)
 				@$(CC) -o $(NAME1) $(SRCS) $(FLAGS)

bonus :			$(OBJB)
 				@$(CC) -o $(NAME2) $(SRCB) $(FLAGS)

clean:
				@$(RM) $(OBJS) $(OBJB)

fclean:			clean
				@$(RM) $(NAME1) $(NAME2)

re:				fclean all

.PHONY: 		all fclean clean re
