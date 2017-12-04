/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:18:36 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 18:04:47 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_printer(t_solution *sol)
{
	int i;

	i = 0;
	while (i < sol->len)
	{
		ft_putstr_fd(sol->matrix[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

int			main(int ac, char **av)
{
	t_stock		*stk;
	t_solution	*sol;
	int			fd;

	if (ac != 2)
	{
		ft_putstr_fd("usage: ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd(" input_file\n", 2);
		exit(1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("error\n", 1);
		exit(1);
	}
	stk = ft_stk_init(27);
	ft_reader(fd, stk);
	close(fd);
	sol = ft_solver_main(stk);
	ft_printer(sol);
	ft_stk_free(stk);
	ft_sol_free(sol);
	return (0);
}
