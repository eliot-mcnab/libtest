/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:46:49 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 17:34:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libtest.h"

/*
 * @brief Generates header string for a unit annoucing its name.
 *
 * @param unit (t_unit *): the unit to generate the header for.
 */
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
 * @return (char *): message summarizing test in the given [unit].
 */
static char	*ft_unit_message(t_unit *unit)
{
	t_str	name;
	t_str	str_passed;
	t_str	str_total;
	t_str	str_coverage;
	t_str	str_success;

	name = unit -> name;
	str_passed = ft_itoa(unit -> counter -> passed);
	str_total = ft_itoa(ft_countotal(unit -> counter));
	str_coverage = ft_itoa((int)(unit -> counter -> threshold * 100));
	if (ft_coverage_reached(unit -> counter))
	{
		str_success = SUCCEESS;
	}
	else
	{
		str_success = FAILURE;
	}
	return (ft_strnjoin(14,
			LPURPLE, " ", WHITE, name, LGRAY, ": ", str_passed, "/",
			str_total, " tests passed  ", WHITE, str_coverage,
			"\% coverage needed  ", str_success));
}

/*
 * @brief Generates a string summarizing test results for a [runner].
 *
 * @param runner (t_runner *: the runner to generate the message for.
 *
 * @return (char *): message summarizing units tests in the [runner].
 */
static char	*ft_runner_message(t_runner *runner)
{
	t_str	str_passed;
	t_str	str_total;
	t_str	str_coverage;
	t_str	str_success;

	str_passed = ft_itoa(runner -> counter -> passed);
	str_total = ft_itoa(ft_countotal(runner -> counter));
	str_coverage = ft_itoa((int)(runner -> counter -> threshold * 100));
	if (ft_coverage_reached(runner -> counter))
	{
		str_success = SUCCEESS;
	}
	else
	{
		str_success = FAILURE;
	}
	return (ft_strnjoin(9, " ", str_passed, "/", str_total,
			" units passed  ", WHITE, str_coverage,
			"\% coverage needed  ", str_success));
}

/*
 * @brief Runs tests on a unit in a linked list and displays an output message.
 *
 * @param any (t_any): the unit in the linked list.
 */
static void	ft_runner_test_unit(t_any any)
{
	t_unit	*unit;

	unit = (t_unit *)any;
	ft_putendl_fd(ft_unit_header(unit), STDOUT);
	ft_putendl_fd(ft_strnjoin(3, LPURPLE, "|", LGRAY), STDOUT);
	unit -> f_tests(unit);
	if (ft_coverage_reached(unit -> counter))
	{
		ft_countpass(unit -> runner -> counter);
	}
	else
	{
		ft_countfail(unit -> runner -> counter);
	}
	ft_putendl_fd(ft_strnjoin(3, LPURPLE, "|", LGRAY), STDOUT);
	ft_putendl_fd(ft_unit_message(unit), STDOUT);
	ft_putendl_fd("", STDOUT);
}

/*
 * @brief Runs test on all units stored in a runner.
 *
 * @param  runner (t_runner*): the runner containing the units to test.
 */
void	ft_run_tests(t_runner *runner)
{
	ft_putendl_fd(
		ft_strnjoin(
			5, WHITE, "Running Tests", LCYAN, "    ", LGRAY),
		STDOUT);
	ft_putendl_fd("", STDOUT);
	ft_lstiter(runner -> units_head, &ft_runner_test_unit);
	ft_putendl_fd(ft_runner_message(runner), STDOUT);
	ft_free_all(runner);
}
