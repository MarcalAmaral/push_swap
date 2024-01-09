# tool macros
CC = cc
CFLAGS = -g -Wall -Werror -Wextra 

# path macros
OBJ_PATH = obj
SRC_PATH = src
PATH_LIBFT = lib/libft
PATH_LIBFTLIB = $(PATH_LIBFT)/libft.a

# compile macros
NAME = push_swap

SRC_FILES = src/validations.c

INCLUDE = -I./inc

AUX_FILES = src/aux/*.c

FILE_TESTE = tests/main_test.cpp \
			 tests/v01/01.cpp

$(NAME): $(PATH_LIBFTLIB)
	$(CC) $(CFLAGS) $(AUX_FILES) $(SRC_FILES) $(INCLUDE) -o $@ $(PATH_LIBFTLIB)

$(PATH_LIBFTLIB):
	$(MAKE)	-C $(PATH_LIBFT)

all: $(NAME)

clean:
	@$(MAKE) -C $(PATH_LIBFT) clean

fclean: clean
	@$(MAKE) -C $(PATH_LIBFT) fclean
	@rm -f $(NAME)

re: fclean all

runTests: $(PATH_LIBFTLIB)
	g++ $(SRC_FILES) $(AUX_FILES) $(INCLUDE) $(FILE_TESTE) -I/usr/local/include -L/usr/local/lib -lgtest -lgtest_main -o test $(PATH_LIBFTLIB)
	./test

.PHONY: all clean fclean re runTests