# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 17:54:38 by cemenjiv          #+#    #+#              #
#    Updated: 2023/04/11 18:12:07 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME			= Animal

# SRCS			= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
				  	  
# OBJS			= $(SRCS:.cpp=.o) #Do not forget to use .cpp in here. 

# CC				= c++  #We can also use c++ as a compiler 
# CFLAGS			= -Wall -Wextra -Werror -g -std=c++98
# RM				= rm -f 

# .cpp.o:
# 				c++ ${CFLAGS}  -c $< -o $(<:.cpp=.o) 
	
# all:			$(NAME)

# $(NAME):		$(OBJS)
# 				$(CC) ${OBJS} -o $@ 
			
# clean:		
# 				$(RM) $(OBJS)
				
# fclean:			clean
# 				$(RM) $(NAME)
				
# re:				fclean all

# .PHONY:			all clean fclean re

NAME			= Animal

SRCS_DIR   		= srcs/
SRCS_FILES		= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
SRCS 			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS_DIR		= objs/
OBJS 			= $(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))

CC				= c++
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
