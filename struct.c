/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:18:57 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 18:04:09 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_stock		*ft_stk_init(int size_max)
{
	t_stock	*stk;

	if (!(stk = (t_stock *)malloc(sizeof(t_stock))))
		return (NULL);
	if (!(stk->array = (t_piece *)malloc(sizeof(t_piece) * size_max)))
	{
		free(stk);
		stk = NULL;
		return (NULL);
	}
	stk->number = 0;
	stk->size_max = size_max;
	return (stk);
}

void		ft_stk_free(t_stock *stk)
{
	free(stk->array);
	stk->array = NULL;
	free(stk);
	stk = NULL;
}

int			ft_stk_push_back(t_stock *stk, t_piece p)
{
	if (stk->number >= stk->size_max)
		return (0);
	stk->array[stk->number] = p;
	stk->number++;
	return (1);
}

t_solution	*ft_sol_init(int len)
{
	t_solution	*sol;
	int			i;

	if (!(sol = malloc(sizeof(*sol))))
		return (NULL);
	sol->len = len;
	if (!(sol->matrix = malloc(sizeof(char *) * len)))
	{
		free(sol);
		sol = NULL;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		if (!(sol->matrix[i] = malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_memset(sol->matrix[i], '.', len);
		sol->matrix[i][len] = '\0';
		i++;
	}
	return (sol);
}

void		ft_sol_free(t_solution *sol)
{
	int	i;

	i = 0;
	while (i < sol->len)
	{
		free(sol->matrix[i]);
		sol->matrix[i] = NULL;
		i++;
	}
	free(sol->matrix);
	sol->matrix = NULL;
	free(sol);
	sol = NULL;
}
