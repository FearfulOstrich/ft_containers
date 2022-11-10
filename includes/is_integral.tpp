/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:25:25 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/10 10:12:52 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_TPP
# define IS_INTEGRAL_TPP

template< typename T, T v >
integral_constant< T, v >::operator T() const
{
	return ( value );
}

#endif