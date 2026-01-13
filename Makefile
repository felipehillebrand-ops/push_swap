# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 21:06:09 by fjose-hi          #+#    #+#              #
#    Updated: 2026/01/12 21:37:52 by fjose-hi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./Libft

# --- Source Files ---
# Shared source files (used by both push_swap and checker)
SHARED_SRC = ft_initialization.c ft_checklist.c ft_checklist_utils.c ft_sorting.c \
             ft_tiny_sort.c ft_push_chunks_to_b.c ft_push_back_to_a.c ft_swap.c \
             ft_push.c ft_rotate.c ft_rev_rotate.c ft_stack.c ft_stack2.c

# Main push_swap source file
PUSH_SWAP_SRC = push_swap_main.c

# Checker source file
CHECKER_SRC = checker.c

# --- Object Files ---
SHARED_OBJ = $(SHARED_SRC:.c=.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SHARED_OBJ) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SHARED_OBJ) $(PUSH_SWAP_OBJ) $(LIBFT)

checker: $(LIBFT) $(SHARED_OBJ) $(CHECKER_OBJ)
	$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(SHARED_OBJ) $(CHECKER_OBJ) $(LIBFT)

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(SHARED_OBJ) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(CHECKER_NAME)

re: fclean all

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: checker

.PHONY: all clean fclean re bonus checker