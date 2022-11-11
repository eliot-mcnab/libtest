/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:30:33 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 10:55:45 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Creates a new unit to test.
 *
 * @parm unit_name (t_str): the name of the unit.
 * @param f_unit_tests (t_tests): the tests to preform on the unit.
 * @param parent_runner (t_runner*): parent runner containing the unit.
 *
 * @return (t_unit *): new unit.
 */
static t_unit	*ft_create_unit(t_str unit_name, t_tests f_unit_tests,
		t_runner *parent_runner)
{
	t_unit	*unit;

	unit = malloc(sizeof(*unit));
	if (!unit)
	{
		return (NULL);
	}
	unit -> runner = parent_runner;
	unit -> name = unit_name;
	unit -> f_tests = f_unit_tests;
	unit -> passed = 0;
	unit -> failed = 0;
	return (unit);
}

/*
 * @brief Adds a new unit to test to a [runner].
 *
 * @param runner (* t_runner): the runner that will call the unit to run its
 * 	tests.
 * @param unit_name (t_str): the name of the unit to test.
 * @param f_unit_tests (bool(t_unit*)): the tests to run for the unit.
 */
void	ft_unit_add(t_runner *runner, t_str unit_name, t_tests f_unit_tests)
{
	t_unit	*unit;
	t_list	**node_current;

	unit = ft_create_unit(unit_name, f_unit_tests, runner);
	if (!unit)
	{
		return ;
	}
	node_current = &(runner -> units_last -> next);
	if (!(runner -> units_head))
	{
		node_current = &(runner -> units_head);
	}
	*node_current = ft_lstnew(unit);
	if (!(*node_current))
	{
		return ;
	}
	runner -> units_last = *node_current;
}
