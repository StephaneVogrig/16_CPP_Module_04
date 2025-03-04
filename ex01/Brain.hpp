/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:57:45 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 16:20:52 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <sstream>
# include <string>
# include "utils.hpp"

class Brain
{
	private:

		std::string ideas[100];
		int			_currentIndex;
		int			_registered;

	public:

		Brain();
		Brain(const Brain & toCopy);

		Brain & operator = (const Brain & toAssign);

		~Brain();

		std::string getIdea(int i);

		void addIdea(const std::string & idea);
		
		void display(void);

};

#endif
