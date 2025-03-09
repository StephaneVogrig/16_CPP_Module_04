/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:40:57 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 17:26:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:

		MateriaSource(void);
		MateriaSource(const MateriaSource & toCopy);

		~MateriaSource(void);

		MateriaSource & operator = (const MateriaSource & toAssign);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:

		static const int	_inventorySize = 4;
		AMateria *			_inventory[_inventorySize];

};

#endif
