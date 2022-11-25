NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_1 =  \
	 ./ft_strlcpy.c    \
	./ft_strlen.c    \
	./ft_strlcat.c    \
	./ft_calloc.c    \
	./ft_bzero.c    \
	./ft_strdup.c    \
	./ft_memmove.c    \
	./ft_strnstr.c    \
	./ft_memchr.c    \
	./ft_strchr.c    \
	./ft_memcmp.c    \
	./ft_isascii.c    \
	./ft_isdigit.c    \
	./ft_memset.c    \
	./ft_memcpy.c       \
	./ft_atoi.c        \
	./ft_strncmp.c    \
	./ft_isalpha.c    \
	./ft_isalnum.c    \
	./ft_isprint.c    \
	./ft_toupper.c    \
	./ft_tolower.c     \
	./ft_strrchr.c    \

SRC_2 = \
	./ft_striteri.c \
	./ft_strmapi.c    \
	./ft_split.c    \
	./ft_strtrim.c    \
	./ft_substr.c    \
	./ft_putchar_fd.c    \
	./ft_putstr_fd.c    \
	./ft_putnbr_fd.c     \
	./ft_putendl_fd.c    \
	./ft_strjoin.c    \
	./ft_itoa.c        \

BONUS = \
	./ft_lstmap.c	\
	./ft_lstnew.c	\
	./ft_lstadd_front.c	\
	./ft_lstsize.c	\
	./ft_lstlast.c	\
	./ft_lstadd_back.c	\
	./ft_lstdelone.c	\
	./ft_lstclear.c	\
	./ft_lstiter.c	\

SRC = \
	$(SRC_1)	\
	$(SRC_2)	\
	$(BONUS)	\

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)
AR = ar -rc

all : ${NAME}

${NAME} : ${OBJ}
	${AR} ${NAME} ${OBJ}

.o: .c
	${CC} -c ${CFLAGS} $< -o $@

bonus: ${BONUS}
	${AR} $(NAME) $(BONUS_OBJ)

clean: 
	rm -f $(OBJ) $(BONUS_OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean ${NAME}

.PHONY: all clean fclean re all bonus
