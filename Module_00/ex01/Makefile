# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 00:25:35 by ael-khni          #+#    #+#              #
#    Updated: 2024/07/01 17:51:53 by danbarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= phonebook

CC			:= c++
FLAGS		:= -Wall -Wextra -Werror -std=c++98

#Colors:
GREEN		:= \e[92;5;118m
YELLOW		:= \e[93;5;226m
GRAY		:= \e[33;2;37m
RESET		:= \e[0m
CURSIVE		:= \e[33;3m

all: $(NAME)

$(NAME): phonebook.cpp phonebook.hpp
	@printf "$(CURSIVE)$(GRAY)- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(FLAGS) megaphone.cpp -o $(NAME)
	@printf "$(GREEN)- Executable ready.\n$(RESET)"

clean:
	@rm -rf $(NAME)
	@printf "$(YELLOW)- Executable removed.$(RESET)\n"

fclean: clean

re: fclean all

.PHONY: all clean re
