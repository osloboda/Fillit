/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:37:02 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/02 16:43:52 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "fcntl.h"
# include "Libft/libft.h"

typedef struct		s_figure
{
	char			sym;
	char			*tetram;
	int				*coord;
	int				hight;
	int				whith;
	struct s_figure	*next;
}					t_figure;

typedef struct		s_map
{
	int				size;
	char			*map;
}					t_map;

int					**check_dop(int **matrix, int x, int y, int *r);
void				free_list(t_figure *stack);
int					ft_sqrt(unsigned int num);
int					**set_matrix(char *str);
void				testr(char *str, char a, t_figure *fig, t_figure *tmp);
t_map				*fillit(int count, t_figure *figur);
char				*top_up_figure(int **str, int x, int y, int i);
char				*top_left_figure(int **str, int x, int y, int j);

#endif
