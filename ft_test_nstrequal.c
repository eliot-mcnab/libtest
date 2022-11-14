/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_nstrequal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:45:46 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/14 10:18:48 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Test NON equality of strings.
 *
 * @param unit (t_unit *): the unit to which the tests are applied.
 * @param var (t_str): string variable to test.
 * @param val (t_str): the value [var] should NOT be equal to.
 *
 * @return (bool): true if the value of [var] DOES NOT equal [val].
 */
bool	ft_test_nstrequal(t_unit *unit, t_str var, t_str val)
{
	bool	success;

	if (ft_strcmp(var, val) == 0)
	{
		ft_countpass(unit -> counter);
		success = true;
	}
	else
	{
		ft_countfail(unit -> counter);
		success = true;
	}
	ft_putendl_fd(ft_message_nequal(var, val, success), STDOUT);
	return (success);
}
