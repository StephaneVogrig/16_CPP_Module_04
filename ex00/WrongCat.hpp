/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:35:56 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/02 23:44:56 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"
# include "display.hpp"

class WrongCat : public WrongAnimal
{
	public:

		WrongCat(void);
		WrongCat(const WrongCat & wrongCat);

		~WrongCat(void);

		WrongCat & operator = (const WrongCat & wrongCat);

		void makeSound(void) const;

};

void testWrongCat(void);

#endif
