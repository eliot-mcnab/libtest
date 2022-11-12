/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:55:36 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 17:16:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static double	ft_unit(t_unit *unit)
{
	t_str	test;

	test = ft_strdup("test");
	ft_test_strequal(unit, test, "test");
	ft_test_strequal(unit, test, "nope");
	return (ft_coverage(unit -> counter));
}

int	main(int argc, char *argv[])
{
	t_runner	*runner;

	(void) argc;
	(void) argv;
	runner = ft_runner_create(.5);
	ft_unit_add(runner, "test", &ft_unit, .6);
	ft_run_tests(runner);
	return (0);
}
