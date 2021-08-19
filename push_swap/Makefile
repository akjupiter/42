SOURCES				=	libraries/get_next_line_utils.c \
						libraries/get_next_line.c \
						libraries/libft_functions.c \
						libraries/libft_functions2.c \
						libraries/libft_ft_split.c \
						libraries/libft_ft_calloc.c \
						sources/list/list.c \
						sources/list/push.c \
						sources/list/reverserotate.c \
						sources/list/rotate.c \
						sources/list/swap.c \
						sources/parser/parser.c
OBJECTS				=	${SOURCES:.c=.o}

SOURCES_CHECKER		=	sources/checker/checker.c						
OBJECTS_CHECKER		=	${SOURCES_CHECKER:.c=.o}

SOURCES_PUSHSWAP	=	sources/pushswap/pushswap.c \
						sources/pushswap/heapsort.c \
						sources/pushswap/smallsort.c \
						sources/pushswap/bigsort.c
OBJECTS_PUSHSWAP	=	${SOURCES_PUSHSWAP:.c=.o}

NAME_CHECKER		=	checker
NAME_PUSHSWAP		=	push_swap

COMPILE				=	clang
REMOVE				=	rm -f

COMPILATION_FLAGS	=	-Wall -Wextra -Werror

.c.o:
	${COMPILE} ${COMPILATION_FLAGS} -c $< -o ${<:.c=.o}

all: ${NAME_CHECKER} ${NAME_PUSHSWAP}

${NAME_CHECKER}: ${OBJECTS} ${OBJECTS_CHECKER}
	${COMPILE} -o ${NAME_CHECKER} ${OBJECTS} ${OBJECTS_CHECKER}

${NAME_PUSHSWAP}: ${OBJECTS} ${OBJECTS_PUSHSWAP}
	${COMPILE} -o ${NAME_PUSHSWAP} ${OBJECTS} ${OBJECTS_PUSHSWAP}

clean:
	${REMOVE} ${OBJECTS} ${OBJECTS_CHECKER} ${OBJECTS_PUSHSWAP}

fclean: clean
	${REMOVE} ${NAME_CHECKER} ${NAME_PUSHSWAP}

re: fclean all

.PHONY: all clean fclean re
