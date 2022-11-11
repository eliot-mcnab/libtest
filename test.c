/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:55:36 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 16:55:38 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libtest.h"
#include <stdio.h>

static double	ft_unit(t_unit *unit)
{
	t_str	test;

	test = ft_strdup("test");
	ft_test_strequal(unit, test, "test");
	return (ft_tests_success(unit));
}

int	main(int argc, char *argv[])
{
	t_runner	*runner;

	(void) argc;
	(void) argv;
	runner = ft_runner_create();
	ft_unit_add(runner, "test", &ft_unit);
	ft_unit_add(runner, "test", &ft_unit);
	ft_unit_add(runner, "test", &ft_unit);
	ft_unit_add(runner, "test", &ft_unit);
	ft_runner_start(runner);
	return (ft_runner_success(runner));
}
