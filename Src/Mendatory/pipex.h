/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:27:23 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/30 18:10:13 by nathan           ###   ########.fr       */
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

#endif