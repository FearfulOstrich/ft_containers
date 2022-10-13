/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:25:25 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/13 16:29:31 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_TPP
# define IS_INTEGRAL_TPP

template< typename T >
value_type	is_integral< T >::operator bool() const
{
	return ( value );
}

template< typename T >
value_type	is_integral< T >::value = false;
template< >
value_type	is_integral< bool >::value = true;
template< >
value_type	is_integral< char >::value = true;
template< >
value_type	is_integral< wchar_t >::value = true;
template< >
value_type	is_integral< short >::value = true;
template< >
value_type	is_integral< int >::value = true;
template< >
value_type	is_integral< long >::value = true;
template< >
value_type	is_integral< long long >::value = true;
template< >
value_type	is_integral< signed bool >::value = true;
template< >
value_type	is_integral< signed char >::value = true;
template< >
value_type	is_integral< signed wchar_t >::value = true;
template< >
value_type	is_integral< signed short >::value = true;
template< >
value_type	is_integral< signed int >::value = true;
template< >
value_type	is_integral< signed long >::value = true;
template< >
value_type	is_integral< signed long long >::value = true;
template< >
value_type	is_integral< unsigned bool >::value = true;
template< >
value_type	is_integral< unsigned char >::value = true;
template< >
value_type	is_integral< unsigned wchar_t >::value = true;
template< >
value_type	is_integral< unsigned short >::value = true;
template< >
value_type	is_integral< unsigned int >::value = true;
template< >
value_type	is_integral< unsigned long >::value = true;
template< >
value_type	is_integral< unsigned long long >::value = true;
template< >
value_type	is_integral< const bool >::value = true;
template< >
value_type	is_integral< const char >::value = true;
template< >
value_type	is_integral< const wchar_t >::value = true;
template< >
value_type	is_integral< const short >::value = true;
template< >
value_type	is_integral< const int >::value = true;
template< >
value_type	is_integral< const long >::value = true;
template< >
value_type	is_integral< const long long >::value = true;
template< >
value_type	is_integral< const signed bool >::value = true;
template< >
value_type	is_integral< const signed char >::value = true;
template< >
value_type	is_integral< const signed wchar_t >::value = true;
template< >
value_type	is_integral< const signed short >::value = true;
template< >
value_type	is_integral< const signed int >::value = true;
template< >
value_type	is_integral< const signed long >::value = true;
template< >
value_type	is_integral< const signed long long >::value = true;
template< >
value_type	is_integral< const unsigned bool >::value = true;
template< >
value_type	is_integral< const unsigned char >::value = true;
template< >
value_type	is_integral< const unsigned wchar_t >::value = true;
template< >
value_type	is_integral< const unsigned short >::value = true;
template< >
value_type	is_integral< const unsigned int >::value = true;
template< >
value_type	is_integral< const unsigned long >::value = true;
template< >
value_type	is_integral< const unsigned long long >::value = true;

#endif