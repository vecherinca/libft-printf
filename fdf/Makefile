NAME = fdf
CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC =  \
	 ./fdf.c    \
	 ./ft_split.c \
	 ./utils.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \


OBJ = $(SRC:.c=.o)


all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ}

.o: .c
	${CC} -c ${CFLAGS} $< -o $@

clean: 
	rm -f $(OBJ) 
	
fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re all bonus