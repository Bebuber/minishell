/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 03:04:51 by amecani           #+#    #+#             */
/*   Updated: 2024/07/06 04:56:08 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ! Add the code from github to school_repo

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# define CTRL_D		55	//? CTRL_D sends a (null) to read_line
						//?		,which is EOF (End Of File) signal
# define MALLOC_FAIL 0

// Quote Types
# define SINGLE -1
# define DOUBLE -2

# include <readline/readline.h>

typedef enum s_type
{
	WORD,
	PIPE,
	IN,
	H_DOC,
	OUT,
	APPEND,
	ERR,
	END
}					t_type;

typedef struct s_token
{
	t_type			type;
	char			*string;
	char			quote_type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_terminal_inputs
{
	char			*input;
	char **env;									//! add envp
}					t_terminal_inputs;

int		command_center(t_terminal_inputs *terminal);
int		check_gaps_and_clear(char *s);
int		extract_token_characteristic(char *s, t_token *token);
void	free_tokens(t_token *token);
char	*extract_text(char *s);
t_token	*init_deafult_token(t_token *token);

//		U T I L I T I E S

//?		Checks if the string is "clear" or
//?		if it's only filled with spaces and tabs (gaps)
int		gap(char c);

#endif