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

clean		:
				@echo "$(RED) Temporary Files Deleted"
				@rm -f $()

fclean		: 	clean
				@echo "$(RED) Execuatable Files Deleted"
				@rm -f $(NAME)

re			: fclean all

PHONY		: clean fclean re all