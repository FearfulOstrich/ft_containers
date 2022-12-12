/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:45:00 by antoine           #+#    #+#             */
/*   Updated: 2022/12/12 17:08:26 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TPP
# define STACK_TPP

/*==============================================================================
							*********************
							* MEMBER FUNCTIONS. *
							*********************
==============================================================================*/

/*==============================================================================
	Constructors.
==============================================================================*/

/*
Default constructor.
Create stack from container.
Initializes empty container if none given.
*/
template< typename T, typename Container >
stack< T, Container >::stack( const Container& cont )
	: c( cont )
{
	return ;
}

/*
Copy constructor.
*/
template< typename T, typename Container >
stack< T, Container >::stack( const stack& other )
	: c( other.c )
{
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

/*
Stack destructor.
*/
template< typename T, typename Container >
stack< T, Container >::~stack( void )
{
	return ;
}

/*==============================================================================
	Assignation functions.
==============================================================================*/

/*
Assignation operator =
Copy all attributes of `other`.
*/

template< typename T, typename Container >
stack< T, Container >&	stack< T, Container >::operator=( const stack& other )
{
	if ( this != &other )
		c = other.c;
	return ( *this );
}

/*==============================================================================
	Element access.
==============================================================================*/

/*
Top element access as non-const value.
If stack is empty, Segfault.
*/
template< typename T, typename Container >
typename stack< T, Container >::reference	stack< T, Container >::top( void )
{
	return ( c.back() );
}

/*
Top element access as const value.
If stack is empty, Segfault.
*/
template< typename T, typename Container >
typename stack< T, Container >::const_reference	stack< T, Container >::top( void ) const
{
	return ( c.back() );
}

/*==============================================================================
	Capacity functions.
==============================================================================*/

/*
Check if container is empty.
*/
template< typename T, typename Container >
bool	stack< T, Container >::empty( void ) const
{
	return ( c.empty() );
}

/*
Check if container is empty.
*/
template< typename T, typename Container >
typename stack< T, Container >::size_type	stack< T, Container >::size( void ) const
{
	return ( c.size() );
}

/*==============================================================================
	Container modifier functions. 
==============================================================================*/


/*
Push new element to stack.
*/
template< typename T, typename Container >
void	stack< T, Container >::push( const value_type& value )
{
	c.push_back( value );
	return ;
}

/*
Remove top element from stack.
*/
template< typename T, typename Container >
void	stack< T, Container >::pop( void )
{
	c.pop_back();
	return ;
}

/*==============================================================================
							*************************
							* NON-MEMBER FUNCTIONS. *
							*************************
==============================================================================*/

/*
Equal comparison.
*/
template< typename T, typename Alloc >
bool	operator==( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs )
{
	return ( lhs.c == rhs.c );
}

/*
Different comparison
*/
template< typename T, typename Alloc >
bool	operator!=( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs )
{
	return ( !( lhs == rhs ) );
}

/*
Greater than comparison
*/
template< typename T, typename Alloc >
bool	operator>( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs )
{
	return ( lhs.c > rhs.c );
}

/*
Greater than or equal to comparison
*/
template< typename T, typename Alloc >
bool	operator>=( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs )
{
	return ( !( lhs < rhs ) );
}

/*
Less than comparison
*/
template< typename T, typename Alloc >
bool	operator<( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs )
{
	return ( lhs.c < rhs.c );
}

/*
Less than or equal to comparison
*/
template< typename T, typename Alloc >
bool	operator<=( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs )
{
	return ( !( lhs > rhs ) );
}


#endif