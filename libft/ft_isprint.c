/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:58:15 by ombatkam          #+#    #+#             */
/*   Updated: 2024/10/08 12:10:31 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main() {
    
	char test1 = 'A';    
    char test2 = ' ';    
    char test3 = '~';    
    char test4 = '\n';   
	char test5 = 127;    

    printf("ft_isprint('%c') = %d\n", test1, ft_isprint(test1)); 
    printf("ft_isprint('%c') = %d\n", test2, ft_isprint(test2)); 
    printf("ft_isprint('%c') = %d\n", test3, ft_isprint(test3)); 
    printf("ft_isprint('\\n') = %d\n", ft_isprint(test4));       
    printf("ft_isprint(127) = %d\n", ft_isprint(test5));
	printf("ft_isprint('%c') = %d\n", test1, isprint(test1)); 
    printf("ft_isprint('%c') = %d\n", test2, isprint(test2)); 
    printf("ft_isprint('%c') = %d\n", test3, isprint(test3)); 
    printf("ft_isprint('\\n') = %d\n", isprint(test4));      
    printf("ft_isprint(127) = %d\n", isprint(test5));	

    return 0;
}
*/
