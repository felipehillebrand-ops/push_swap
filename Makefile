# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 21:06:09 by fjose-hi          #+#    #+#              #
#    Updated: 2026/01/15 19:22:27 by fjose-hi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./Libft

SRC = ft_initialization.c ft_checklist.c ft_checklist_utils.c ft_sorting.c \
      ft_tiny_sort.c ft_push_chunks_to_b.c ft_push_back_to_a.c ft_swap.c \
	  ft_push.c ft_rotate.c ft_rev_rotate.c ft_stack.c ft_stack2.c

MAIN = main.c

BONUSSRC = ft_checker_bonus.c

OBJ = $(SRC:.c=.o)
MAINOBJ = $(MAIN:.c=.o)
BONUSOBJ = $(BONUSSRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) 
bonus: $(NAME_BONUS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ) $(MAINOBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MAINOBJ) $(LIBFT)

$(NAME_BONUS): $(LIBFT) $(OBJ) $(BONUSOBJ)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ) $(BONUSOBJ) $(LIBFT)
	
clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(MAINOBJ) $(BONUSOBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus