NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS	= ft_printf.c ft_printf_utils.c ft_printf_percent.c  \
		  ft_printf_c.c ft_printf_s.c ft_printf_u.c ft_printf_di.c \
		  ft_printf_pxX.c ft_printf_pxX_utils.c ft_printf_type_utils.c \
		  ft_printf_di_utils.c

BNS_SRCS =ft_printf_bonus.c ft_printf_utils_bonus.c \
		  ft_printf_percent_bonus.c ft_printf_c_bonus.c \
		  ft_printf_s_bonus.c ft_printf_u_bonus.c \
		  ft_printf_di_bonus.c ft_printf_pxX_bonus.c \
		  ft_printf_pxX_utils_bonus.c ft_printf_type_utils_bonus.c \
		  ft_printf_di_utils_bonus.c

OBJS = $(SRCS:%.c=%.o)

BNS_OBJS = $(BNS_SRCS:%.c = %.o)

AR = ar rcs

RM = rm -f

FLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(BNS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJ_FILES)

%.o : %.c
	gcc $(FLAGS) -c $< -I./ -o $@

bonus :
	make WITH_BONUS=0 all

clean :
	$(RM) $(OBJS) $(BNS_OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re bonus
