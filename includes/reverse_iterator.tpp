/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:16:54 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/17 17:38:34 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

template< typename Iter >
reverse_iterator< Iter >::reverse_iterator( void )
	: current()
{
	return ;
}

template< typename Iter >
reverse_iterator< Iter >::reverse_iterator( iterator_type x )
	: current(x)
{
	return ;
}

template< typename Iter >
template< typename U >
reverse_iterator< Iter >::reverse_iterator( const reverse_iterator< U >& other)
{
	*this = other;
	return ;
}

template< typename Iter >
reverse_iterator< Iter >&	reverse_iterator< Iter >::operator=(\
							const reverse_iterator< Iter >& other)
{
	if (this != &other)
		current = other.current;
	return (*this);
}

template< typename Iter >
reverse_iterator::iterator_type	reverse_iterator< Iter >::base( void ) const
{
	return (current);
}

template< typename Iter >
reverse_iterator::reference	reverse_iterator< Iter >::operator*( void ) const
{
	return (*(current - 1));
}

template< typename Iter >
reverse_iterator::pointer	reverse_iterator< Iter >::operator->( void ) const
{
	return (current - 1);
}