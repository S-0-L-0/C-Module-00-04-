# Variabili
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = harl

# File sorgente
SRCS = main.cpp Harl.cpp

# File oggetto
OBJS = $(SRCS:.cpp=.o)

# Regola principale
all: $(NAME)

# Creazione eseguibile
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compilazione file oggetto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pulizia file oggetto
clean:
	rm -f $(OBJS)

# Pulizia completa
fclean: clean
	rm -f $(NAME)

# Ricompilazione
re: fclean all

# Target per test rapido
test: $(NAME)
	@echo "=== Quick test ==="
	@echo "Testing DEBUG:"
	@./$(NAME) | grep -A1 "Testing DEBUG"
	@echo "\nTesting ERROR:"
	@./$(NAME) | grep -A1 "Testing ERROR"

.PHONY: all clean fclean re test