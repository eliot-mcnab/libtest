/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:51:40 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 17:00:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Frees up all memory used by a counter.
 *
 * @param counter (t_counter *): the counter to free.
 */
static void	ft_free_counter(t_counter *counter)
{
	counter -> passed = 0;
	counter -> failed = 0;
	counter -> threshold = 0;
	free(counter);
}

/*
 * @brief Frees up all memory used by a unit.
 *
 * @param any (t_any *): unit in the linked list to free.
 */
static void	ft_free_unit(t_any any)
{
	t_unit	*unit;

	unit = (t_unit *)any;
	unit -> runner = NULL;
	unit -> name = NULL;
	unit -> f_tests = NULL;
	ft_free_counter(unit -> counter);
	unit -> counter = NULL;
	free(unit);
}

/*
 * @brief Frees up all memory used by the tester.
 *
 * @param runner (t_runner *): the runner which ran the tests.
 */
void	ft_free_all(t_runner *runner)
{
	ft_lstclear(&(runner -> units_head), &ft_free_unit);
	runner -> units_last = NULL;
	ft_free_counter(runner -> counter);
	free(runner);
}
