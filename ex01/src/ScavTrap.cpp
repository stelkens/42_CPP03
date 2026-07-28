/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstelken <tstelken@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:49:41 by tstelken          #+#    #+#             */
/*   Updated: 2026/07/28 10:14:26 by tstelken         ###   ########.fr       */
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

void	ScavTrap::takeDamage(unsigned int amount)
{
	if(_hitP > amount){
		std::cout << "ScavTrap " << _name << ":\ttakes " << amount << " Points of damage\n";
		_hitP -= amount;
	}
	else if (_hitP > 0){
		std::cout << "ScavTrap " << _name << ":\ttakes " << _hitP << " Points of damage and is O.K.\n";
		_hitP = 0;
	}
	else
		std::cout << "ScavTrap " << _name << ":\tis O.K.\n";
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if(!_hitP){
		std::cout << "ScavTrap " << _name << ":\twants to repair itself but is O.K.\n";
		return;
	}
	if(_energyP > 0){
		std::cout << "ScavTrap " << _name << ":\trepairs itself gaining " << amount << " Hit points\n";
		--_energyP;
		_hitP += amount;
	}
	else
		std::cout << "ScavTrap " << _name << ":\twants to repair itself but has no Energy Points left\n";
}