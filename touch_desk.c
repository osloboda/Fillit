/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_desk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:04:32 by osloboda          #+#    #+#             */
/*   Updated: 2018/12/13 15:07:05 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure		*create_node(char *str, char a, int i, int j)
{
	t_figure	*new_node;
	int			*coord;
	int			max;

	if (!(new_node = (t_figure *)malloc(sizeof(t_figure))))
		return (NULL);
	coord = (int*)malloc(sizeof(int) * 4);
	max = 0;
	while (++i < 16)
	{
		if (str[i] == '#')
		{
			coord[j++] = i;
			if (coord[j - 1] % 4 + 1 > max)
				max = coord[j - 1] % 4 + 1;
		}
	}
	new_node->coord = coord;
	new_node->next = NULL;
	new_node->tetram = str;
	new_node->hight = coord[3] / 4 + 1;
	new_node->whith = max;
	new_node->sym = a;
	return (new_node);
}

void			print_map(t_map *map)
{
	int			j;
	int			i;

	i = 0;
	j = 0;
	while (j < map->size && i != map->size * map->size)
	{
		write(1, &(map->map[i]), 1);
		if (++j == map->size)
		{
			write(1, "\n", 1);
			j = 0;
		}
		i++;
	}
	free(map->map);
	free(map);
}

void			testr(char *str, char a, t_figure *fig, t_figure *tmp)
{
	int			**matrix;

	while (*str)
	{
		matrix = set_matrix(str);
		if (a == 'A')
		{
			fig = create_node(top_up_figure(matrix, -1, -1, -1), a, -1, 0);
			tmp = fig;
		}
		else
		{
			fig->next = create_node(top_up_figure(matrix, -1, -1, -1)
					, a, -1, 0);
			fig = fig->next;
		}
		free(matrix[0]);
		free(matrix[1]);
		free(matrix[2]);
		free(matrix[3]);
		free(matrix);
		str += 21;
		a++;
	}
	print_map(fillit(a - 'A', tmp));
}

char			*top_up_figure(int **str, int x, int y, int i)
{
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (str[y][x] == '#')
				break ;
		if (str[y][x] == '#')
			break ;
	}
	while (++i < 4 && y > 0)
	{
		x = -1;
		while (++x < 4)
			if (str[i][x] == '#')
			{
				str[i - y][x] = '#';
				str[i][x] = '.';
			}
	}
	return (top_left_figure(str, 0, -1, -1));
}

char			*top_left_figure(int **str, int x, int y, int j)
{
	char		*figure;
	int			i;

	i = -1;
	figure = (char*)malloc(17 * sizeof(char));
	while (++i < 16)
		figure[i] = '.';
	figure[16] = '\0';
	while (++y < 4)
	{
		x = -1;
		while (++x < 3)
			if (str[x][y] == '#')
				break ;
		if (str[x][y] == '#' && (x = -1))
			break ;
	}
	while (++x < 4 && (j = -1))
		while (++j < 4)
			if (str[j][x] == '#')
				figure[(x - y) + j * 4] = '#';
	return (figure);
}
