/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:09:43 by lhafsi            #+#    #+#             */
/*   Updated: 2022/06/15 00:41:21 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
    struct	sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = f_sig;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    ft_putnbr(getpid());
    write(1, "\n", 1);

    while (1)
        pause();
}
