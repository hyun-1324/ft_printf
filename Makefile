NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS	= ft_printf.c ft_printf_utils.c ft_printf_type_utils.c\
		  ft_printf_c.c ft_printf_s.c ft_printf_u.c\
		  ft_printf_di.c ft_printf_di_utils.c ft_printf_pxX.c\
		  ft_printf_pxX_utils.c\

OBJS = $(SRCS:%.c=%.o)
AR = ar rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

.SECONDARY: $(OBJS)
all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o : %.c ft_printf_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
