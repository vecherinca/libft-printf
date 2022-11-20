NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

INCLUDES = ./libft.h

# SRC_PART1 = \
# 	 ./ft_strlcpy.c    \
# 	    ./ft_strlen.c    \
# 	 ./ft_strlcat.c    \
# 	 ./ft_calloc.c    \
# 	  ./ft_bzero.c    \
# 	  ./ft_strdup.c    \
# 	./ft_memmove.c    \
# 	./ft_strnstr.c    \
# 	./ft_memchr.c    \
# 	./ft_strchr.c    \
# 	./ft_memcmp.c    \
# 	./ft_isascii.c    \
# 	./ft_isdigit.c    \
# 	./ft_memset.c    \
# 	./ft_memcpy.c       \
# 	./ft_atoi.c        \
# 	./ft_strncmp.c    \
# 	./ft_isalpha.c    \
# 	./ft_isalnum.c    \
# 	./ft_isprint.c    \
# 	./ft_toupper.c    \
# 	./ft_tolower.c     \
# 	 ./ft_strrchr.c    \
	
# SRC_PART2 = \
# 	 ./ft_striteri.c \
# 	./ft_strmapi.c    \
# 	./ft_split.c    \
# 	./ft_strtrim.c    \
# 	 ./ft_substr.c    \
# 	 ./ft_putchar_fd.c    \
# 	 ./ft_putstr_fd.c    \
# 	./ft_putnbr_fd.c     \
# 	 ./ft_putendl_fd.c    \
# 	 ./ft_strjoin.c    \
# 	 ./ft_itoa.c        \

BONUS = \
		./ft_lstnew.c	\
		./ft_lstadd_front.c	\
		 ./ft_lstsize.c	\
		 ./ft_lstlast.c	\
		 ./ft_lstadd_back.c \

SRCS = \
	$(SRC_PART1)    \
	$(SRC_PART2)	\
	$(BONUS) \
	
	
OBJS = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

bonus:$(NAME) $(BONUS_OBJ) 
		$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJ)


.c.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(RMFLAG) $(OBJS) $(BONUS_OBJ)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean fclean re
