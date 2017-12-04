/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 18:15:18 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 19:09:53 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_move_left(char tab[5][5])
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		tab[i][0] = tab[i][1];
		tab[i][1] = tab[i][2];
		tab[i][2] = tab[i][3];
		tab[i][3] = '.';
	}
}

static void	ft_move_up(char tab[5][5])
{
	int	j;

	j = -1;
	while (++j < 4)
	{
		tab[0][j] = tab[1][j];
		tab[1][j] = tab[2][j];
		tab[2][j] = tab[3][j];
		tab[3][j] = '.';
	}
}

/*
** Modifies each piece struture's tab to move the '#'
** as much as possible to the up and left
*/

static void	ft_fill_piece(t_piece *p)
{
	if (ft_strchr((const char *)p->tab, '#') != 0)
	{
		while (p->tab[0][0] == '.' && p->tab[1][0] == '.'
				&& p->tab[2][0] == '.' && p->tab[3][0] == '.')
			ft_move_left(p->tab);
		while (p->tab[0][0] == '.' && p->tab[0][1] == '.'
				&& p->tab[0][2] == '.' && p->tab[0][3] == '.')
			ft_move_up(p->tab);
	}
}

static void	ft_exit(t_stock *stk)
{
	ft_stk_free(stk);
	ft_putstr_fd("error\n", 1);
	exit(1);
}

/*
** Reads the file given as input, and puts the data into a t_stock struct
*/

void		ft_reader(int fd, t_stock *stk)
{
	t_piece	p;
	char	letter;
	int		size_read;
	int		last;

	letter = 'A';
	while ((size_read = read(fd, p.tab, 21)) >= 20)
	{
		last = size_read;
		p.tab[4][1] = '\0';
		ft_fill_piece(&p);
		if (ft_check_piece(p) == 0)
			ft_exit(stk);
		p.letter = letter++;
		ft_stk_push_back(stk, p);
	}
	if (size_read != 0 || last == 21 || letter == 'A' || letter > 'Z' + 1)
		ft_exit(stk);
	p.letter = '\0';
	ft_stk_push_back(stk, p);
}
