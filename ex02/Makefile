NAME = main
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC = 	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rfd $(NAME) target_shruberry

fclean: clean
	rm -rfd $(OBJ)

re: fclean all