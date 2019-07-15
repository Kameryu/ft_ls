# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msorin <msorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 14:12:05 by msorin            #+#    #+#              #
#    Updated: 2017/12/09 14:12:13 by msorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls

SRCS_NAME=	add_time.c \
			clean_info.c \
			copy_dirent.c \
			ft_aff_detail.c \
			ft_error.c \
			ft_ls.c \
			ft_print_data.c \
			get_block.c \
			get_gu_name.c \
			get_guid.c \
			get_indir_doc.c \
			get_length.c \
			get_mode.c \
			get_nlink.c \
			main.c \
			opt_managment.c \
			print_ls.c \
			s_doc.c \
			set_color.c \
			set_detail.c \
			sort_file_list.c \
			sort_ls.c

SRCS = $(addprefix srcs/,$(SRCS_NAME))

HEADER_NAME = define.h ft_error.h ft_ls.h structure.h

HEADER = $(addprefix incl/,$(HEADER_NAME))

OBJS = $(SRCS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -Wmissing-prototypes

LIBH = -I./libft -I./incl

LIBA = -lft -L./libft

DBG = -g -O0

#===============================#
#		Compilation rules 		#
#===============================#

all: $(NAME)

$(NAME): $(OBJS)
	@(cd libft && $(MAKE))
	@$(CC) $(FLAGS) $(LIBA) $(LIBH) $(OBJS) -o $(NAME)
	@echo "$(NAME) created and indexed"

%.o: %.c
	@$(CC) -c $< $(C_FLAG) $(OPT_FLAG) $(LIBH) -o $@

#===============================#
#		Cleaning rules			#
#===============================#
norme:
	norminette $(SRCS)
	norminette $(HEADER)
	@(cd libft && $(MAKE) $@)

clean:
	@(cd libft && $(MAKE) $@)
	@rm -f $(OBJS)
	@echo "*** Object file cleaned ***"

fclean: clean
	@(cd libft && $(MAKE) $@)
	@rm -f $(NAME)
	@echo "*** $(NAME) cleaned ***"

half: clean $(NAME)

re: fclean all

compile : re
	$(MAKE) fclean

.PHONY: all norme clean fclean half re compile
