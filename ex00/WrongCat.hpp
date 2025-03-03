/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:35:56 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 00:45:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"
# include "utils.hpp"

class WrongCat : public WrongAnimal
{
	public:

		WrongCat(void);
		WrongCat(const WrongCat & toCopy);

		~WrongCat(void);

		WrongCat & operator = (const WrongCat & toAssign);

		void makeSound(void) const;

		static void test(void);

};

void testWrongCat(void);

#endif
