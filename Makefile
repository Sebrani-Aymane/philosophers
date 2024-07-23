NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c philo.c time.c
OBJ = $(SRC:.c=.o)
INCLUDES = philo.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
