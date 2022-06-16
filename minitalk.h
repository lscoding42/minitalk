/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 02:16:29 by lhafsi            #+#    #+#             */
/*   Updated: 2022/06/15 03:08:03 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// CLIENT
char			*convert_bin(unsigned char chr);
void			send_sig(int pid, char *msg);
void			listen_server_sig(int sig);

// SERVEUR
int				ft_bin_to_uc(char *str);
void    		f_sig(int sig, siginfo_t *meta, void *context);

// LES PUTS
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);

// ATOI
int				ft_is_digit(int c);
int				ft_is_space(unsigned char c);
int				ft_atoi(char *str);

// LES STRS
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *dest, char *src);
char			*ft_strjoin(char *s1, char *s2);

#endif