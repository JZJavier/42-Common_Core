/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:50:45 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/29 18:16:25 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 4 && !argv[2][1] & !argv[3][1])
    {
        while (argv[1][i]!='\0')
        {
            if (argv[1][i]==argv[2][0])
            {
                argv[1][i] = argv[3][0];
            }
            write (1, &argv[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}
