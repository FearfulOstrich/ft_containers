/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.tpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:12:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/12 16:36:39 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_TPP
# define LEXICOGRAPHICAL_COMPARE_TPP

template< typename InputIt1, typename InputIt2 >
bool	lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 )
{
	for ( ; ( first1 != last1 ) && ( first2 != last2 ); first1++, first2++ )
	{
		if ( *first1 < *first2 )
			return ( true );
		if ( *first2 < *first1 )
			return ( false );
	}
	return ( ( first1 == last1) && ( first2 != last2 ) );
}

template< typename InputIt1, typename InputIt2 , typename Comp >
bool	lexicographical_compare( InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2, Comp compare )
{
	for ( ; ( first1 != last1 ) && ( first2 != last2 ); first1++, first2++ )
	{
		if ( compare( *first1, *first2 ) )
			return ( true );
		if ( compare( *first2, *first1 ) )
			return ( false );
	}
	return ( ( first1 == last1) && ( first2 != last2 ) );
}

#endif