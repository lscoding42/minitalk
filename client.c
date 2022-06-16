/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/06/15 03:09:57 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3)
	{
		write(1, "Error: missing argument\n", 24);
		return (1);
	}
	i = -1;
	signal(SIGUSR1, listen_server_sig);
	pid = ft_atoi(av[1]);
	send_sig(pid, av[2]);
	while (++i < 8)
	{
		usleep(5000);
		kill(pid, SIGUSR2);
	}
}
