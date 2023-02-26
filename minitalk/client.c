/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:07:29 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/08 12:20:05 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char_binary(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << (i)))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

int	main(int ac, char **argv)
{
	int				pid;
	int				i;
	unsigned char	*message;

	message = (unsigned char *)argv[2];
	if (ac != 3)
	{
		write(2, "ERROR\n", 7);
		exit(1);
	}
	i = 0;
	if (ac == 3)
	{		
		pid = ft_atoi(argv[1]);
		check_pid(argv, pid);
		while (message[i] != '\0')
		{
			send_char_binary(pid, message[i]);
			i++;
		}
	}
}
