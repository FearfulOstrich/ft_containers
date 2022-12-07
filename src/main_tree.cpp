/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tree.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:53:44 by antoine           #+#    #+#             */
/*   Updated: 2022/12/06 10:20:19 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RBNode.hpp"
#include "RBTree.hpp"
#include "comp.hpp"


int main()
{
	ft::RBTree< int >	my_tree;

	std::cout << "sentinel: " << my_tree.get_root() << std::endl;
	std::cout << "4 nodes: " << std::endl;

	my_tree.insert( 12, ft::less< int >() );
	my_tree.insert( 14, ft::less< int >() );
	my_tree.insert( 9, ft::less< int >() );
	my_tree.insert( 17, ft::less< int >() );
	std::cout << "Inside tree: " << std::endl;
	std::cout << "root: " << my_tree.get_root()->content << std::endl;
	std::cout << "root->left: " << my_tree.get_root()->left->content << std::endl;
	std::cout << "root->left->left: " << my_tree.get_root()->left->left->content << std::endl;
	std::cout << "root->left->right: " << my_tree.get_root()->left->right->content << std::endl;
	std::cout << "root->right: " << my_tree.get_root()->right->content << std::endl;
	std::cout << "root->right->left: " << my_tree.get_root()->right->left->content << std::endl;
	std::cout << "root->right->right: " << my_tree.get_root()->right->right->content << std::endl;
	my_tree.remove( 14, ft::less< int >() );
	std::cout << "Inside tree: " << std::endl;
	std::cout << "root: " << my_tree.get_root()->content << std::endl;
	std::cout << "root->left: " << my_tree.get_root()->left->content << std::endl;
	std::cout << "root->left->left: " << my_tree.get_root()->left->left->content << std::endl;
	std::cout << "root->left->right: " << my_tree.get_root()->left->right->content << std::endl;
	std::cout << "root->right: " << my_tree.get_root()->right->content << std::endl;
	std::cout << "root->right->left: " << my_tree.get_root()->right->left->content << std::endl;
	std::cout << "root->right->right: " << my_tree.get_root()->right->right->content << std::endl;
	
}