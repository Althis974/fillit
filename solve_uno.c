/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_uno.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 14:48:32 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 11:49:41 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Tries (through bruteforce) to a find a possible solution
*/

static int	ft_solver_help(t_solution *sol, t_piece *p)
{
	int	x;
	int y;
	int	height;
	int	width;

	if (p[0].letter == '\0')
		return (1);
	height = ft_solver_height(p[0]);
	width = ft_solver_width(p[0]);
	x = -1;
	while (++x < sol->len - height + 1)
	{
		y = -1;
		while (++y < sol->len - width + 1)
		{
			if (!(ft_check_conflict(sol, p[0], x, y)))
			{
				ft_add_piece(sol, p[0], x, y);
				if (ft_solver_help(sol, &p[1]) == 1)
					return (1);
				ft_del_piece(sol, p[0], x, y);
			}
		}
	}
	return (0);
}

/*
** Computes the size of the smallest possible square for the solution
*/

static int	ft_solver_size(int nb)
{
	int size;
	int left;
	int mid;
	int	right;

	if (nb == 0 || nb == 1)
		return (nb);
	left = 1;
	right = nb;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid * mid < nb)
		{
			left = mid + 1;
			size = mid;
		}
		else
			right = mid - 1;
	}
	return (size);
}

/*
** Infinite loop that is only broken if a solution is found
** or if sol can't be properly initialised.
** If a solution can't be found for a given size, size++
*/

t_solution	*ft_solver_main(t_stock *stk)
{
	t_solution	*sol;
	int			size;

	sol = NULL;
	size = ft_solver_size(stk->number);
	while (1)
	{
		sol = ft_sol_init(size);
		if (sol == NULL || ft_solver_help(sol, stk->array) == 1)
			break ;
		ft_sol_free(sol);
		size++;
	}
	return (sol);
}
