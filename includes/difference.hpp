/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:12:02 by antoine           #+#    #+#             */
/*   Updated: 2022/11/17 23:18:45 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFFERENCE_HPP
# define DIFFERENCE_HPP

# include "iterator_traits.hpp"

namespace ft
{
	//	Difference between two iterators.
	template< typename InputIt >
	typename ft::iterator_traits< InputIt >::difference_type	difference( InputIt first, InputIt last );
 
	# include "difference.tpp"

}

#endif