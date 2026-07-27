/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstelken <tstelken@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:09:47 by tstelken          #+#    #+#             */
/*   Updated: 2026/07/27 13:06:51 by tstelken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitP;
		unsigned int	_energyP;
		unsigned int	_attackP;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap(const std::string name);
		~ClapTrap();

		ClapTrap &operator =(const ClapTrap& other);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};

#endif
