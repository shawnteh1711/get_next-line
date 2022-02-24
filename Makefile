NAME		:= get_next_line
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -c -g
SRCS		= get_next_line.c


all			: $(NAME)

# Colors
GREEN		= \033[1;32m
RED			= \033[1;31m

$(NAME)		:
				@echo "$(GREEN) Compiling Files"
				@$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

test		:
				gcc main.c -g get_next_line.c get_next_line_utils.c get_next_line.h && ./a.out

test2		:
				gcc main.c -g get_next_line.c get_next_line_utils.c get_next_line.h

clean		:
				@echo "$(RED) Temporary Files Deleted"
				@rm -f $()

fclean		: 	clean
				@echo "$(RED) Execuatable Files Deleted"
				@rm -f $(NAME)

re			: fclean all

PHONY		: clean fclean re all