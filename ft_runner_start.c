/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runner_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:46:49 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 11:05:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libtest.h"
#include <stdbool.h>

/*
 * @brief Runs tests on a unit in a linked list.
 *
 * @param any (t_any): the unit in the linked list.
 */
static void	ft_runner_run_tests(t_any any)
{
	t_unit	*unit;

	unit = (t_unit *)any;
	if (unit -> f_tests(unit))
	{
		(unit -> runner -> passed)++;
	}
	else
	{
		(unit -> runner -> failed)++;
	}
}

/*
 * @brief Runs test on all units stored in a runner.
 *
 * @param  runner (t_runner*): the runner containing the units to test.
 */
void	ft_runner_start(t_runner *runner)
{
	ft_lstiter(runner -> units_head, &ft_runner_run_tests);
}
