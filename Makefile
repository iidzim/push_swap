# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 14:24:43 by iidzim            #+#    #+#              #
#    Updated: 2021/06/27 16:43:05 by iidzim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1			=	push_swap
NAME2			=	checker

SRCS			=	./push_swap_d/push_swap.c\
					./push_swap_d/sort_big_stack.c\
					./push_swap_d/sort_small_stack.c

SRCB			=	./checker_d/checker.c\
					./checker_d/gnl.c\
					

SRC				=	./checker_d/ft_split.c\
					./checker_d/gnl_utils.c\
					./push_swap_d/operation.c\
					./push_swap_d/operation2.c\
					./push_swap_d/list.c\
					./push_swap_d/utils.c\
					./push_swap_d/utils2.c

OBJS			=	$(SRCS:.c=.o)

OBJB			=	$(SRCB:.c=.o)

OBJ				=	$(SRC:.c=.o)

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

all:			$(NAME1)

$(NAME1):		$(OBJS) $(OBJ)
				@$(CC) -o $(NAME1) $(SRCS) $(SRC) $(FLAGS)

bonus :			$(NAME2)

$(NAME2):		$(OBJB) $(OBJ)
				@$(CC) -o $(NAME2) $(SRCB) $(SRC) $(FLAGS)

clean:
				@$(RM) $(OBJS) $(OBJB) $(OBJ)

fclean:			clean
				@$(RM) $(NAME1) $(NAME2)

re:				fclean all
