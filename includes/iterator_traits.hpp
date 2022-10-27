/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:16:01 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/26 14:20:37 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <cstddef>

namespace ft
{

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag: public input_iterator_tag { };
	struct bidirectional_iterator_tag: public forward_iterator_tag { };
	struct random_access_iterator_tag: public bidirectional_iterator_tag { };
	
	template< typename T >
	struct iterator_traits
	{
		// Typedefs
		typedef T									Iter;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template< typename T >
	struct iterator_traits< T* >
	{
		// Typedefs
		typedef std::ptrdiff_t				difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template< typename T >
	struct iterator_traits< const T* >
	{
		// Typedefs
		typedef std::ptrdiff_t				difference_type;
		typedef T							value_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

}

#endif