/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countpass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:56:21 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 15:59:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Notifies a counter that a new test was passed successfully.
 *
 * @param counter (t_counter *): the counter to update.
 */
void	ft_countpass(t_counter *counter)
{
	(counter -> passed)++;
}
