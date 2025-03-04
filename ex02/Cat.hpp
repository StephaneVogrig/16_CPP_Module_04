/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:35:56 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 19:17:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"
# include "utils.hpp"

class Cat : public Animal
{
	public:

		Cat(void);
		Cat(const Cat & toCopy);

		~Cat(void);

		Cat & operator = (const Cat & toAssign);

		void makeSound(void) const;

		void addIdea(const std::string & idea);
		void display(void);

	private:

		Brain * _brain;

};

#endif
