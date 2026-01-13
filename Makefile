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
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./Libft

SRC = ft_initialization.c ft_checklist.c ft_checklist_utils.c ft_sorting.c \
      ft_tiny_sort.c ft_push_chunks_to_b.c ft_push_back_to_a.c ft_swap.c \
	  ft_push.c ft_rotate.c ft_rev_rotate.c ft_stack.c ft_stack2.c

BONUSSRC = ft_putchar2.c

OBJ = $(SRC:.c=.o)
BONUSOBJ = $(BONUSSRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) 

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	
clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: .bonus

.bonus: $(LIBFT) $(OBJ) $(BONUSOBJ)
	touch .bonus
	ar rcs $(NAME) $(LIBFT) $(OBJ) $(BONUSOBJ)

.PHONY: all clean fclean re bonus