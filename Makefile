# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagnell <amagnell@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 12:42:40 by amagnell          #+#    #+#              #
#    Updated: 2023/10/13 14:32:56 by amagnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME2 = server
CFLAGS = -Wall -Wextra -Werror -MD
INCLUDE = minitalk.h
SOURCES = client.c
SOURCES2 = server.c
OBJECTS = $(SOURCES:.c=.o)

OBJECTS2 = $(SOURCES2:.c=.o)

DEP = $(SOURCES:.c=.d)

DEP2 = $(SOURCES2:.c=.d)

$(NAME) : $(OBJECTS)
	ar -rsc $(NAME) $^

$(NAME2) : $(OBJECTS2)
	ar -rsc $(NAME2) $^

all : $(NAME) $(NAME2)

fclean : clean
	rm -f $(NAME) $(NAME2)

clean :
	rm -f $(OBJECTS) $(OBJECTS2) $(DEP) $(DEP2)

re : fclean all

.PHONY: all re clean fclean

-include $(DEP) $(DEP2)
