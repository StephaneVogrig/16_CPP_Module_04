/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:35:56 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 16:27:28 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"
# include "utils.hpp"

class Dog : public Animal
{
	public:

		Dog(void);
		Dog(const Dog & toCopy);

		~Dog(void);

		Dog & operator = (const Dog & toAssign);

		void makeSound(void) const;

		void addIdea(const std::string & idea);
		void display(void);

	private:

		Brain * _brain;

};

#endif
