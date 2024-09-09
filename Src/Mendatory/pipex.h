/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:27:23 by nsauret           #+#    #+#             */
/*   Updated: 2024/09/09 11:38:32 by nsauret          ###   ########.fr       */
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
void	command_to_pipe(char *argv[], char *envp[], int fd[2], int *pid);
void	command_using_pipe(char *argv[], char *envp[], int fd[2], int *pid);

// get_path.c
char	*get_path(char *envp[], char **args, int *pid);

#endif