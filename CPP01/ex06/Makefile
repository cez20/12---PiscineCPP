# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 17:07:24 by cemenjiv          #+#    #+#              #
#    Updated: 2023/04/02 20:30:48 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= HarlFilter

SRCS			= main.cpp Harl.cpp 
				  	  
OBJS			= $(SRCS:.cpp=.o) #Do not forget to use .cpp in here. 

CC				= c++  #We can also use c++ as a compiler 
CFLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= rm -f 

.cpp.o:
				c++ ${CFLAGS}  -c $< -o $(<:.cpp=.o) 
	
all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) ${OBJS} -o $@ 
			
clean:		
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re

