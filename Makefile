# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 22:24:37 by stemsama          #+#    #+#              #
#    Updated: 2023/02/01 13:26:52 by stemsama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

LIBFT			=	./libft/libft.a

CC = cc
FLAGS =  -Wall -Werror -Wextra

SRC = tools1.c tools2.c main_p.c faire_map.c
OBJECT = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	@make -C ./libft all bonus
	@cp	./libft/libft.a $(NAME)
	@ar -cr $(NAME) $(OBJECT)
	
bonus : $(OBJECT_BONUS)
	@ar -cr $(NAME) $(OBJECT_BONUS)

%.o:%.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@ 

clean :
	@make -C ./libft clean
	rm -f $(OBJECT) $(OBJECT_BONUS)

fclean : clean
	@make -C ./libft fclean
	rm -f $(NAME)

re : fclean all 

.PHONY: clean fclean re all libft
