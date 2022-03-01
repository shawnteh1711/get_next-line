NAME		:= get_next_line.a
# CC			:= gcc
# CFLAGS		:= -Wall -Werror -Wextra -c -g -fsanitize=address
AR			= ar rcs
RM			= rm -f
SRCS		= get_next_line.c get_next_line_utils.c
OBJS     	= ${SRCS:.c=.o}


all			: $(NAME)

# Colors
GREEN		= \033[1;32m
RED			= \033[1;31m

# $(NAME)		:
# 				@echo "$(GREEN) Compiling Files"
# 				@$(CC) -o $(NAME) $(CFLAGS) $(SRCS)
	
$(NAME)		:   $(OBJS)
				@echo "$(GREEN) Compiling Files"
				@$(AR) $(NAME) $(OBJS)

test		:
				gcc main.c -g get_next_line.c get_next_line_utils.c get_next_line.h && ./a.out

test2		:
				gcc main.c -g get_next_line.c get_next_line_utils.c get_next_line.h

clean		:
				@echo "$(RED) Temporary Files Deleted"
				@$(RM) $(OBJS)

fclean		: 	clean
				@echo "$(RED) Execuatable Files Deleted"
				@$(RM) $(NAME)

re			: fclean all

PHONY		: clean fclean re all