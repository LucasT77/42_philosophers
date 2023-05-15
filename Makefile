# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2023/05/15 17:00:47 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philosophers

SOURCE			=	
OBJECT			=	$(SOURCE:.c=.o)
 
CC 				=	cc
CFLAGS			=	-Wall -Wextra -Werror -pthread

all:			$(NAME) 

$(NAME):		$(OBJECT)
						$(MAKE) -C
						$(CC) $(CFLAGS) $(OBJECT) -o philosophers
						echo "Mandatory done"

clean:
						$(RM) $(OBJECT)
						echo "Cleaned"

fclean:			clean
						$(RM) $(NAME)
						echo "Fully cleaned"

re:				fclean all

.SILENT:
