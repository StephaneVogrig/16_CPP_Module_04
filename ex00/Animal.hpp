/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:35:56 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/02 23:22:56 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "display.hpp"

class Animal
{
	public:

		Animal(void);
		Animal(const Animal & animal);

		virtual ~Animal(void);

		Animal & operator = (const Animal & animal);

		std::string getType(void) const;

		virtual void makeSound(void) const;

	protected:

		std::string _type;

};

std::ostream & operator << (std::ostream & os, const Animal & animal);

void testAnimal(void);

#endif
