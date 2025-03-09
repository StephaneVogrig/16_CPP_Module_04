/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:35:56 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 17:07:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include "utils.hpp"

class AAnimal
{
	public:

		AAnimal(const std::string & type = "animal");
		AAnimal(const AAnimal & toCopy);

		virtual ~AAnimal(void);

		AAnimal & operator = (const AAnimal & toAssign);

		std::string getType(void) const;

		virtual void makeSound(void) const = 0;

	protected:

		std::string _type;

};

std::ostream & operator << (std::ostream & os, const AAnimal & animal);

#endif
