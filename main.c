#include "includes/ft_filler.h"

int	ft_put_number(int ***arr, int i, int j, int number)
{
	int changes;

	changes = 0;
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
		changes = 0;
		while(i < g_field_heigth)
		{
			while(j < g_field_width)
			{
				if((*arr)[i][j] == enemy_figure)
				{
					if(ft_put_number(arr, i, j, number))
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

	//ft_fill_field_victory()
	i = 0;
	j = 0;
	int flag = 0;
	while(i < g_field_heigth)
	{
		while(j < g_field_width)
		{
			if ((*arr)[i][j] == -3)
			{
				(*arr)[i][j] = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}


	i = 0;
	j = 0;

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

void ft_figure_measure_heigth(char **figure_arr)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(i < g_figure_heigth)
	{
		while(j < g_figure_width)
		{
			if (figure_arr[i][j] == '*')
			{
				g_inner_heigth++;
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void ft_figure_measure_width(char **figure_arr)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(j < g_figure_width)
	{
		while(i < g_figure_heigth)
		{
			if (figure_arr[i][j] == '*')
			{
				g_inner_width++;
				break;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void ft_prepare_figure(char ***figure_arr)
{
	int i;
	int j;

	i = 0;
	j = 0;

	g_min_x = g_figure_width;
	g_min_y = g_figure_heigth;

	while(i < g_figure_heigth)
	{
		while(j < g_figure_width)
		{
			if ((*figure_arr)[i][j] == '*')
			{
				if (j <= g_min_x)
					g_min_x = j;
				if (i <= g_min_y)
					g_min_y = i;
				g_stars += 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int ft_figure_fits(int field, char figure, int *cover, int *score)
{
	if (field > 0)
	{
		*score += field;
		return (1);
	}
	else if (field == -2)
	{
		*cover += 1;
		return (1);
	}
	else
		return(0);
}
 
void ft_put_figure(int **field_arr, char **figure_arr)
{
	int i_field = 0;
	int j_field = 0;
	
	int res_i_field;
	int res_j_field;

	int i_figure = g_min_y;
	int j_figure = g_min_x;
	
	int cover = 0;
	int count = 0;
	int score = 0;
	int best_score = 100000000;

	
	while((i_field + g_inner_heigth - 1) < g_field_heigth)
	{
		res_i_field = i_field;
		while((j_field + g_inner_width - 1) < g_field_width)
		{
			res_j_field = j_field;
			while(i_figure < g_figure_heigth)
			{
				while(j_figure < g_figure_width)
				{
					if (figure_arr[i_figure][j_figure] == '*')
						if (ft_figure_fits(field_arr[i_field][j_field], figure_arr[i_figure][j_figure], &cover, &score))
							count++;
					j_figure++;
					j_field++;
				}
				j_figure = g_min_x;
				j_field = res_j_field;
				i_figure++;
				i_field++;
			}
			if((cover == 1) && (count == g_stars))
			{
				if (score < best_score)
				{
					best_score = score;
					g_x = res_i_field - g_min_y;
					g_y = res_j_field - g_min_x;
				}
			}
			score = 0;
			cover = 0;
			count = 0;
			i_field = res_i_field;
			j_field = res_j_field;
			j_field++;
			i_figure = g_min_y;
		}
		j_field = 0;
		i_field = res_i_field;
		i_field++;
	}
}

void	*ft_free_arr(void **arr)
{
	size_t i;

	i = 0;
	if (arr == 0)
		return (arr);
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

void ft_get_field_size(char *str)
{
	char **tmp_arr;

	tmp_arr = ft_strsplit(str, ' ');
	g_field_heigth = ft_atoi(tmp_arr[1]);
	g_field_width = ft_atoi(tmp_arr[2]);
	ft_free_arr((void **)tmp_arr);
}

void ft_get_figure_size(char *str)
{
	char **tmp_arr;

	tmp_arr = ft_strsplit(str, ' ');
	g_figure_heigth = ft_atoi(tmp_arr[1]);
	g_figure_width = ft_atoi(tmp_arr[2]);
	ft_free_arr((void **)tmp_arr);
}

void ft_null_variables()
{
	g_figure_heigth = 0;
	g_figure_width = 0;
	g_min_x = 0;
	g_min_y = 0;
	g_inner_width = 0;
	g_inner_heigth = 0;
	g_stars = 0;
	g_x = 0;
	g_y = 0;
}
void ft_solver(int ***field_arr, char ***figure_arr)
{
	ft_fill_field(field_arr);
	ft_prepare_figure(figure_arr);
	ft_figure_measure_heigth(*figure_arr);
	ft_figure_measure_width(*figure_arr);
	ft_put_figure(*field_arr, *figure_arr);
	//dprintf(fd, "===== RES ===== %d %d\n", g_x, g_y);
	ft_putstr(ft_itoa(g_x));
	write(1, " ", 1);
	ft_putstr(ft_itoa(g_y));
	write(1, "\n", 1);
	ft_null_variables();
	ft_free_arr((void **)*field_arr);
	ft_free_arr((void **)*figure_arr);
}

void ft_get_size_player(char *str, int ***field_arr, int *flag)
{
	int arr_iter = 0;

	ft_get_field_size(str);
	*field_arr = (int**)malloc(sizeof(int*) * (g_field_heigth + 1));
	while(arr_iter < g_field_heigth)
	{
		(*field_arr)[arr_iter] = (int*)malloc(sizeof(int) * g_field_width);
		arr_iter++;
	}
	(*field_arr)[arr_iter] = NULL;
	*flag = 1;
	g_enemy_figure = g_player_number == 1 ? 'X' : 'O';
	g_my_figure = g_player_number == 1 ? 'O' : 'X';
}

void ft_get_field(char *str, int ***field_arr, int *i)
{
	int j;

	j = 0;
	while(str[j])
	{
		if (str[j] == g_enemy_figure)
			(*field_arr)[*i][j - 4] = -1;
		if (str[j] == g_my_figure)
			(*field_arr)[*i][j - 4] = -2;
		if (str[j] == '.')
			(*field_arr)[*i][j - 4] = -3;
		j++;
	}
	(*i)++;
}

void ft_parser_filler(int fd)
{
	int **field_arr = NULL;
	char **figure_arr = NULL;
	char *str;
	int i;
	//int j = 0;
	int stop = 0;
	int k = 0;
	int flag = 0;

	i = 0;
	ft_null_variables();
	while (get_next_line(0, &str))
	{
		flag = 0;
		if (*str == '$')
			g_player_number = str[10] - '0';
		else if ((*(str + 1) == 'l') && (!flag))
			ft_get_size_player(str, &field_arr, &flag);
		else if (*str >= '0' && *str <= '9')
			ft_get_field(str, &field_arr, &i);
		else if (*(str + 1) == 'i')
		{
			ft_get_figure_size(str);
			figure_arr = (char**)malloc(sizeof(char*) * (g_figure_heigth + 1));
		}
		else if ((*str == '.') || (*str == '*'))
		{
			figure_arr[k] = ft_strdup(str);
			k++;
			if (k == g_figure_heigth)
				figure_arr[k] = NULL;
			stop++;
		}
		if (stop >= g_figure_heigth && (g_figure_heigth))
		{
			ft_solver(&field_arr, &figure_arr);
			stop = 0;
			i = 0;
			k = 0;
		}
		ft_strdel(&str);
	}


	dprintf(fd, "oK5 =====================\n");
}

int main(void)
{
	int fd = open("myres", O_WRONLY | O_TRUNC);

	ft_parser_filler(fd);

	// dprintf(fd, "%s\n", system ("leaks iyerin.filler") );
	return (0);
}


// gcc main.c libftprintf.a -o players/iyerin.filler && ./filler_vm -f maps/map00 -p1 players/abanlin.filler -p2 players/iyerin.filler