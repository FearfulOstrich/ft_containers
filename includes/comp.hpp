/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:41:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/02 19:55:36 by antoine          ###   ########.fr       */
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
		bool	operator()( const T& lhs, const T& rhs ) const;
	};

	# include "comp.tpp"
}

#endif