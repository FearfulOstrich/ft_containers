/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:41:46 by antoine           #+#    #+#             */
/*   Updated: 2022/12/07 08:43:28 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
# define RBTree_ITERATOR_HPP

# include<cstddef>

namespace ft
{
	template< typename T >
	class RBTree_iterator
	{
	public:
		//	Typedefs
		typedef std::ptrdiff_t						difference_type;
		typedef typename RBNode< T >::value_type	value_type;
		typedef typename RBNode< T >::pointer		pointer;
		typedef typename RBNode< T >::reference		reference;
		typedef 
	}
}

#endif