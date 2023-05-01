# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 17:07:24 by cemenjiv          #+#    #+#              #
#    Updated: 2023/05/01 19:30:02 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= megaphone

SRCS			= megaphone.cpp

OBJS			= $(SRCS:.cpp=.o) 

CC				= c++ 
CFLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= rm -f 

%.o:%.cpp		
				$(CC) ${CFLAGS}  -c $< -o $@
	
all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $@ 
			
clean:		
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re 
