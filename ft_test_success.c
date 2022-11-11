/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_success.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:16:43 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 10:23:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"
#include <stdbool.h>

/*
 * @brief Determines if a unit passed all its tests.
 *
 * @param unit (t_unit *): the unit to check.
 *
 * @return (bool): true if [unit] passed all its tests, false otherwise.
 */
bool	ft_test_success(t_unit *unit)
{
	if (unit -> failed == 0)
		return (true);
	else
		return (false);
}
