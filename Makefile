# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amecani <amecani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 21:57:45 by amecani           #+#    #+#              #
#    Updated: 2024/07/07 23:40:04 by amecani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g3

SOURCES =				minishell.c \
$(addprefix parsing/,	extract_token.c parse.c utilities.c)

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJECTS) | $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME) -lreadline

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C libft clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C libft fclean
	@rm -rf $(OBJECTS)
	@rm -rf $(NAME)

re: fclean all