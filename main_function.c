/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:00:04 by osloboda          #+#    #+#             */
/*   Updated: 2018/12/13 16:00:00 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_validity(int **matrix, int r, int x, int y)
{
	int		res;

	res = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (matrix[y][x] != 10)
				res += matrix[y][x] - 1;
			x++;
		}
		free(matrix[y]);
		y++;
	}
	free(matrix);
	if ((res != 6 && res != 8) || r != 4)
		return (1);
	return (0);
}

int			**set_matrix(char *str)
{
	int		**matrix;
	int		i;
	int		j;

	i = 0;
	matrix = (int**)malloc(4 * sizeof(int*));
	while (i < 4 && *str)
	{
		j = 0;
		matrix[i] = (int*)malloc(5 * sizeof(int));
		while (j < 4)
		{
			matrix[i][j] = (int)str[j];
			j++;
		}
		i++;
		str += 5;
	}
	return (matrix);
}

int			check_figure(char *str, int y, int x, int r)
{
	int		**matrix;

	while ((*str == '.' || *str == '#' || *str == '\n') &&
			(matrix = set_matrix(str)) && ((y + 1) % 4 != 0))
	{
		str += 21;
		y = 0;
		r = 0;
		y = -1;
		while (++y < 4 && (x = -1))
			while (++x < 4)
				matrix = check_dop(matrix, x, y, &r);
		if (check_validity(matrix, r, 0, 0))
			return (0);
	}
	return (1);
}

void		validation_read(const int fd, int h, int j, int i)
{
	char	buff[546];
	int		ret;

	if ((ret = (int)read(fd, buff, 546)) && ret >= 19 && ret < 546 &&
			!(buff[ret] = '\0'))
		while (i <= ret && (buff[i] == '#' || buff[i] == '.'
					|| buff[i] == '\n' || buff[i] == '\0'))
		{
			if ((j != 5 && j != 4 && buff[i] == '\n') || (h == 4 && buff[i - 1]
						!= '\n' && buff[i - 1] != '\0') || ((h == 3 && j == 5
							&& buff[i] == '\n' && buff[i + 1] != '#' &&
							buff[i + 1] != '.') || (buff[i] == '\0' && h == 3
								&& j == 5)))
				break ;
			if (h == 4 && i++)
				h = 0;
			if (i++ && j == 5 && !(j = 0))
				h++;
			j++;
		}
	if (i == ret && ret >= 19 && ret < 546 && check_figure(buff, 0, 0, 0))
		testr(buff, 'A', NULL, NULL);
	else
		ft_putstr("error\n");
}

int			main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		argv++;
		if ((fd = open(*argv, O_RDONLY)))
		{
			validation_read(fd, 0, 0, 0);
			close(fd);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
