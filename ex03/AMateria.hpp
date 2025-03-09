/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:29:55 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 22:42:20 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "utils.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria & materia);
		
		virtual ~AMateria(void);
		
		AMateria & operator = (const AMateria & toAssign);

		std::string const & getType() const;

		virtual AMateria * clone() const = 0;
		virtual void use(ICharacter & target);

};

std::ostream & operator << (std::ostream & os, const AMateria & materia);

#endif