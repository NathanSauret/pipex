/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:27:23 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/20 12:35:24 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

// exit_error.c
void	exit_error(int error_case, char *arg);

// pipex.c
void	first_command(char *argv[], int fd[2]);
void	middle_command(char *arg, char *argv[], int argc, int fd[2]);
void	last_command(char *argv[], int argc, int fd[2], int write_way);

// verify_args.c
void	verify_args(int argc, char *argv[]);

#endif