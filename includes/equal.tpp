/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:12:36 by aalleon           #+#    #+#             */
/*   Updated: 2023/01/06 14:06:35 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_TPP
# define EQUAL_TPP

template< typename InputIt1, typename InputIt2 >
bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
{
	for ( ; first1 != last1; first1++, first2++ )
	{
		if ( *first1 != *first2 )
			return ( false );
	}
	return ( true );
}

template< typename InputIt1, typename InputIt2 , typename BinaryPredicate >
bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p )
{
	for ( ; first1 != last1; first1++, first2++ )
	{
		if ( !p( *first1, *first2 ))
			return ( false );
	}
	return ( true );
}

#endif