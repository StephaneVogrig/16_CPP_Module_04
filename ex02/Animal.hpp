/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:35:56 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/07 19:04:45 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "utils.hpp"

class Animal
{
	public:

		Animal(const std::string & type = "animal");
		Animal(const Animal & toCopy);

		virtual ~Animal(void);

		Animal & operator = (const Animal & toAssign);

		std::string getType(void) const;

		virtual void makeSound(void) const = 0;

	protected:

		std::string _type;

};

std::ostream & operator << (std::ostream & os, const Animal & animal);

#endif
