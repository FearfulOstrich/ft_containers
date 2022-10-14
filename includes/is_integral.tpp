/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:25:25 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/14 10:09:07 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_TPP
# define IS_INTEGRAL_TPP

// template< typename T, T v >
// static const T	value = v;

template< typename T, T v >
integral_constant< T, v >::operator T() const
{
	return ( value );
}

#endif