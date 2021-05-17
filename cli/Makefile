##
## EPITECH PROJECT, 2021
## B-CPP-300-BDX-3-1-CPPD06-thomas.camlong [SSH: Laptop-Epitech]
## File description:
## Makefile
##

NAME		= 	myteams_cli


SOURCE_DIR	= 	src

TEST_SRC	= 	$(shell find $(TEST_DIR) -name "*.cpp")

SRC			=	$(shell find $(SOURCE_DIR) -name "*.c" -not -path "./$(TEST_DIR)/*")

CFLAGS		=	-Wall -Wextra -Iinclude -I../libs/myteams -L../libs/myteams/ -Wimplicit-fallthrough=0

TEST_DIR	= 	tests

TEST_SRC	= 	$(shell find $(TEST_DIR) -name "*.cpp")

TESTSFLAGS = -lgtest -lgtest_main -lpthread --coverage -D__TESTS

ifneq (,$(findstring debug,$(MAKECMDGOALS)))
	DEBUG = 1
	CFLAGS += -g3 -D DEBUG
endif

OBJ		=	$(SRC:.c=.o)

TEST_OBJ =	$(TEST_SRC:.cpp=.o)

all::	$(NAME)

all::	message

MAKEFLAGS += j

message:
	@echo -e "\e[38;5;33;1m"
	@figlet $(NAME); exit 0
	@echo -e "\e[0m"
	@echo -e "\e[1m[INFO]\t\e[33mCompilation successful 🔧\e[0m"
ifeq ($(DEBUG), 1)
	@echo -e "\e[1m[INFO]\t\e[33mDebug config : \e[92mON\e[0m"
else
	@echo -e "\e[1m[INFO]\t\e[33mDebug config : \e[91mOFF\e[0m"
endif

$(NAME):
	$(CC) -o $(NAME) $(CFLAGS) -O3 $(SRC)
	@cp $(NAME) ../

debug:: clean
debug:: all
debug:: message

tests_run:
	$(CXX) -o tests_run $(SRC) $(TEST_SRC) $(CFLAGS) $(TESTSFLAGS)
	@./tests_run
	@gcovr --exclude tests; echo -e "gcovr not found"
	@echo -e "\e[1m[INFO]\t\e[92mTests finished ✔\e[0m"

clean:
	@find . -name "*.*gc*" -delete
	@find . -name "*.o" -delete
	@echo -e "\e[1m[C]\tClean $(NAME) OK\e[0m"

fclean:	clean
	@rm -rf myteams_cli
	@echo -e "\e[1m[C]\tFClean $(NAME) OK\e[0m"

re::	fclean
re::	all

.PHONY: all clean fclean re tests_run cpp debug
.NOTPARALLEL: tests_run