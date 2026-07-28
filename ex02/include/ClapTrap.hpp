/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstelken <tstelken@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:09:47 by tstelken          #+#    #+#             */
/*   Updated: 2026/07/28 11:49:15 by tstelken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<string>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitP;
		unsigned int	_energyP;
		unsigned int	_attackP;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap(const std::string name);
		ClapTrap(const std::string name,
				const unsigned int hitP, 
				const unsigned int energyP,
				const unsigned int attackP);
		virtual ~ClapTrap();

		ClapTrap &operator =(const ClapTrap& other);

		virtual void	attack(const std::string& target); // virtual so i can overrid the method in ScavTrap
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);

};

#endif
