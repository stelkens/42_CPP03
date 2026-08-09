/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstelken <tstelken@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:49:41 by tstelken          #+#    #+#             */
/*   Updated: 2026/08/09 19:19:08 by tstelken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
	: ClapTrap("noname", 100, 50, 20)
{
	std::cout << "ScavTrap Constructor called\n";
	_guardMode = false;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called for " << _name << "\n";
	*this = other;
}

ScavTrap::ScavTrap(const std::string name)
	: ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap Constructor called for " << name << " \n";
	_guardMode = false;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called for " << _name << " \n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_guardMode = other._guardMode;
	}
	return *this;
}

void	ScavTrap::guardGate(void){
	if(_guardMode){
		std::cout << "ScavTrap " << _name << ":\twas already in Gate keeper mode\n";
		return ;
	}
	_guardMode = true;
	std::cout << "ScavTrap " << _name << ":\tis now in Gate keeper mode\n";
}

void	ScavTrap::attack(const std::string& target){
	if(!_hitP){
		std::cout << "ScavTrap " << _name << ":\twants to attack but is O.K.\n";
		return;
	}
	if(_energyP > 0){
		std::cout << "ScavTrap " << _name << ":\tattacks " << target << ", causing " << _attackP << " points of damage!\n";
		--_energyP;
	}
	else
		std::cout << "ScavTrap " << _name << ":\twants to attack but has no Energy Points left\n";
}