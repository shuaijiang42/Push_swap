NAME = push_swap

SOURCES = data_parsing.c movement.c movement2.c stack_utiles.c algorithm.c \
free.c build_stack_a.c get_target.c sort_until_five.c main.c 
# BONUS_SOURCES = 
		
OBJECTS = $(SOURCES:.c=.o)
# BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

LIB = libft/libft.a

CC = gcc
CFLAGS += -Wextra -Werror -Wall  -I ./libft #-g3 -fsanitize=address
 
all: $(NAME) 

$(NAME): $(OBJECTS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -o $(NAME)


# bonus: $(BONUS_OBJECTS)
#	ar rcs $(NAME) $(BONUS_OBJECTS)

clean:
	make clean -C libft
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean:
	make fclean -C libft
	rm -f $(NAME) $(OBJECTS)

re: fclean all 
.SILENT: