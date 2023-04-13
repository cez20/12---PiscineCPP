# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 17:07:24 by cemenjiv          #+#    #+#              #
#    Updated: 2023/03/27 14:58:08 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= zombie

SRCS			= main.cpp Zombie.cpp zombieHorde.cpp
				  	  
OBJS			= $(SRCS:.cpp=.o) #Do not forget to use .cpp in here. 

CC				= c++  #We can also use c++ as a compiler 
CFLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= rm -f 

.c.o:		
				c++ ${CFLAGS}  -c $< -o $(<:.c=.o) 
	
all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) ${OBJS} -o $@ 
			
clean:		
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re 
