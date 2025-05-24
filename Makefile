NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iinclude
AR = ar rcs
RM = rm -f

SRC_DIR = ./src/

SRCS	= $(SRC_DIR)ft_printf.c \
		  $(SRC_DIR)ft_printf_utils.c \
		  $(SRC_DIR)ft_printf_c.c \
		  $(SRC_DIR)ft_printf_s.c \
		  $(SRC_DIR)ft_printf_u.c \
		  $(SRC_DIR)ft_printf_di.c \
		  $(SRC_DIR)ft_printf_di_utils.c \
		  $(SRC_DIR)ft_printf_pxX.c \
		  $(SRC_DIR)ft_printf_pxX_utils.c \
		  $(SRC_DIR)ft_printf_type_utils.c \

OBJS = $(SRCS:%.c=%.o)

.SECONDARY: $(OBJS)

all : $(NAME)

$(NAME) : $(OBJS)
	@make all -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: all

clean :
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
