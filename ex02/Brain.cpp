/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:57:54 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 19:21:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* constructor ---------------------------------------------------------------*/

Brain::Brain() : _currentIndex(0), _registered(0)
{
	std::cout << CYAN "Brain default constructor called" RESET << std::endl;
}

Brain::Brain(const Brain & toCopy)
{
	std::cout << CYAN "Brain constructor by copy called" RESET << std::endl;
	*this = toCopy;
}

/* destructor ----------------------------------------------------------------*/

Brain::~Brain()
{
	std::cout << BLUE "Brain default destructor called" RESET << std::endl;
}

/* operator ------------------------------------------------------------------*/

Brain & Brain::operator = (const Brain & toAssign)
{
	std::cout << PURPLE "Brain assignation operator called" RESET << std::endl;
	_currentIndex = toAssign._currentIndex;
	_registered = toAssign._registered;
	for (int i = 0; i < 100; ++i)
		ideas[i] = toAssign.ideas[i];
	return (*this);
}

/* accessors -----------------------------------------------------------------*/
	
std::string Brain::getIdea(int i)
{
	if (i < 0 || i >= 100)
	{
		std::cout << RED "Error, idea id must be between 0 and 99!" RESET;
		return ("");
	}
	return (ideas[i]);
}
		
void Brain::addIdea(const std::string & idea)
{
	ideas[_currentIndex] = idea;
	if (_currentIndex == 99)
		_currentIndex = 0;
	else
		++_currentIndex;
	if (_registered < 100)
		++_registered;
}

/* public utilities ----------------------------------------------------------*/

void Brain::display(void)
{
	if (_registered == 0)
	{
		std::cout << RED "empty brain" RESET << std::endl;
		return ;
	}
	for (int i = 0; i < _registered; ++i)
		std::cout << "idea " << i << " : "<< ideas[i] << std::endl;
}

/* test ----------------------------------------------------------------------*/


// static void test_array(void)
// {
// 	displaySubtest("Array");
// 	Brain array[5];
// }

// static void test_constuctorByCopy(void)
// {
// 	displaySubtest("constructor by copy");

// 	std::cout << YELLOW "Create a Brain" RESET << std::endl;
// 	Brain * original = new Brain();
// 	original->addIdea("I think therefore I am");
// 	original->display();

// 	std::cout << std::endl;
// 	std::cout << YELLOW "Create a Brain by copy" RESET << std::endl;
// 	Brain copy(*original);

// 	std::cout << std::endl;
// 	std::cout << YELLOW "Delete original" RESET << std::endl;
// 	delete original;
	
// 	std::cout << std::endl;
// 	std::cout << YELLOW "copy content : " RESET << std::endl;
// 	copy.display();

// 	std::cout << std::endl;
// }

// void Brain::test(void)
// {
// 	displaySection("test Brain");

// 	test_constructor<Brain>();
// 	test_new<Brain>();
// 	test_array();
// 	test_constuctorByCopy();
// }
