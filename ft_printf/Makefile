NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS	= ft_printf_bonus.c ft_printf_utils_bonus.c\
		  ft_printf_percent_bonus.c ft_printf_c_bonus.c\
		  ft_printf_s_bonus.c ft_printf_u_bonus.c\
		  ft_printf_di_bonus.c ft_printf_pxX_bonus.c\
		  ft_printf_pxX_utils_bonus.c ft_printf_type_utils_bonus.c\
		  ft_printf_di_utils_bonus.c

OBJS = $(SRCS:%.c=%.o)
.SECONDARY: $(OBJS)
AR = ar rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

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

.PHONY : all clean fclean re bonus
