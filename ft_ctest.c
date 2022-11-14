/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:04:25 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/14 09:27:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

// TODO: replace the itoa here by an ltoa
static char	*ft_ctest_message(t_any var, t_any val, bool success)
{
	t_str	str_var;
	t_str	str_val;
	t_str	str_success;

	str_var = ft_itoa((size_t) var);
	str_val = ft_itoa((size_t) val);
	if (success)
	{
		str_success = SUCCEESS;
	}
	else
	{
		str_success = FAILURE;
	}
	return (ft_strnjoin(9,
			LPURPLE, " ", WHITE, "&", str_var, " tested against &", str_val,
			"-", str_success));
}

/*
 * @brief Runs a custom test on a unit.
 *
 * @param unit (t_unit *): the unit to run the test on.
 * @param var (t_any): variable to test.
 * @param val (t_any): target value.
 * @param f_test (t_test): test function.
 *
 * @return (bool): whether the test passed.
 */
bool	ft_ctest(t_unit *unit, t_any var, t_any val, t_test f_test)
{
	bool	success;

	if (f_test(var, val))
	{
		ft_countpass(unit -> counter);
		success = true;
	}
	else
	{
		ft_countfail(unit -> counter);
		success = false;
	}
	ft_putendl_fd(ft_ctest_message(var, val, success), STDOUT);
	return (success);
}
