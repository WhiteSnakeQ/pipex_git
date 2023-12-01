# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 07:07:11 by kreys             #+#    #+#              #
#    Updated: 2023/12/01 17:24:34 by kreys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c error.c init_obj.c parse.c delete_obj.c work_with_file.c
SRCDIR		= ./project/pipex/

SRCPRF		= ./project/printf/libftprintf.a
SRCLIB		= ./project/LIBFT/libft.a

SRCGNL		= get_next_line.c get_next_line_utils.c
SRCGNLDIR	= ./project/get_next_line/

OBJGNL		= ${addprefix ${SRCGNLDIR}, ${SRCGNL:.c=.o}}
OBJ			= ${addprefix ${SRCDIR}, ${SRC:.c=.o}} ${SRCPRF} ${SRCLIB} ${OBJGNL}

NAME		= pipex

FLAGS		= -Wall -Wextra -Werror -fsanitize=address,undefined -g3

CC			= cc

all:		${NAME}

.c.o:
			@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	printf libft ${OBJ}
			@${CC} ${FLAGS} ${SRCPRF} ${OBJ} -o ${NAME}
			@echo DONE

printf:		
			@${MAKE} -C ./project/printf/

libft:		
			@${MAKE} -C ./project/libft/

re:			fclean all

clean:		
			@rm -f ${OBJ}

fclean:		clean
			@rm -f ${NAME}