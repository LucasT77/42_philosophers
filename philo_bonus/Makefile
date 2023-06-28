# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2023/06/02 15:33:47 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philosophers

SOURCE			=	main.c src/philos.c src/states.c src/utils.c

OBJECT			=	$(SOURCE:.c=.o)
 
CC 				=	cc
CFLAGS			=	-Wall -Wextra -Werror -pthread

all:			$(NAME) 

$(NAME):		$(OBJECT)
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
