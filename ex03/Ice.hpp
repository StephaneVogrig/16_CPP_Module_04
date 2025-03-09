/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:42:13 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 23:37:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "utils.hpp"

class Ice : public AMateria
{
	public:

		Ice();
		Ice(const Ice & toCopy);

		~Ice();

		Ice operator = (const Ice & toAssign);

		Ice * clone() const;

		void use(ICharacter & target);

};

#endif