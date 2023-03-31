SRCS = srcs/push_swap.c \
	   srcs/push_swap_utils.c \
	   srcs/mvts_s.c \
	   srcs/mvts_pr.c \
	   srcs/medium.c \
	   srcs/big.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror
NAME = push_swap

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

.c.o :
	@gcc ${FLAGS} -I push_swap.h -c $< -o ${<:.c=.o}

all: ${OBJS}
	@make -C ./libft/
	@make -C ./ft_printf/
	@mv ./libft/libft.a ./libft.a
	@mv ./ft_printf/libftprintf.a ./libftprintf.a
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc ${FLAGS}  -o ${NAME} libft.a libftprintf.a ${OBJS}
	@echo $(GREEN)"     - Compiled -"$(NONE)
	@rm -f $(OBJS)
	@rm ./libft.a
	@rm ./libftprintf.a
	@make fclean -C ./libft/
	@make fclean -C ./ft_printf
	@echo $(CURSIVE)$(GRAY) "     - Deleted object files" $(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -f ${OBJS}
	@echo $(GREEN)"     - Removed -"$(NONE)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -f $(NAME) libft.a libftprintf.a
	@make fclean -C ./libft/
	@make fclean -C ./ft_printf/
	@echo $(GREEN)"     - Removed -"$(NONE)

re: fclean all

.PHONY : .c.o all bonus clean fclean re