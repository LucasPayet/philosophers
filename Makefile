# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 14:45:40 by lupayet           #+#    #+#              #
#    Updated: 2025/11/07 15:28:25 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC_F = main.c
SRC_DIR = ./src/
OBJ_D = ./obj/
INC = ./include/

$(OBJ_DIR):
	@mkdir obj

OBJ	= $(addprefix $(OBJ_DIR), $(SRC_F:.c=.o))

$(OBJ)%.o: $(OBJ_DIR) $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:fclean all

rebonus: fclean bonus

dev: re
	@make clean 1>/dev/null
