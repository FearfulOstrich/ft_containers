/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:19:21 by antoine           #+#    #+#             */
/*   Updated: 2022/11/18 08:28:36 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFFERENCE_TPP
# define DIFFERENCE_TPP

template< typename InputIt >
typename ft::iterator_traits< InputIt >::difference_type	difference( InputIt first, InputIt last )
{
	typename ft::iterator_traits< InputIt >::difference_type	size = 0;
	while ( first != last )
	{
		size++;
		first++;
	}
	return ( size );
}

#endif