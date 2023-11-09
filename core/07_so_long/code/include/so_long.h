/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:56:55 by groka             #+#    #+#             */
/*   Updated: 2023/08/06 16:20:49 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 96
# define HEIGHT 96

# define IMG_WALL_PATH	"./assets/pic/norminette_01.png"
# define IMG_BG_PATH	"./assets/pic/space.png"
# define IMG_PATH_PATH	"./assets/pic/blood_01.png"
# define IMG_COLL_PATH	"./assets/pic/towel_01.png"
# define IMG_EXIT_PATH	"./assets/pic/42_comp.png"
# define IMG_PLAYER_PATH	"./assets/pic/bloody_marvin.png"
# define IMG_OPEN_PATH	"./assets/pic/open.png"
# define IMG_END_PATH	"./assets/pic/END_IN_TEARS.png"

# define Z_IMG_WALL	1
# define Z_IMG_BG	-1
# define Z_IMG_PATH	0
# define Z_IMG_COLL	2
# define Z_IMG_EXIT	2
# define Z_IMG_OPEN	51
# define Z_IMG_PLAYER	50
# define Z_IMG_END 20

# define ERROR_MSG_MLX_MALLOC	"Malloc error (mlx)"
# define ERRMSG_TEXTURE_WALL	\
"something is very baad with the TEXTURE of the WALLS"
# define ERRMSG_TEXTURE_PLAYER	\
"something is very baad with the TEXTURE of the PLAYER"
# define ERRMSG_TEXTURE_PATH	\
"something is very baad with the TEXTURE of the PATH"
# define ERRMSG_TEXTURE_COLL	\
"something is very baad with the TEXTURE of the COLLECTABLES"
# define ERRMSG_TEXTURE_EXIT	\
"something is very baad with the TEXTURE of the EXIT"
# define ERRMSG_TEXTURE_BG	\
"something is very baad with the TEXTURE of the BACKGROUND"
# define ERRMSG_TEXTURE_OPEN	\
"something is very baad with the TEXTURE of the OPEN image"
# define ERRMSG_TEXTURE_END	\
"something is very baad with the TEXTURE of the END image"
# define ERRMSG_INSTANCE	"couldn't make a new instance"

# define ERROR_MSG_MAP_WALL	"The map walls are not persistent"
# define ERRMSG_NO_ITEMS	"A vital element is missing from the map"
# define ERRMSG_ROADS	"Issue with the pathways to all elements"
# define ERRMSG_NO_ARGUMENT	"One file requires a command line argument"
# define ERRMSG_FILE_EXTENSION	"Incorrect file extension"
# define ERRMSG_FILE_OPEN	"Unable to open the file"
# define ERRMSG_FILE_FORMAT	"Invalid map format"
# define ERRMSG_FILE_EMPTY	"File is empty"
# define ERRMSG_FILE_READING	"Issue with reading the file"
# define ERRMSG_FILE_CHAR	"Incorrect character in the file"
# define ERRMSG_MALLOC	"Memory allocation error"

typedef enum e_boolean {very_false, very_true}	t_boolean;

/**
 * @brief	The role of this structure is
 * 			storing the dimensions of map/matrix
 */
typedef struct s_map_dim
{
	size_t	row;
	size_t	col;
}	t_map_dim;

/**
 * @brief	A struct for coordinations (x, y).
 */
typedef struct s_coordinate
{
	size_t	i;
	size_t	j;
}	t_coordinate;

/**
 * @brief 
 * 
 * index:	index of the instance (patrol or collectable)
 * @note	patrols shouldn't reach the position of a collectable
 * 			or one more index needed.
 * at type 1 is wall 0 is field
 */
typedef struct s_cell
{
	int			type;
	t_boolean	player;
	t_boolean	exit;
	t_boolean	collectable;
	t_boolean	patrol;
	t_boolean	reachable;
	int			i_player;
	int			i_exit;
	int			i_coll;
	int			i_wall;
	int			i_path;
	t_boolean	trail;
}	t_cell;

/**
 * row:			number of rows of the map
 * col:			number of cols of the map
 * collecables: number of collectables
 */
typedef struct s_map_info
{
	size_t	row;
	size_t	col;
	size_t	collectables;
}	t_map_info;

typedef struct s_grid_size
{
	size_t	row;
	size_t	col;
}	t_grid_size;

//QUESTION: which struct has the x and y of a given t_cell thing t_map dim? 
//Or are the totals there
//map is the bigass array
typedef struct s_board
{
	t_map_dim		dim;
	t_cell			**map;
	t_coordinate	player_coord;
	t_grid_size		grid;
	t_coordinate	grid_start;
}	t_board;

///////////////////
// CLASS_BOARD
///////////////////
/**
 * @brief The core of the "class/object board"
 * 			it contains the static variable, the DATA
 * @note	This function is "private", not for usage.
*/
t_board			*class_board(t_cell **map, t_boolean free);

/**
 * @brief	The destructor of the board.
 * 			Delete the map, set zero everything.
 */
void			destructor_of_board(void);

/**
 * @brief Set the map for class board.
 * 
 * @param map 2D matrix.
 */
void			set_map(t_cell **map);

/**
 * @brief Get the map of class board
 * 
 * @return t_cell** The 2D matrix of map.
 */
t_cell			**get_map(void);

/**
 * @brief free the allocated memory of map of class board
 */
void			free_map(void);

/**
 * @brief Set the row of dimension of board.
 * 
 * @param row 
 */
void			set_row(size_t row);

/**
 * @brief Set the collum of dimensions of board.
 * 
 * @param col 
 */
void			set_col(size_t col);

/**
 * @brief Get the row of dimensions of the board.
 * 
 * @return size_t 
 */
size_t			get_row(void);

/**
 * @brief Get the collum of dimensions of the board.
 * 
 * @return size_t 
 */
size_t			get_col(void);

/**
 * @brief Set the player position.
 * 
 * @param x x coordinate of the player.
 * @param y y coodsinate of the player.
 */
void			set_player_pos(size_t x, size_t y);

/**
 * @brief Get the player position.
 * 
 * @return t_coordinate 
 */
t_coordinate	get_player_pos(void);

void			set_grid(size_t row, size_t col);

t_grid_size		get_grid(void);

void			set_grid_start_i(int i);

void			set_grid_start_j(int j);

t_coordinate	get_grid_start(void);

/////////////////////////
//	ERROR_HANDLING
/////////////////////////
/**
 * @brief 
 * 
 * @param msg 
 */
void			error_msg_exit(char *msg);
/**
 * @brief free the map, before exit.
 * 
 */
void			error_freemap_exit(char *msg);

void			error_closemlx_exit(char *msg);

////////////////////////
//	MAP_CREATING
///////////////////////
/**
 * @brief It checks the extension of the file, and tries to open it.
 * 			Exit the program, if something is wrong.
 * 
 * @param file - name of the file to open
 * @return int fd - file descriptor
 */
int				open_file(char *file);

/**
 * @brief 
 * @note every line of the map should end with \n (new line)
 * @param file 
 */
void			dimension_fill(char *file);

/**
 * @brief 
 * 
 */
void			create_map(char	*file);

///////////////////
// MAP VALIDATION
//////////
t_boolean		map_validation(void);

///////////////////////
void			mother_of_destructors(void);

//////////////////////////
// CLASS MLX
//////////////////////////
mlx_t			*class_mlx(void);

void			run_mlx(void);

mlx_t			*get_mlx(void);

void			set_window(void);

void			images_to_mlx(void);

//////////////////////////
// CLASS IMG WALL
///////////////////////////
/* private */
mlx_image_t		*class_img_wall(mlx_texture_t *texture);
/* public */
void			set_texture_wall(char *file);

mlx_image_t		*get_img_wall(void);

int				new_instance_wall(int x, int y);

void			show_insta_img_wall(int index, int i, int j);
void			hide_insta_img_wall(int index);

//////////////////////////
// CLASS IMG PATH
///////////////////////////
/* private */
mlx_image_t		*class_img_path(mlx_texture_t *texture);
/* public */
void			set_texture_path(char *file);

mlx_image_t		*get_img_path(void);

int				new_instance_path(int x, int y);

void			show_insta_img_path(int index, int i, int j);
void			hide_insta_img_path(int index);

//////////////////////////
// CLASS IMG COLL
///////////////////////////
/* private */
mlx_image_t		*class_img_coll(mlx_texture_t *texture);
/* public */
void			set_texture_coll(char *file);

mlx_image_t		*get_img_coll(void);

int				new_instance_coll(int x, int y);

void			show_insta_img_coll(int index, int i, int j);
void			hide_insta_img_coll(int index);

/**
 * @brief instacollhide
 * 
 * @param index 
 */
void			insta_coll_hide(int index);

//////////////////////////
// CLASS IMG PLAYER
///////////////////////////
/* private */
mlx_image_t		*class_img_player(mlx_texture_t *texture);
/* public */
void			set_texture_player(char *file);

mlx_image_t		*get_img_player(void);

int				new_instance_player(int x, int y);

void			show_insta_img_player(int index, int i, int j);
void			hide_insta_img_player(int index);

//////////////////////////
// CLASS IMG EXIT
///////////////////////////
/* private */
mlx_image_t		*class_img_exit(mlx_texture_t *texture);
/* public */
void			set_texture_exit(char *file);

mlx_image_t		*get_img_exit(void);

int				new_instance_exit(int x, int y);

void			show_insta_img_exit(int index, int i, int j);
void			hide_insta_img_exit(int index);

//////////////////////////
// CLASS IMG BACKGROUND
///////////////////////////
/* private */
mlx_image_t		*class_img_bg(mlx_texture_t *texture);
/* public */
void			set_texture_bg(char *file);

mlx_image_t		*get_img_bg(void);

int				new_instance_bg(int x, int y);

void			destructor_of_img_bg(void);

//////////////////////////
// CLASS IMG OPEN
///////////////////////////
mlx_image_t		*class_img_open(mlx_texture_t *texture);
void			set_texture_open(char *file);
mlx_image_t		*get_img_open(void);
int				new_instance_open(int x, int y);
void			insta_open_hide(int index);
void			show_insta_img_open(int index, int i, int j);
void			hide_insta_img_open(int index);

////////////////////////
// CLASS IMG END
////////////////////////
mlx_image_t		*class_img_end(mlx_texture_t *texture);
void			set_texture_end(char *file);
mlx_image_t		*get_img_end(void);
int				new_instance_end(int x, int y);
void			insta_end_hide(int index);
void			show_insta_img_end(int index, int i, int j);
void			hide_insta_img_end(int index);

/////////////////////////
// HOOKS
//////////////////////
void			keyhook(mlx_key_data_t keydata, void *param);

///////////////////////////
// TIME TO PLAY
//////////////////////

void			move_player(int x, int y);
t_boolean		is_it_done(void);
void			finish_it(void);
t_boolean		is_it_finished(void);

/////////////
// GRID VIEW
//////////

void			view(void);
void			grid(void);
void			hide_all_insta(void);

#endif
