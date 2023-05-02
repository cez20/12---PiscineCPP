# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 17:07:24 by cemenjiv          #+#    #+#              #
#    Updated: 2023/05/01 22:25:14 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Phonebook

SRCS			= main.cpp PhoneBook.cpp Contact.cpp

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= rm -f 

OBJS			= $(SRCS:.cpp=.o) 

%.o: %.cpp
				$(CC) ${CFLAGS}  -c $< -o $@
	
all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@ 
			
clean:		
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re 
