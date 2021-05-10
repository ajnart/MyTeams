##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

define rich_echo
[ -t 1 ] && echo -e "\e[1m$(1)\e[0m\t$(2)" || echo -e "$(1)\t$(2)"
endef

NAME	=	MyTeams

MAKEFLAGS += --no-print-directory

ifneq (,$(findstring debug,$(MAKECMDGOALS)))
	CFLAGS += -D__DEBUG -g3
endif

ifneq (,$(findstring tests,$(MAKECMDGOALS)))
	CFLAGS += -D__TESTS -lcriterion --coverage
endif

all::	$(NAME)

$(NAME):
	@make -C server
	@make -C cli

clean:
	@find . -name "*.o" -delete
	@find . -name "*.gc*" -delete
	@make clean -C server
	@make clean -C cli

fclean:
	@find . -name "myteams_*" -delete
	@find . -name "tests_run" -delete
	@make fclean -C server
	@make fclean -C cli

re::
	@make clean -C server $(MAKECMDGOALS)
	@make clean -C cli $(MAKECMDGOALS)
re::
	@make -C server $(MAKECMDGOALS)
	@make -C cli $(MAKECMDGOALS)

tests_run:
	@make -C server $(MAKECMDGOALS)
	@make -C cli $(MAKECMDGOALS)

debug:
	@make debug -C server $(MAKECMDGOALS) 
	@make debug -C cli $(MAKECMDGOALS)

cli:
	@make -C cli
server:
	@make -C server

.PHONY: tests_run re fclean clean all message debug cli server