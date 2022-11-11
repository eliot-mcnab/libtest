/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strequal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:15:10 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 10:00:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Test equality of strings.
 *
 * @param unit (t_unit *): the unit to which the tests are applied.
 * @param var (t_str): string variable to test.
 * @param val (t_str): the value [var] should be equal to.
 *
 * @return (bool): true if the value of [var] equals [val].
 */
bool	ft_test_strequal(t_unit *unit, t_str var, t_str val)
{
	if (ft_strcmp(var, val) == 0)
	{
		(unit -> passed)++;
		return (true);
	}
	else
	{
		(unit -> failed)++;
		return (false);
	}
}
