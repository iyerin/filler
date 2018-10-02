#include "includes/ft_filler.h"

#define FIGURE(player_number) (player_number == 1) ? 'O' : 'X'



int	ft_put_number(int ***arr, int i, int j, int number, int fd)
{
	int changes = 0;

	//dprintf(fd, "i = %d\nj = %d\nnumber = %c\n", i, j, number);
	if ((j - 1 >= 0) && ((*arr)[i][j - 1] == -3))
	{
		(*arr)[i][j - 1] = number;
		changes = 1;
	}
	if ((j + 1 < g_field_width) && ((*arr)[i][j + 1] == -3))
	{
		(*arr)[i][j + 1] = number;
		changes = 1;
	}
	if ((i - 1 >= 0) && ((*arr)[i - 1][j] == -3))
	{
		(*arr)[i - 1][j] = number;
		changes = 1;
	}
	if ((i + 1 < g_field_heigth) && ((*arr)[i + 1][j] == -3))
	{
		(*arr)[i + 1][j] = number;
		changes = 1;
	}
	return (changes);
}

void ft_fill_field(int ***arr)
{
	int fd = open("myres2", O_WRONLY);

	int number = 1;
	int enemy_figure = -1;
	int i = 0;
	int j = 0;
	int changes = 1;

	while(changes)
	{
		//write(fd, "tyt\n", 4);
		changes = 0;
		while(i < g_field_heigth)
		{
			//write(fd, "tyttyt2\n", 8);
			while(j < g_field_width)
			{
				//write(fd, "tyttyttyt3", 10);
				if((*arr)[i][j] == enemy_figure)
				{
				//	write(fd, "HUHU", 4);
					if(ft_put_number(arr, i, j, number, fd))
						changes = 1;
				}
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
		enemy_figure = number;
		number += 1;
	}
	while(i < g_field_heigth)
	{
		while(j < g_field_width)
		{
			dprintf(fd, "%d ", (*arr)[i][j]);
			j++;
		}
		dprintf(fd, "\n");
		j = 0;
		i++;
	}




	close(fd);
}

void ft_prepare_figure(char ***figure_arr, int fd)
{
	int i = 0;
	int j = 0;

	g_min_x = g_figure_width;
	g_min_y = g_figure_heigth;

	while(i < g_figure_heigth)
	{
		while(j < g_figure_width)
		{
			if ((*figure_arr)[i][j] == '*')
			{
				if (i <= g_min_x)
					g_min_x = i;
				if(j <= g_min_y)
					g_min_y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int ft_figure_fits(int field, char figure, int *cover, int *score)
{
	if (figure == '.')
		return(1);
	else if (figure == '*' && field > 0)
	{
		*score += field;
		return (1);
	}
	else if (figure == '*' && field == -2)
	{
		*cover += 1;
		return (1);
	}
	else
		return(0);

}
 
void ft_put_figure(int **field_arr, char **figure_arr, int fd)
{
	int i = 0;
	int j = 0;

	int x;
	int y;

	int i_field = 0;
	int j_field = 0;
	
	int i_figure = g_min_x;
	int j_figure = g_min_y;
	
	int cover = 0;
	int count = 0;
	int score = 0;
	int best_score = 1000;

	while(i < g_figure_heigth)
	{
		while(j < g_figure_width)
		{
			while(i_figure < g_figure_heigth)
			{
				while(j_figure < g_figure_width)
				{
					if (ft_figure_fits(field_arr[i_field][j_field], figure_arr[i_figure][j_figure], &cover, &score))
						count++;
					j_figure++;
				}
				j_figure = g_min_y;
				i_figure++;
			}
			if((cover = 1) && (count = (g_figure_heigth - g_min_y) * (g_figure_width - g_min_x)))
			{
				if (score < best_score)
				{
					best_score = score;
					x = j_figure - g_min_y;
					y = i_figure - g_min_x;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	dprintf(fd, "x = %d\n, y = %d\n", x, y);
	//write(fd, "tyt", 3);
	//printf("")
}


void ft_get_field_size(char *str)
{
	char **tmp_arr;

	tmp_arr = ft_strsplit(str, ' ');
	g_field_heigth = ft_atoi(tmp_arr[1]);
	g_field_width = ft_atoi(tmp_arr[2]);
	//free tmp_arr

}

void ft_get_figure_size(char *str)
{
	char **tmp_arr;

	tmp_arr = ft_strsplit(str, ' ');
	g_figure_heigth = ft_atoi(tmp_arr[1]);
	g_figure_width = ft_atoi(tmp_arr[2]);
	//free tmp_arr

}

int ft_parser_filler(char **return_str)
{
	int fd = open("myres", O_WRONLY);

	int **field_arr;
	char **figure_arr;
	char *str;
	int i = 0;
	int j = 4;
	int flag = 0;
	int arr_iter = 0;

	int print = 0;
	
	while(get_next_line(0, &str))
	{
		//dprintf(fd, "\nstr = %s", str);

		if (*str == '$')
			g_player_number = str[10] - '0';
		else if ((*(str + 1) == 'l') && (!flag))
		{
			ft_get_field_size(str);
			field_arr = (int**)malloc(sizeof(int*) * g_field_heigth);
			while(arr_iter < g_field_heigth)
			{
				field_arr[arr_iter] = (int*)malloc(sizeof(int) * g_field_width);
				arr_iter++;
			}
			flag = 1;
		}
		else if (*str >= '0' && *str <= '9')
		{

			while(str[j])
			{
				//write(fd, "tyt", 3);
				if (str[j] == 'O')
					field_arr[i][j - 4] = -1;
				if (str[j] == 'X')
					field_arr[i][j - 4] = -2;
				if (str[j] == '.')
					field_arr[i][j - 4] = -3;
				//write(fd, "tyt", 3);
				j++;
			}
			//field_arr[i] = (unsigned char*)ft_strsub(str, 4, g_field_width);
			// while (print < g_field_width)
			// {
			// 	dprintf(fd, "%d", field_arr[i][print]);
			// 	print++;
			// }
			// j = 4;
			// print = 0;
			i++;
			j = 0;
		}

		else if (*(str + 1) == 'i')
		{
			ft_get_figure_size(str);
			figure_arr = (char**)malloc(sizeof(char*) * g_figure_heigth);
			//dprintf(fd, "fig_hei = %d\n", g_figure_heigth);
		}
		else if ((*str == '.') || (*str == '*'))
		{
			figure_arr[j] = ft_strdup(str);
			//dprintf(fd, "fig = %s\n", figure_arr[j]);
			j++;
		}
		else if (*str == '=')
			return (0);
		ft_strdel(&str);		
	}

	ft_fill_field(&field_arr);
	ft_prepare_figure(&figure_arr, fd);
	ft_put_figure(field_arr, figure_arr, fd);

	//dprintf(fd, "min_x = %d\nmin_y = %d\n", g_min_x, g_min_y);



	close(fd);
	return (0);
}

int main(void)
{
	//char **field_arr;
 	//char **figure_arr;
	//char *str;
	char *return_str;	
//int fd2 = open("test", O_RDONLY);

	while (ft_parser_filler(&return_str))
	{
		//ft_fill_field(field_arr);
		// ft_put_figure();
		printf("%s\n", "2 4");
	}
	return (0);
}


// gcc main.c libftprintf.a -o players/iyerin.filler && ./filler_vm -f maps/map00 -p1 players/abanlin.filler -p2 players/iyerin.filler