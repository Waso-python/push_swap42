# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 14:50:12 by sdarr             #+#    #+#              #
#    Updated: 2022/01/30 21:55:54 by sdarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME_BONUS  = 	checker

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

HEADER		=	push_swap.h

SRC			=	push_swap.c 			push_swap_lib_utils.c	\
				push_swap_lib_split.c	push_swap_atoi.c 		\
				push_swap_checkers.c	push_swap_lib_list.c	\
				push_swap_list.c		ps_command1.c			\
				ps_sorting2.c			ps_sorting.c			\
				ps_sorting3.c			ps_command2.c
				
SRC_BONUS	=	checker.c				push_swap_lib_utils.c	\
				push_swap_lib_split.c	push_swap_atoi.c 		\
				push_swap_checkers.c	push_swap_lib_list.c	\
				push_swap_list.c		ps_command1.c			\
				ps_sorting2.c			ps_sorting.c			\
				ps_sorting3.c			ps_command2.c			\
				checker_util.c

OBJ_DIR		=	obj
OBJ_DIR_BONUS		=	b_obj
OBJ 		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ_BONUS	=	$(addprefix $(OBJ_DIR_BONUS)/,$(SRC_BONUS:.c=.o))

RM_DIR		=	rm -rf
RM_FILE		=	rm -f

INCLUDES	= 	-I .

${NAME}:	${OBJ}
			@$(CC) -o $(NAME) $(OBJ) $(FLAGS) 
			@echo "\tCompiling...\t" [ $(NAME) ] $(SUCCESS)
			
${NAME_BONUS}:	${OBJ_BONUS}
				@$(CC) -o $(NAME_BONUS) $(OBJ_BONUS) $(FLAGS) 
				@echo "\tCompiling...\t" [ $(NAME_BONUS) ] $(SUCCESS)

									
$(OBJ)		:	| $(OBJ_DIR)

$(OBJ_BONUS)		:	| $(OBJ_DIR_BONUS)

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)
			
$(OBJ_DIR)/%.o :	%.c $(HEADER) Makefile
					@${CC} $(FLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_DIR_BONUS):
			@mkdir -p $(OBJ_DIR_BONUS)
			
$(OBJ_DIR_BONUS)/%.o :	%.c $(HEADER) Makefile
						@${CC} $(FLAGS) $(INCLUDES) -o $@ -c $<
					

#COLORS
C_NO="\033[00m"
C_OK="\033[32m"
C_GOOD="\033[32m"

#DEBUG
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)
			
all:	$(NAME)

bonus:	$(NAME_BONUS)

clean:
		@${RM_DIR} ${OBJ_DIR}
		@echo "\tCleaning...\t" [ $(NAME) ] $(OK)
		@${RM_DIR} ${OBJ_DIR_BONUS}
		@echo "\tCleaning...\t" [ $(NAME_BONUS) ] $(OK)
		
fclean:	clean
		@${RM_FILE} $(NAME) 
		@echo "\tDeleting...\t" [ $(NAME) ] $(OK)
		@${RM_FILE} $(NAME_BONUS)
		@echo "\tDeleting...\t" [ $(NAME_BONUS) ] $(OK)
		
re:		fclean all

.PHONY: all clean fclean re bonus
