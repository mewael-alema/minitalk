/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malema <malema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:55:16 by malema            #+#    #+#             */
/*   Updated: 2023/03/24 13:28:26 by malema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <unistd.h>

void	ft_signal_receiver(int signal)
{
	int i = 0;
	
	while (i < 8)
	{
		if (signal == SIGUSR2)
			printf("SIGUSR2 - %d", 1);
		else
			printf("SIGUSR1 - %d", 2);
		i++;
	}
}

int	main(void)
{
	int	pid;
	int	i;

	pid = (int)(getpid());
	printf("this is the %d \n", pid);
	signal(SIGUSR1, ft_signal_receiver);
	signal(SIGUSR2, ft_signal_receiver);
	while (1)
		usleep(WAIT_TIME);
}
