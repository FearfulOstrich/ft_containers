/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:20:16 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/02 19:55:31 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMP_TPP
# define COMP_TPP

/*
less - Operator().
Effectively calls `lhs` < `rhs`.
*/
template< typename T >
bool	less< T >::operator()( const T& lhs, const T& rhs ) const
{
	return ( lhs < rhs );
}

/*
greater - Operator().
Effectively calls `lhs` > `rhs`.
*/
template< typename T >
bool	greater< T >::operator()( const T& lhs, const T& rhs ) const
{
	return ( lhs > rhs );
}

#endif