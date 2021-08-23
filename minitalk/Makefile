SOURCE				=	librarie/utils.c
OBJECT				=	${SOURCE:.c=.o}

SOURCE_CLIENT	=	sources/client/ft_client.c
OBJECT_CLIENT		=	${SOURCE_CLIENT:.c=.o}

SOURCE_SERVER	=	sources/server/ft_server.c
OBJECT_SERVER	=	${SOURCE_SERVER:.c=.o}

NAME_CLIENT		=	client
NAME_SERVER		=	server

COMPILE				=	clang
REMOVE				=	rm -f

COMPILATION_FLAGS	=	-Wall -Wextra -Werror

.c.o:
	${COMPILE} ${COMPILATION_FLAGS} -c $< -o ${<:.c=.o}

all: ${NAME_CLIENT} ${NAME_SERVER}

${NAME_CLIENT}: ${OBJECT} ${OBJECT_CLIENT}
	${COMPILE} -o ${NAME_CLIENT} ${OBJECT} ${OBJECT_CLIENT}

${NAME_SERVER}: ${OBJECT} ${OBJECT_SERVER}
	${COMPILE} -o ${NAME_SERVER} ${OBJECT} ${OBJECT_SERVER}

clean:
	${REMOVE} ${OBJECT} ${OBJECT_CLIENT} ${OBJECT_SERVER}

fclean: clean
	${REMOVE} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

.PHONY: all clean fclean re
