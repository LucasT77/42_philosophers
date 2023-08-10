SRCS = philo.c actions.c get_1.c get_2.c get_3.c utils.c set_1.c set_2.c inits.c time.c
NAME = philo
CC = cc
FLAGS = -Wall -Werror -Wextra -lpthread #-fsanitize=thread
RM = rm -f
OBJS= $(SRCS:.c=.o)

all: ${NAME}

$(NAME): $(OBJS)
		${CC} ${FLAGS} -o ${NAME} ${OBJS} ${INCS}
# ${NAME}: 
# 	${CC} ${FLAGS} -o ${NAME} ${SRCS} ${INCS}

ignore:
	${CC} ${FLAGS} -o ${NAME} ${OBJS} ${INCS}

clean:
	${RM} ${OBJS}

fclean:clean 
	${RM} ${NAME}

re:fclean all

.PHONY:all re clean fclean