/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:27:23 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/20 15:43:57 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

// exit_error.c
void	exit_error(int error_case, char *arg, char **args, int *pid);

// pipex.c
void	command_to_pipe(char *argv[], char **envp, int fd[2], int *pid);
void	command_using_pipe(char *argv[], char **envp, int fd[2], int *pid);

// verify_args.c
void	verify_args(int argc, char *argv[]);

#endif