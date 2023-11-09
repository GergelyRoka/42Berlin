# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groka <groka@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 13:00:31 by groka             #+#    #+#              #
#    Updated: 2023/08/06 13:00:31 by groka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ls *.c | tr ' ' '\n' | xclip -sel clip
# ls */*.c | tr ' ' '\n' | xclip -sel clip


NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a
SRCS	:=	src/main.c \
			src/mother_of_destructors.c \
			src/class_board/class_board.c \
			src/class_board/grid.c \
			src/class_board/info.c \
			src/class_board/map.c \
			src/class_board/player_pos.c \
			src/class_img_background/class_background.c \
			src/class_img_background/img_bg_visibility.c \
			src/class_img_collectables/class_img_collectables.c \
			src/class_img_collectables/img_collectables_visibility.c \
			src/class_img_end/class_img_end.c \
			src/class_img_end/img_end_visibility.c \
			src/class_img_exit/class_img_exit.c \
			src/class_img_exit/img_exit_visibility.c \
			src/class_img_open/class_img_open.c \
			src/class_img_open/img_open_visibility.c \
			src/class_img_path/class_img_path.c \
			src/class_img_path/img_path_visibility.c \
			src/class_img_player/class_img_player.c \
			src/class_img_player/img_player_visibility.c \
			src/class_img_wall/class_img_wall.c \
			src/class_img_wall/img_wall_visibility.c \
			src/class_mlx/class_mlx.c \
			src/class_mlx/set_up_images.c \
			src/class_mlx/set_window.c \
			src/error_handling/error_closemlx_exit.c \
			src/error_handling/error_freemap_exit.c \
			src/error_handling/error_msg_exit.c \
			src/grid_view/grid.c \
			src/grid_view/view.c \
			src/hooks/keyhook.c \
			src/map_creating/create_map.c \
			src/map_creating/dimension_fill.c \
			src/map_creating/open_file.c \
			src/map_validation/map_validation.c \
			src/time_to_play/is_it_done.c \
			src/time_to_play/is_it_finished.c \
			src/time_to_play/move_player.c

OBJS	:= ${SRCS:.c=.o}
DEPS	:= ./include/so_long.h

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

%.o: %.c $(DEPS) #-fsanitize=address -g
	@$(CC) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)  #-fsanitize=address -static-libsan
	@$(CC)  $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: clean all

.PHONY: all, clean, fclean, re, libmlx