/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strequal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:15:10 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 17:48:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libtest.h"
#include <stdbool.h>

/*
 * @brief Generates a message sumarising the result of an equality test between
 * 	2 strings.
 *
 * @param var (t_str): string variable to test.
 * @param val (t_str): the value [var] should be equal to.
 * @param success (bool): whether [var] = [val].
 *
 * @return (char *): string summarising string equality test.
 */
static char	*ft_test_message(t_str var, t_str val, bool success)
{
	t_str	str_passed;

	if (success)
	{
		str_passed = SUCCEESS;
	}
	else
	{
		str_passed = FAILURE;
	}
	return (ft_strnjoin(15,
			LPURPLE, " ", WHITE, "\"", var, "\"", LGRAY, " should equal ",
			WHITE, "\"", val, "\"", LGRAY, " - ", str_passed));
}

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
	bool	success;

	if (ft_strcmp(var, val) == 0)
	{
		(unit -> passed)++;
		success = true;
	}
	else
	{
		(unit -> failed)++;
		success = false;
	}
	ft_putendl_fd(ft_test_message(var, val, success), 1);
	return (success);
}
