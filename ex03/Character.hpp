/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:48:13 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 22:46:12 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(const std::string & name = "noName");
		Character(const Character & toCopy);
		
		~Character(void);
		
		Character & operator = (const Character & toAssign);
		
		std::string const & getName() const;
		
		void equip(AMateria * m);
		void unequip(int idx);
		void use(int idx, ICharacter & target);

	private:

		static const int	_inventorySize = 4;
		std::string			_name;
		AMateria *			_inventory[_inventorySize];

};

#endif
