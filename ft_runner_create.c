/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runner_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:15:10 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/10 18:25:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Creates a unit test runner. 
 */
t_runner	*ft_runner_create(void)
{
	t_runner	*runner;

	runner = malloc(sizeof(*runner));
	if (!runner)
	{
		return (NULL);
	}
	return (runner);
}
