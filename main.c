#include "includes/ft_filler.h"

#define FIGURE(player_number) (player_number == 1) ? 'O' : 'X'



int	ft_put_number(unsigned char ***arr, int i, int j, char number, int fd)
{
	int changes = 0;

	//dprintf(fd, "i = %d\nj = %d\nnumber = %c\n", i, j, number);
	if ((j - 1 >= 0) && ((*arr)[i][j - 1] == '.'))
	{
		(*arr)[i][j - 1] = number;
		changes = 1;
	}
	if ((j + 1 < g_field_width) && ((*arr)[i][j + 1] == '.'))
	{
		(*arr)[i][j + 1] = number;
		changes = 1;
	}
	if ((i - 1 >= 0) && ((*arr)[i - 1][j] == '.'))
	{
		(*arr)[i - 1][j] = number;
		changes = 1;
	}
	if ((i + 1 < g_field_heigth) && ((*arr)[i + 1][j] == '.'))
	{
		(*arr)[i + 1][j] = number;
		changes = 1;
	}
	return (changes);
}

void ft_fill_field(unsigned char ***arr)
{
	int fd = open("myres2", O_WRONLY);

	char number = 1;
	char enemy_figure = 'O';
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
				if((*arr)[i][j] == 'X')
					(*arr)[i][j] = 122;
				//write(fd, "tyttyttyt3", 10);
				if((*arr)[i][j] == enemy_figure)
				{
					if (enemy_figure == 'O')
						(*arr)[i][j] = 121;
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

t_figure **ft_get_figure()
{
	char *str;
	t_figure **figure_cord;
	int i = 0;
	int x = 0;

	while(get_next_line(0, &str))
	{
		if(str[x] == '*')
		{
			figure_cord[i] = malloc(sizeof(t_figure));
			figure_cord[i]->x = x;
			figure_cord[i]->y = i;
		}
		i++;
		x = 0;
	}
	return(figure_cord);
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
	//free tmp_arr

}

int ft_parser_filler(char **return_str)
{
	int fd = open("myres", O_WRONLY);

	unsigned char **field_arr;
	char **figure_arr;
	char *str;
	int i = 0;
	int j = 0;
	int flag = 0;
	
	while(get_next_line(0, &str))
	{
		//dprintf(fd, "str = %s\n", str);

		if (*str == '$')
			g_player_number = str[10] - '0';
		else if ((*(str + 1) == 'l') && (!flag))
		{
			ft_get_field_size(str);
			field_arr = (unsigned char**)malloc(sizeof(char*) * g_field_heigth);
			flag = 1;
		}
		else if (*str >= '0' && *str <= '9')
		{
			field_arr[i] = (unsigned char*)ft_strsub(str, 4, g_field_width);
			dprintf(fd, "field = %s\n", field_arr[i]);
			i++;
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
			dprintf(fd, "fig = %s\n", figure_arr[j]);
			j++;
		}
		else if (*str == '=')
			return (0);
		ft_strdel(&str);		
	}

	ft_fill_field(&field_arr);
	// ft_put_figure(&field_arr);


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
		printf("%s\n", return_str);
	}
	return (0);
}


// gcc main.c libftprintf.a -o players/iyerin.filler && ./filler_vm -f maps/map00 -p1 players/abanlin.filler -p2 players/iyerin.filler