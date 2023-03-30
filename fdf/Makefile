NAME = fdf
CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC =  \
	 ./fdf.c    \
	 ./ft_split.c \
	 ./utils.c \
	  ./utils2.c \
	 ./create_tab.c \
	 ./change_base.c \
	 ./renderandprint.c\
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \


OBJ = $(SRC:.c=.o)
.SILENT:

all : ${NAME}

${NAME} : ${OBJ}
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "FDF is created"
.o: .c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 
	rm -f $(OBJ) 
	
fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re all 
