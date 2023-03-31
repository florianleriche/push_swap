/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvts_pr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:27:08 by fleriche          #+#    #+#             */
/*   Updated: 2023/03/30 13:30:03 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_mvts_pa(int *col_a, int *col_b, int *ia, int *ib)
{
	*ia = *ia + 1;
	col_a[*ia] = col_b[*ib];
	*ib = *ib - 1;
	ft_printf("pa\n");
}

void	ps_mvts_pb(int *col_a, int *col_b, int *ia, int *ib)
{
	*ib = *ib + 1;
	col_b[*ib] = col_a[*ia];
	*ia = *ia - 1;
	ft_printf("pb\n");
}

void	ps_mvts_ra(int *col_a, int *ia)
{
	int	buf;
	int	i_buf;

	i_buf = *ia + 1;
	buf = col_a[*ia];
	while (--i_buf > 0)
		col_a[i_buf] = col_a[i_buf - 1];
	col_a[i_buf] = buf;
	ft_printf("ra\n");
}

void	ps_mvts_rra(int *col_a, int *ia)
{
	int	buf;
	int	i_buf;

	i_buf = -1;
	buf = col_a[i_buf + 1];
	while (++i_buf < *ia)
		col_a[i_buf] = col_a[i_buf + 1];
	col_a[i_buf] = buf;
	ft_printf("rra\n");
}