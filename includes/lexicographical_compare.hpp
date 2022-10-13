/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:23:16 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/13 14:09:08 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
	// equal with two iterators.
	template< typename InputIt1, typename InputIt2 >
	bool	lexicographical_compare( InputIt1 first1, InputIt1 last1,\
									InputIt2 first2, InputIt2 last2 );
	// equal with two iterators and a binary predicate
	template< typename InputIt1, typename InputIt2 , typename Comp >
	bool	lexicographical_compare( InputIt1 first1, InputIt1 last1,\
									InputIt2 first2, InputIt2 last2,\
									Comp compare );

# include "lexicographical_compare.tpp"

}

#endif