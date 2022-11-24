/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:41:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/24 14:07:06 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMP_HPP
# define COMP_HPP

# include "binary_function.hpp"

namespace ft
{
	template< typename T >
	struct less: public binary_function< T, T, bool >
	{
		//	Operator ()
		bool	operator()( const T& lhs, const T& rhs) const;
	};

	template< typename T >
	struct greater: public binary_function< T, T, bool >
	{
		//	Operator ()
		bool	operator()( const T& lhs, const T& rhs );
	};

	# include "comp.tpp"
}

#endif