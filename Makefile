# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 17:23:49 by nfakih            #+#    #+#              #
#    Updated: 2025/08/19 17:23:49 by nfakih           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long

SRC = main.c \
	get_next_line/get_next_line_bonus.c \
	ft_printf/ft_printf.c ft_printf/ft_putchar_fd.c ft_printf/ft_putnbr_base.c \
	ft_printf/ft_putstr_fd.c \
	Libft/ft_atoi.c Libft/ft_itoa.c Libft/ft_memset.c Libft/ft_putendl_fd.c \
	Libft/ft_split.c Libft/ft_strchr.c Libft/ft_strdup.c Libft/ft_strjoin.c \
	Libft/ft_strlcat.c Libft/ft_strlcpy.c Libft/ft_strlen.c Libft/ft_strncmp.c \
	Libft/ft_strnstr.c Libft/ft_strrchr.c Libft/ft_strstr.c Libft/ft_strtrim.c \
	Libft/ft_substr.c small.c parsing.c validation.c keys.c draw.c rendering.c

OBJ     = $(SRC:.c=.o)

CC      = cc
CFLAGS  = -Wall -Werror -Wextra -Iminilibx-linux -g -Ift_printf -Iget_next_line -ILibft

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(MLX_LIB):
	@echo "🎨 Building MinilibX..."
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo "🏂 done making MinilibX"

$(NAME): $(MLX_LIB) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
	@echo "🏂 done making $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1
	@echo "💄 done cleaning"

fclean: clean
	@rm -f $(NAME)
	@echo "👺 done fcleaning"

re: fclean all

.PHONY: all clean fclean re