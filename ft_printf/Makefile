$(info BNS_OBJS = $(BNS_OBJS))
$(info OBJ_FILES = $(OBJ_FILES))

NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS	= ft_printf.c ft_printf_utils.c ft_printf_percent.c\
		  ft_printf_c.c ft_printf_s.c ft_printf_u.c ft_printf_di.c\
		  ft_printf_pxX.c ft_printf_pxX_utils.c ft_printf_type_utils.c\
		  ft_printf_di_utils.c

BNS_SRCS =ft_printf_bonus.c ft_printf_utils_bonus.c\
		  ft_printf_percent_bonus.c ft_printf_c_bonus.c\
		  ft_printf_s_bonus.c ft_printf_u_bonus.c\
		  ft_printf_di_bonus.c ft_printf_pxX_bonus.c\
		  ft_printf_pxX_utils_bonus.c ft_printf_type_utils_bonus.c\
		  ft_printf_di_utils_bonus.c

OBJS = $(SRCS:%.c=%.o)

BNS_OBJS = $(BNS_SRCS:%.c=%.o)

AR = ar rcs

RM = rm -f

CC = cc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

%_bonus.o:%_bonus.c
	$(CC) $(FLAGS) -c $< -o $@

%.o:%.c
	$(CC) $(FLAGS) -c $< -I./ -o $@

bonus : all $(BNS_OBJS)
	$(AR) $(NAME) $(BNS_OBJS)

clean :
	$(RM) $(OBJS) $(BNS_OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re bonus
