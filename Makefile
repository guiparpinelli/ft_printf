# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 17:40:35 by gparpine          #+#    #+#              #
#    Updated: 2023/05/27 19:22:10 by gparpine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME	=  libftprintf.a

SRCS 	= ft_printf.c src/print_hex.c src/print_nbr.c src/print_ptr.c src/print_str.c src/print_unbr.c
OBJS 	= ${SRCS:.c=.o}

CC	= cc
RM	= /bin/rm -f
CFLAGS	= -Wall -Wextra -Werror -I./includes/

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc ${NAME} ${OBJS}

clean:
	$(MAKE) clean -C ./libft
	${RM} ${OBJS}

fclean: clean
	$(MAKE) fclean -C ./libft
	${RM} ${NAME}

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader **/*.c
	norminette -R CheckDefine **/*.h

.PHONY: all re clean fclean norm
