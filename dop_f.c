/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:03 by osloboda          #+#    #+#             */
/*   Updated: 2018/12/13 15:45:10 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				**check_dop(int **matrix, int x, int y, int *r)
{
	if (matrix[y][x] == '#' && (matrix[y][x] = 1))
	{
		if ((*r)++ && x > 0 && matrix[y][x - 1] < 4 && matrix[y][x - 1]++)
			matrix[y][x]++;
		if (x < 3 && matrix[y][x + 1] < 4 && matrix[y][x + 1]++)
			matrix[y][x]++;
		if (y > 0 && matrix[y - 1][x] < 4 && matrix[y - 1][x]++)
			matrix[y][x]++;
		if (y < 3 && matrix[y + 1][x] < 4 && matrix[y + 1][x]++)
			matrix[y][x]++;
	}
	else
		matrix[y][x] = 10;
	return (matrix);
}

void			free_list(t_figure *stack)
{
	t_figure	*figure;
	t_figure	*tmp;

	figure = stack;
	while (figure)
	{
		tmp = figure;
		figure = figure->next;
		tmp->coord ? free(tmp->coord) : tmp->coord;
		tmp->tetram ? free(tmp->tetram) : tmp->tetram;
		tmp ? free(tmp) : tmp;
	}
}

int				ft_sqrt(unsigned int num)
{
	float		result;
	float		div;

	div = num;
	result = num;
	if (num <= 0)
		return (0);
	while (1)
	{
		div = (num / div + div) / 2;
		if (result > div)
			result = div;
		else
			return (result - (int)result != 0 ? (int)result + 1 : (int)result);
	}
	return (0);
}
