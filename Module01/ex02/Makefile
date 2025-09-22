# Variabili
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = brain

# File sorgente (solo main.cpp)
SRCS = main.cpp

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

.PHONY: all clean fclean re