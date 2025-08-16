NAME    = so_long

SRC =	 main.c \
	get_next_line/get_next_line_bonus.c \
	ft_printf/ft_printf.c ft_printf/ft_putchar_fd.c ft_printf/ft_putnbr_base.c \
	ft_printf/ft_putstr_fd.c \
	Libft/ft_atoi.c Libft/ft_itoa.c Libft/ft_memset.c Libft/ft_putendl_fd.c \
	Libft/ft_split.c Libft/ft_strchr.c Libft/ft_strdup.c Libft/ft_strjoin.c \
	Libft/ft_strlcat.c Libft/ft_strlcpy.c Libft/ft_strlen.c Libft/ft_strncmp.c \
	Libft/ft_strnstr.c Libft/ft_strrchr.c Libft/ft_strstr.c Libft/ft_strtrim.c \
	Libft/ft_substr.c  parsing.c\


OBJ     = $(SRC:.c=.o)

CC      = cc
CFLAGS  =  -Ift_printf -Iget_next_line -ILibft

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "🏂 done making"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "💄 done cleaning"

fclean: clean
	@rm -f $(NAME)
	@echo "👺 done fcleaning"

re: fclean all

.PHONY: all clean fclean re
