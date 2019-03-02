/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:03:04 by osloboda          #+#    #+#             */
/*   Updated: 2018/12/13 15:47:54 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*make_map(int map_size)
{
	t_map	*map;
	int		map_ip;

	map = (t_map *)malloc(sizeof(t_map));
	map->size = map_size;
	map_ip = map_size * map_size;
	if (!(map->map = (char *)malloc(map_ip + 1)))
		return (NULL);
	map->map[map_ip--] = '\0';
	while (map_ip >= 0)
		map->map[map_ip--] = '.';
	return (map);
}

void		del_elem(t_map *map, t_figure *figur)
{
	int		i;

	i = 0;
	while (map->map[i])
	{
		if (figur->sym == map->map[i])
			map->map[i] = '.';
		i++;
	}
}

int			try_elem(t_map *map, int i, int j, t_figure *figur)
{
	int		h;

	h = i;
	while (++j < 4)
	{
		if ((j == 0) || (figur->coord[j] / 4) == (figur->coord[j - 1] / 4))
		{
			if (j == 0)
				i += figur->coord[j];
			else
				i += figur->coord[j] - figur->coord[j - 1];
		}
		else
			i += (figur->coord[j] - figur->coord[j - 1]) + map->size - 4;
		if (map->map[i] == '.')
			map->map[i] = figur->sym;
		else
		{
			del_elem(map, figur);
			i = h;
			return (0);
		}
	}
	i = h;
	return (1);
}

int			put_elem(t_map *map, t_figure *figur)
{
	int		i;

	i = 0;
	while (map->map[i])
	{
		if (((i / map->size) <= (map->size - figur->hight)) && ((i % map->size)
					<= (map->size - figur->whith)) &&
				try_elem(map, i, -1, figur))
		{
			if (!figur->next || put_elem(map, figur->next))
				return (1);
			else
				del_elem(map, figur);
		}
		i++;
	}
	return (0);
}

t_map		*fillit(int count, t_figure *figur)
{
	t_map	*map;
	int		size;

	size = 0;
	map = make_map(ft_sqrt(count * 4));
	while (!put_elem(map, figur))
	{
		size = map->size + 1;
		free(map);
		map = make_map(size);
	}
	free_list(figur);
	return (map);
}
