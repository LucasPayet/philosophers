# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 14:45:40 by lupayet           #+#    #+#              #
#    Updated: 2025/11/13 13:13:01 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC_F = main.c utils.c init.c
SRC_DIR = ./src/
OBJ_D = ./obj/
INC = ./include/

OBJ	= $(addprefix $(OBJ_D), $(SRC_F:.c=.o))

all: $(NAME)

$(OBJ_D):
	@mkdir -p $(OBJ_D)

$(OBJ_D)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME): $(OBJ_D) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

dev: re
	@make clean 1>/dev/null

.PHONY: all clean fclean re dev
