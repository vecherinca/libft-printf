NAME = fdf
CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBS = libmlx_Linux.a -lm -lX11 -lXext
SRC =  \
	 ./fdf.c    \
	 ./ft_split.c \
	 ./utils.c \
	  ./utils2.c \
	 ./create_tab.c \
	 ./change_base.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \


OBJ = $(SRC:.c=.o)


all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME} ${OBJ}

.o: .c
	${CC} -c ${CFLAGS} $< -o $@

clean: 
	rm -f $(OBJ) 
	
fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re all bonus