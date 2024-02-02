#ifndef IMAGE_H
# define IMAGE_H
# include "cub3d.h"
# include "../minilibx-linux/mlx.h"
# include "../utils/libft/libft.h"
# include <math.h>

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;


#endif