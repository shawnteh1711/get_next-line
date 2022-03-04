NAME		:= libget_next_line.a
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -c -g -fsanitize=address
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
				@echo "(GREEN) Running Program"
				@$(CC) main.c -g get_next_line.a && ./a.out

test		:
				gcc main.c -g get_next_line.c get_next_line_utils.c get_next_line.h && ./a.out

test2		:
				gcc main.c -g get_next_line.c get_next_line_utils.c get_next_line.h

bonus		:
				gcc main.c -g get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.h && ./a.out


clean		:
				@echo "$(RED) Temporary Files Deleted"
				@$(RM) $(OBJS)

fclean		: 	clean
				@echo "$(RED) Execuatable Files Deleted"
				@$(RM) $(NAME)

re			: fclean all

PHONY		: clean fclean re all