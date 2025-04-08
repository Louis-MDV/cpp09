
NAME = btc

CXX 		= 	c++
CXXFLAGS	= 	-Wall -Wextra -Werror -std=c++98

RED			= 	$(shell tput setaf 1)
GREEN		= 	$(shell tput setaf 2)
YELLOW		= 	$(shell tput setaf 3)
NC			= 	$(shell tput sgr0)

SRCS = main.cpp BitcoinExchange.cpp

OBJECTS 	= 	$(SRCS:.cpp=.o)

# Default target (what will run when you type 'make')
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Rule to compile .cpp files into .o files
%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up object files and the executable
clean:
	rm -f $(OBJECTS) $(NAME)

fclean: clean
	@rm -f $(NAME)
	@printf  "[cpp09:ex00] $(RED)Cleaned all!$(RESET)\n" 

re: fclean all

.PHONY: all clean fclean re
