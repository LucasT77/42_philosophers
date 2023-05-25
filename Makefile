# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2023/05/25 15:44:45 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philosophers

SOURCE			=	philo.c src/utils.c src/threads.c src/states.c src/free_all.c

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
