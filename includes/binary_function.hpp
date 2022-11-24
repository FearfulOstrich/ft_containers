/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_function.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:22:54 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/23 14:25:37 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_FUNCTION_HPP
# define BINARY_FUNCTION_HPP

namespace ft
{
	template< typename Arg1, typename Arg2, typename Result >
	struct binary_function
	{
		//	Typedefs
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};
}

#endif