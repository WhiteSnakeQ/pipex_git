# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 01:07:43 by kreys             #+#    #+#              #
#    Updated: 2023/11/29 14:58:15 by kreys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_isalpha.c ft_striteri.c ft_putnbr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c \
ft_strmapi.c ft_split.c ft_isdigit.c ft_itoa.c ft_strtrim.c ft_strjoin.c ft_isalnum.c ft_substr.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
 ft_strdup.c 

SRCS		= ${SRC}

OBJ			= ${SRCS:.c=.o}

BOBJ		= ${BSRCS:.c=.o}

BSRCS		= ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c \
  ft_lstnew.c ft_lstmap.c ft_lstiter.c 

NAME_F		= libft.a

HEADER		= libft.h

AR			= ar rc

RM			= rm -f

LIBR		= ranlib

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME_F} clean

.c.o:
			@${GCC} ${CFLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

${NAME_F}:	${OBJ}
			@${AR} ${NAME_F} ${OBJ}
			@${LIBR} ${NAME_F}

bonus:		${OBJ} ${BOBJ}
			@${AR} ${NAME_F} ${OBJ} ${BOBJ}
			@${LIBR} ${NAME_F}

clean:
			@rm -f ${OBJ} ${BOBJ}

fclean:		clean
			@rm -f ${NAME_F}

re:			fclean all

.PHONY:		all clean fclean re
