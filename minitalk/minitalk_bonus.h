/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:10:29 by nchaknan          #+#    #+#             */
/*   Updated: 2023/02/08 12:15:37 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"

void	send_char_binary(int pid, char c);
void	signal_handler(int sig, siginfo_t *info, void *context);
void	ft_putchar(char c);
void	check_pid(char **argv, int pid);

int		ft_strlen(char *s);
int		ft_atoi(char *str);
int		ft_isdigit(int n);

char	binary_to_ascii(char *bin);

#endif