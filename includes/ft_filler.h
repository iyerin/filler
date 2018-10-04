#ifndef FT_FILLER_H
# define FT_FILLER_H

# include <stdio.h>
# include "./libft.h"
# include <stdlib.h>

typedef struct	s_figure
{
	int			x;
	int 		y;
}				t_figure;


int g_field_width;
int g_field_heigth;
int g_player_number;
int g_figure_heigth;
int g_figure_width;
int g_min_x;
int	g_min_y;
int g_inner_width;
int g_inner_heigth;
int g_stars;
int g_x;
int g_y;
char g_enemy_figure;
char g_my_figure;

//t_figure g_figure;


#endif


// t_figure **ft_get_figure()
// {
// 	char *str;
// 	t_figure **figure_cord;
// 	int i = 0;
// 	int x = 0;

// 	while(get_next_line(0, &str))
// 	{
// 		if(str[x] == '*')
// 		{
// 			figure_cord[i] = malloc(sizeof(t_figure));
// 			figure_cord[i]->x = x;
// 			figure_cord[i]->y = i;
// 		}
// 		i++;
// 		x = 0;
// 	}
// 	return(figure_cord);
// }

/*
.............
.............
.............
.............
..........*..
..........***
.........*.*.
...........*.
.............
.............
*/

			//field_arr[i] = (unsigned char*)ft_strsub(str, 4, g_field_width);
			// while (print < g_field_width)
			// {
			// 	dprintf(fd, "%d", field_arr[i][print]);
			// 	print++;
			// }
			// j = 4;
			// print = 0;

						// while(print < g_field_width)
			// {
			// 	dprintf(fd, "%d", field_arr[i][print]);
				
			// 	print++;
			// }
			// dprintf(fd, "\n");