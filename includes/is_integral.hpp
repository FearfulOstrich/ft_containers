/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:15:31 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/14 10:08:51 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template< typename T, T v >
	struct integral_constant
	{
		// Typedefs
		typedef T	value_type;
		typedef integral_constant< T, v >	type; 

		// Attributes
		static const value_type	value = v;

		// Operators
		operator value_type() const;
	};

	typedef integral_constant< bool, true >		true_type;
	typedef integral_constant< bool, false >	false_type;

	template< typename T >
	struct is_integral: public false_type { };

	template< >
	struct is_integral< bool >: public true_type { };

	template< >
	struct is_integral< char >: public true_type { };

	template< >
	struct is_integral< wchar_t >: public true_type { };

	template< >
	struct is_integral< short >: public true_type { };

	template< >
	struct is_integral< int >: public true_type { };

	template< >
	struct is_integral< long >: public true_type { };

	template< >
	struct is_integral< long long >: public true_type { };

	template< >
	struct is_integral< unsigned char >: public true_type { };

	template< >
	struct is_integral< unsigned short >: public true_type { };

	template< >
	struct is_integral< unsigned int >: public true_type { };

	template< >
	struct is_integral< unsigned long >: public true_type { };

	template< >
	struct is_integral< unsigned long long >: public true_type { };

	template< >
	struct is_integral< const bool >: public true_type { };

	template< >
	struct is_integral< const char >: public true_type { };

	template< >
	struct is_integral< const wchar_t >: public true_type { };

	template< >
	struct is_integral< const short >: public true_type { };

	template< >
	struct is_integral< const int >: public true_type { };

	template< >
	struct is_integral< const long >: public true_type { };

	template< >
	struct is_integral< const long long >: public true_type { };

	template< >
	struct is_integral< const unsigned char >: public true_type { };

	template< >
	struct is_integral< const unsigned short >: public true_type { };

	template< >
	struct is_integral< const unsigned int >: public true_type { };

	template< >
	struct is_integral< const unsigned long >: public true_type { };

	template< >
	struct is_integral< const unsigned long long >: public true_type { };

	# include "is_integral.tpp"

}

#endif