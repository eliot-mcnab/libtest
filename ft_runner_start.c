/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runner_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:46:49 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 16:18:23 by emcnab           ###   ########.fr       */
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
	tests_passed = ft_itoa(unit -> counter -> passed);
	tests_total = ft_itoa(ft_countotal(unit -> counter));
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

	units_total = ft_itoa(ft_countotal(runner -> counter));
	units_passed = ft_itoa(runner -> counter -> passed);
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
	ft_putendl_fd(ft_unit_header(unit), STDOUT);
	ft_putendl_fd(ft_strnjoin(3, LPURPLE, "|", LGRAY), STDOUT);
	if (unit -> f_tests(unit))
	{
		ft_countpass(unit -> runner -> counter);
	}
	else
	{
		ft_countfail(unit -> runner -> counter);
	}
	ft_putendl_fd(ft_strnjoin(3, LPURPLE, "|", LGRAY), STDOUT);
	ft_putendl_fd(ft_unit_recap(unit), STDOUT);
	ft_putendl_fd("", STDOUT);
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
			5, WHITE, "Running Tests", LCYAN, "    ", LGRAY),
		STDOUT);
	ft_putendl_fd("", STDOUT);
	ft_lstiter(runner -> units_head, &ft_runner_run_tests);
	ft_putendl_fd(ft_runner_message(runner), STDOUT);
}
