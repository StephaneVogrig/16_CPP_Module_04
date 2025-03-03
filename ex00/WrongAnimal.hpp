/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:35:56 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/02 23:33:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "display.hpp"

class WrongAnimal
{
	public:

		WrongAnimal(void);
		WrongAnimal(const WrongAnimal & wrongAnimal);

		virtual ~WrongAnimal(void);

		WrongAnimal & operator = (const WrongAnimal & wrongAnimal);

		std::string getType(void) const;

		void makeSound(void) const;

	protected:

		std::string _type;

};

std::ostream & operator << (std::ostream & os, const WrongAnimal & wrongAnimal);

void testWrongAnimal(void);

#endif
