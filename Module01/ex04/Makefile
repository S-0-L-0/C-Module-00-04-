CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = sed_replacer

SRCS = main.cpp StringReplacer.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.replace

re: fclean all

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