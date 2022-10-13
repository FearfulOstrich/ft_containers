/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:09:19 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/13 12:14:17 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
	// equal with two iterators.
	template< typename InputIt1, typename InputIt2 >
	bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 );
	// equal with two iterators and a binary predicate
	template< typename InputIt1, typename InputIt2 , typename BinaryPredicate >
	bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2,\
					BinaryPredicate p );

# include "equal.tpp"

}

#endif