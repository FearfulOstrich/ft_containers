/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.tpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:12:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/24 13:55:52 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_TPP
# define LEXICOGRAPHICAL_COMPARE_TPP

# include "binary_function.hpp"

template< T >
struct less

template< typename InputIt1, typename InputIt2 >
bool	lexicographical_compare( InputIt1 first1, InputIt1 last1,\
								InputIt2 first2, InputIt2 last2 )
{
	for ( ; ( first1 != last1 ) && ( first2 != last2 ); first1++, first2++ )
	{
		if ( *first1 < *first2 )
			return ( true );
		if ( *first1 > *first2 )
			return (false);
	}
	return ( ( first1 == last1) && ( first2 != last2 ) );
}

template< typename InputIt1, typename InputIt2 , typename Comp >
bool	lexicographical_compare( InputIt1 first1, InputIt1 last1,\
								InputIt2 first2, InputIt2 last2, Comp compare )
{
	for ( ; ( first1 != last1 ) && ( first2 != last2 ); first1++, first2++ )
	{
		if ( compare( *first1, *first2 ) )
			return ( true );
		if ( !compare( *first1, *first2 ) )
			return ( false );
	}
	return ( ( first1 == last1) && ( first2 != last2 ) );
}

#endif