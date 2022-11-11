/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runner_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:46:49 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 17:52:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static char	*ft_unit_header(t_unit *unit)
{
	t_str	name;

	name = unit -> name;
	return (ft_strnjoin(5,
			LPURPLE, " Testing ", WHITE, name, LGRAY));
}

/*
 * @brief Generates a message summarizing the result of tests in a unit.
 *
 * @param unit (t_unit *): the unit for which to generate the message.
 *
 * @return ()
 */
static char	*ft_unit_recap(t_unit *unit)
{
	double	success_rate;
	t_str	name;
	t_str	tests_passed;
	t_str	tests_total;
	t_str	str_passed;

	name = unit -> name;
	tests_passed = ft_itoa(unit -> passed);
	tests_total = ft_itoa(unit -> passed + unit -> failed);
	success_rate = ft_tests_success(unit);
	if (success_rate > .5)
	{
		str_passed = SUCCEESS;
	}
	else
	{
		str_passed = FAILURE;
	}
	return (ft_strnjoin(11,
			LPURPLE, " ", WHITE, name, LGRAY, ": ", tests_passed, "/",
			tests_total, " tests passed - ", str_passed));
}

static char	*ft_runner_message(t_runner *runner)
{
	double	success_rate;
	t_str	units_total;
	t_str	units_passed;
	t_str	str_passed;

	units_total = ft_itoa(runner -> passed + runner -> failed);
	units_passed = ft_itoa(runner -> passed);
	success_rate = ft_runner_success(runner);
	if (success_rate > .5)
	{
		str_passed = SUCCEESS;
	}
	else
	{
		str_passed = FAILURE;
	}
	return (ft_strnjoin(6, " ", units_passed, "/", units_total,
			" units passed - ", str_passed));
}

/*
 * @brief Runs tests on a unit in a linked list and displays an output message.
 *
 * @param any (t_any): the unit in the linked list.
 */
static void	ft_runner_run_tests(t_any any)
{
	t_unit	*unit;

	unit = (t_unit *)any;
	ft_putendl_fd(ft_unit_header(unit), 1);
	ft_putendl_fd(ft_strnjoin(3, LPURPLE, "|", LGRAY), 1);
	if (unit -> f_tests(unit))
	{
		(unit -> runner -> passed)++;
	}
	else
	{
		(unit -> runner -> failed)++;
	}
	ft_putendl_fd(ft_strnjoin(3, LPURPLE, "|", LGRAY), 1);
	ft_putendl_fd(ft_unit_recap(unit), 1);
	ft_putendl_fd("", 1);
}

/*
 * @brief Runs test on all units stored in a runner.
 *
 * @param  runner (t_runner*): the runner containing the units to test.
 */
void	ft_runner_start(t_runner *runner)
{
	ft_putendl_fd(
		ft_strnjoin(
			5, WHITE, "Running Tests", CYAN, "    ", LGRAY),
		1);
	ft_putendl_fd("", 1);
	ft_lstiter(runner -> units_head, &ft_runner_run_tests);
	ft_putendl_fd(ft_runner_message(runner), 1);
}
