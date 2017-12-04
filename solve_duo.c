/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_duo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 18:14:23 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 19:49:55 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Computes the height of the tetrimino
*/

int		ft_solver_height(t_piece p)
{
	int	i;
	int	j;
	int	height;

	height = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (p.tab[i][j] == '#')
			{
				height = i + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (height);
}

/*
** Computes the width of the tetrimino
*/

int		ft_solver_width(t_piece p)
{
	int	i;
	int	j;
	int	width;

	width = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (p.tab[i][j] == '#')
			{
				width = j + 1;
				break ;
			}
			i++;
		}
		j++;
	}
	return (width);
}

/*
** Adds a given piece to the sol->matrix
*/

void	ft_add_piece(t_solution *sol, t_piece p, int x, int y)
{
	int	i;
	int	j;
	int height;
	int width;

	height = ft_solver_height(p);
	width = ft_solver_width(p);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (p.tab[i][j] == '#')
				sol->matrix[x + i][y + j] = p.letter;
			j++;
		}
		i++;
	}
}

/*
** Deletes a given piece from the sol->matrix
*/

void	ft_del_piece(t_solution *sol, t_piece p, int x, int y)
{
	int i;
	int	j;
	int	height;
	int	width;

	height = ft_solver_height(p);
	width = ft_solver_width(p);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (p.tab[i][j] == '#')
				sol->matrix[x + i][y + j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_check_conflict(t_solution *sol, t_piece p, int x, int y)
{
	int i;
	int	j;
	int	height;
	int	width;

	height = ft_solver_height(p);
	width = ft_solver_width(p);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (p.tab[i][j] == '#' && sol->matrix[x + i][y + j] != '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
