/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:20:16 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/24 13:59:24 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMP_TPP
# define COMP_TPP

/*
less - Operator().
Effectively calls `lhs` < `rhs`.
*/
template< typename T >
bool	less< T >::operator()( const T& lhs, const T& rhs )
{
	return ( lhs < rhs );
}

/*
greater - Operator().
Effectively calls `lhs` > `rhs`.
*/
template< typename T >
bool	greater< T >::operator()( const T& lhs, const T& rhs )
{
	return ( lhs > rhs );
}

#endif