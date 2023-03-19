# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 17:07:24 by cemenjiv          #+#    #+#              #
#    Updated: 2023/03/19 14:53:24 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= phonebook

SRCS_DIR   		= srcs/
SRCS_FILES		= main.cpp phonebook.cpp contact.cpp
SRCS 			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS_DIR		= objs/
OBJS 			= $(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))

CC				= g++
CFLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= rm -f 

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
				$(CC) ${CFLAGS}  -c $< -o $@
	
all:			objs $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) ${OBJS} -o $@ 
			
clean:		
				@rm -rf $(OBJS)
				@rm -rf $(OBJS_DIR)
				
fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

objs:
				@mkdir -p objs

.PHONY:			all clean fclean re 
