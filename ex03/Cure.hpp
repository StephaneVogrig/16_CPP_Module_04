/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:43:02 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 23:37:22 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "utils.hpp"

class Cure : public AMateria
{
	public:

		Cure();
		Cure(const Cure & toCopy);

		~Cure();

		Cure operator = (const Cure & toAssign);

		Cure * clone() const;

		void use(ICharacter & target);

};

#endif