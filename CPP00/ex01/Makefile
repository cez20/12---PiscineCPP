# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 17:07:24 by cemenjiv          #+#    #+#              #
#    Updated: 2023/01/31 08:38:20 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= phonebook

SRCS			= phonebook.cpp
				  	  
OBJS			= $(SRCS:.cpp=.o) #Declaration OBJS (objets). Tous les fichiers terminant par le suffixe .c vont devenir .o

CC				= g++
CFLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= rm -f 

.c.o:		
				gcc ${CFLAGS}  -c $< -o $(<:.c=.o) 
	
all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) ${OBJS} -o $@ 
			
clean:		
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re 
