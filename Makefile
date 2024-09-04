# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 12:42:40 by amagnell          #+#    #+#              #
#    Updated: 2024/09/04 14:33:04 by amagnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------TARGET---------------#
NAME 		= client
NAME2 		= server

#------------LIBRARIES------------#
LIBS		= ft
LIBFT_DIR	= libft/
INCLUDE 	= minitalk.h libft/libft.h 
LIBFT 		= libft/libft.a

#------------FILES----------------#
SOURCES		= client.c
SOURCES2	= server.c

#------------OBJS & DEPS----------#
OBJECTS 	= $(SOURCES:.c=.o)
OBJECTS2	= $(SOURCES2:.c=.o)

DEP			= $(SOURCES:.c=.d)
DEP2		= $(SOURCES2:.c=.d)

#------------CC-------------------#
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -fsanitize=address
CPPFLAGS	= $(addprefix -I, $(INCLUDE)) -MMD -MP
LDFLAGS		= $(addprefix -L, $(dir $(LIBFT)))
LDLIBS		= $(addprefix -l, $(libs))

#------------COMMANDS-------------#
RM			= rm -rf
MAKEFLAGS 	+= --no-print-directory
	
#------------RULES----------------#
all : libft $(NAME) $(NAME2)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $(NAME)

$(NAME2) : $(OBJECTS2) $(LIBFT)
	$(CC) $(LDFLAGS) $(OBJECTS2) $(LDLIBS) -o $(NAME2)

libft : 
	@make $(MAKEFLAGS) -C $(LIBFT_DIR)

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEP) $(DEP2)

clean :
	$(RM) $(OBJECTS) $(OBJECTS2) $(DEP) $(DEP2)
	@make  clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME) $(NAME2)
	@make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY: all re clean fclean libft
.SILENT:
