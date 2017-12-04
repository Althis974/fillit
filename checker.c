/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:59:00 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 19:03:55 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Returns the number of points of contact between each '#'
*/

static int	ft_check_contact(char tab[5][5], int i, int j)
{
	int result;

	result = 0;
	if (j > 0 && tab[i][j - 1] == '#')
		result++;
	if (j < 3 && tab[i][j + 1] == '#')
		result++;
	if (i > 0 && tab[i - 1][j] == '#')
		result++;
	if (i < 3 && tab[i + 1][j] == '#')
		result++;
	if (1 <= result && result <= 3)
		return (result);
	return (0);
}

/*
** Checks that the input is valid :
** - each fifth caracter on a line is '\n'
** - it only contains '#' or '.'
** - it only contains 4 '#' and either 6 or 8 points of contact
*/

int			ft_check_piece(t_piece p)
{
	int i;
	int	j;
	int	nb;
	int	contact;

	nb = 0;
	contact = 0;
	i = -1;
	while (++i < 4)
	{
		if (p.tab[i][4] != '\n')
			return (0);
		j = -1;
		while (++j < 4)
		{
			if (!(p.tab[i][j] == '#' || p.tab[i][j] == '.'))
				return (0);
			if (p.tab[i][j] == '#' && ft_check_contact(p.tab, i, j) != 0)
			{
				nb++;
				contact += ft_check_contact(p.tab, i, j);
			}
		}
	}
	return (nb == 4 && (contact == 6 || contact == 8));
}
