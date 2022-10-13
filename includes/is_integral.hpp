/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:15:31 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/13 16:32:44 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template< typename T, T v >
	struct integral_constant;
	
	template< typename T >
	struct is_integral: public false_type
	{
		// Typedefs
		typedef bool	value_type

		// Attributes
		static value_type	value;

		// Operators
		value_type	operator bool() const;
	}

	# include "is_integral.tpp"

}

#endif