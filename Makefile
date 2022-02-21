# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maykman <maykman@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 19:34:14 by maykman           #+#    #+#              #
#    Updated: 2022/02/21 19:36:17 by maykman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC			:=	@gcc
CFLAGS		:=	-Wall -Wextra -Werror

# COLORS
RED				:=	\033[38;5;9m
GREEN			:=	\033[38;5;10m
BLUE			:= 	\033[38;5;14m
YELLOW			:=	\033[38;5;226m
RESET			:=	\033[38;5;7m

# VARIABLES
NAME		:=	bsq
INCLUDES	:=	/includes

# FILES
SRCS		:=	main.c \
				get_next_line.c \
				get_next_line_utils.c \
				fill_tab.c
OBJS		:=	$(addprefix srcs/, ${SRCS:.c=.o})

# RULES
%.o:		%.c
	${CC} ${CFLAGS} -c -I.${INCLUDES} $< -o ${<:.c=.o}
	@echo "${BLUE}Compilation of $<...${RESET}"

$(NAME):	${OBJS}
	${CC} ${CFLAGS} $^ -o $@

all:		${NAME}

clean:
	@rm -f ${OBJS}
	@echo "${YELLOW}Cleaning objects files...${RESET}"

fclean:
	@rm -f ${NAME} ${OBJS}
	@echo "${RED}Full clean...${RESET}"

re:			fclean all

.PHONY:		all clean fclean re