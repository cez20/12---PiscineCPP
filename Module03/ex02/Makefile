# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 17:54:38 by cemenjiv          #+#    #+#              #
#    Updated: 2023/04/09 23:07:58 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= FragTrap

SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
				  	  
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