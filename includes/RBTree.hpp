/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:14:46 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/22 16:26:36 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTree_HPP
# define RBTree_HPP

#include "RBNode.hpp"

namespace ft
{

	class RBTree
	{
		//	Attibutes
		//		Root of tree;
		RBNode*	_root;

	public:
		//	Constructors
		//		Default constructor
		RBTree( void );
		//		
		
	};

	# include "RBTree.tpp"

}

#endif