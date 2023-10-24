# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 12:42:40 by amagnell          #+#    #+#              #
#    Updated: 2023/10/24 20:11:13 by amagnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME2 = server
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
INCLUDE = minitalk.h
LIBFT = libft/libft.a
SOURCES = client.c
SOURCES2 = server.c
OBJECTS = $(SOURCES:.c=.o)

OBJECTS2 = $(SOURCES2:.c=.o)

DEP = $(SOURCES:.c=.d)

DEP2 = $(SOURCES2:.c=.d)

all : $(LIBFT) $(NAME) $(NAME2)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) : 
	make -C libft

-include $(DEP) $(DEP2)
$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(NAME2) : $(OBJECTS2) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME2)

fclean : clean
	rm -f $(NAME) $(NAME2)
	make -C libft fclean

clean :
	rm -f $(OBJECTS) $(OBJECTS2) $(DEP) $(DEP2)
	make -C libft clean

re : fclean all

.PHONY: all re clean fclean