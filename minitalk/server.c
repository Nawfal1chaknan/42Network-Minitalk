/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:02:39 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/07 15:13:15 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	binary_to_ascii(char *bin)
{
	int	decimal;
	int	len;
	int	i;

	decimal = 0;
	len = ft_strlen(bin);
	i = 0;
	while (i < len)
	{
		if (bin[i] == '1')
			decimal += (1 << (len - i - 1));
		i++;
	}
	return ((char)decimal);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	message[8];
	static int	i;
	static int	pid;

	(void)context;
	if (pid != info->si_pid)
		i = 0;
	if (sig == SIGUSR1)
		message[i] = '0';
	else if (sig == SIGUSR2)
		message[i] = '1';
	i++;
	if (i == 8)
	{
		message [i] = '\0';
		ft_putchar(binary_to_ascii(message));
		i = 0;
	}
	pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("%d\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
