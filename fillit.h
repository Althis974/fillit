/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:19:26 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 11:36:03 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "lib/libft/libft.h"

/*
** Stores each piece and its associated letter
*/

typedef struct	s_piece
{
	char		letter;
	char		tab[5][5];
}				t_piece;

/*
** Stores all the pieces, their number and the max size
*/

typedef struct	s_stock
{
	t_piece		*array;
	int			number;
	int			size_max;
}				t_stock;

/*
** Stores the solution, each line being len char long
*/

typedef struct	s_solution
{
	char		**matrix;
	int			len;
}				t_solution;

void			ft_reader(int fd, t_stock *stk);

int				ft_check_piece(t_piece p);

void			ft_add_piece(t_solution *sol, t_piece p, int x, int y);
void			ft_del_piece(t_solution *sol, t_piece p, int x, int y);
int				ft_check_conflict(t_solution *sol, t_piece p, int x, int y);

t_stock			*ft_stk_init(int size_max);
void			ft_stk_free(t_stock *stk);
int				ft_stk_push_back(t_stock *stk, t_piece p);
t_solution		*ft_sol_init(int len);
void			ft_sol_free(t_solution *sol);

t_solution		*ft_solver_main(t_stock *stk);
int				ft_solver_height(t_piece p);
int				ft_solver_width(t_piece p);

#endif
