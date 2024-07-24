NAME 	= philo
CC		= cc -Wall -Wextra -Werror -g
SRC		= $(wildcard src/*.c)
OBJ		= $(SRC:.c=.o)
HEADER	= include/philo.h
IFLAG	= -I./include

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(IFLAG) -o $(NAME)

%.o: %.c $(HEADER)	
	@$(CC) -c $< -o $@ $(IFLAG)

clean:
	@rm -f src/*.o
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: philo all clean fclean re
