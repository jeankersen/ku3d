/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:21:51 by anshimiy          #+#    #+#             */
/*   Updated: 2023/07/02 23:29:56 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int  ft_nb_split(const char *str, const char *set)
{
    char	*trimmed_str;
	int		nb;
	int		i;

	trimmed_str = ft_strtrim(str, set);
	if (!trimmed_str)
		return (-1);
	nb = 0;
	i = 0;
	if (!ft_strchr(set, trimmed_str[i]))
		nb++;
	while (trimmed_str[i])
	{
		if (ft_strchr(set, trimmed_str[i]) != NULL)
			nb++;
		i++;
	}
	free(trimmed_str);
	return (nb);
}

static size_t	get_element_size(char *str, char *set)
{
	size_t	size;

	size = 0;
	while (*str && ft_strchr(set, *str) == NULL)
	{
		size++;
		str++;
	}
	return (size);
}

char	**ft_split_set(char *str, char *set)
{
	char	**arr;
	int		arr_len;
	int		i;
	int		j;

	if (str == NULL || set == NULL)
		return (NULL);
	arr_len = ft_nb_split(str, set);
	arr = ft_calloc(arr_len + 1, sizeof(*arr));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < arr_len && *str)
	{
		while (*str && ft_strchr(set, *str) != NULL)
			str++;
		arr[i] = ft_calloc(get_element_size(str, set) + 1, sizeof(*arr[i]));
		if (!arr[i])
        {
            ft_free_str_array(arr);
            return (NULL);
        }
		j = 0;
		while (*str && ft_strchr(set, *str) == NULL)
			arr[i][j++] = *str++;
		i++;
	}
	return (arr);
}


// char **split_string(const char *str, const char *separators)
// {
//     char *copy = strdup(str);
//     char **tokens = malloc(sizeof(char *) * 10000);

//     int count = 0;
//     char *token = strtok(copy, separators);

//     while (token != NULL && count < 10000) {
//         tokens[count++] = strdup(token);
//         token = strtok(NULL, separators);
//     }

//     tokens[count] = NULL;
//     free(copy);

//     return tokens;
// }