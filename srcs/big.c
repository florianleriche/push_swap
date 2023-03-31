/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:22:50 by fleriche          #+#    #+#             */
/*   Updated: 2023/03/31 11:22:58 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_radix(int *col_A, int *ia, int *ib, int size)
{
	int	nb;
	int	*col_b;
	int	j;

	col_b = (int *)malloc(sizeof(int) * size);
	if (!col_b)
		return ;
	nb = 1;
	j = 0;
	while (nb < size)
	{
		while (j < size)
		{
			if (!(col_A[*ia] & nb))
				ps_mvts_pb(col_A, col_b, ia, ib);
			else
				ps_mvts_ra(col_A, ia);
			j++;
		}
		while (*ia != size - 1)
			ps_mvts_pa(col_A, col_b, ia, ib);
		j = 0;
		nb = nb * 2;
	}
	free(col_b);
}

void	ps_nb_renamed(int *tab, int *tab_cpy, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] == tab_cpy[j])
			{
				tab[i] = j;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	ps_nb_ordered(int *tab, int size)
{
	int	i;
	int	j;
	int	buf;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				buf = tab[i];
				tab[i] = tab[j];
				tab[j] = buf;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
