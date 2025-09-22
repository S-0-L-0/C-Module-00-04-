# Variabili
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = sed_replacer

# File sorgente
SRCS = main.cpp StringReplacer.cpp

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
	rm -f *.replace

# Ricompilazione
re: fclean all

# Target per eseguire test automatici
test: $(NAME) test-files
	@echo "=== Running automated tests ==="
	@echo "\n1. Test basic replacement:"
	./$(NAME) test_files/input.txt "Hello" "Hi"
	@echo "\n2. Test multiple occurrences:"
	./$(NAME) test_files/input2.txt "fox" "cat"
	@echo "\n3. Test repeated pattern:"
	./$(NAME) test_files/repeated.txt "AA" "BB"
	@echo "\n4. Test empty replacement:"
	./$(NAME) test_files/input.txt "world" ""
	@echo "\n5. Test non-existent pattern:"
	./$(NAME) test_files/input.txt "xyz" "abc"
	@echo "\n=== Test completed! Check .replace files ==="

.PHONY: all clean fclean re test-files test