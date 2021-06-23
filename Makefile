# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 14:24:43 by iidzim            #+#    #+#              #
#    Updated: 2021/06/23 18:35:42 by iidzim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1			=	push_swap
NAME2			=	checker

SRCS			=	./push_swap/push_swap.c\
					./checker/operation.c\
					./checker/operation2.c\
					./checker/list.c\
					./checker/list2.c\
					./checker/utils.c\
					./checker/utils.c\
					./checker/checker.c\
					./checker/gnl.c\
					./checker/gnl_utils.c

# SRCB			=	

OBJS			=	$(SRCS:.c=.o)

# OBJB			=	$(SRCB:.c=.o)

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address
RM				=	rm -f

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
