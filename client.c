/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malema <malema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:41:21 by malema            #+#    #+#             */
/*   Updated: 2023/03/18 21:08:00 by malema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	send_chars(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(WAIT_TIME);
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		i;
	int		pid;

	if (argc != 3)
		return (1);
	pid = atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	message = argv[2];
	i = 0;
	while (message[i++])
		send_chars(message[i], pid);
	//send_chars(message[i], pid);
}
