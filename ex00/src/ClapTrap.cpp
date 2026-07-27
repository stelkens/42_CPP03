/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstelken <tstelken@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:09:32 by tstelken          #+#    #+#             */
/*   Updated: 2026/07/27 15:23:48 by tstelken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): _name(""), _hitP(10), _energyP(10), _attackP(0){
	std::cout << "Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other){
	std::cout << "Copy constructor called\n";
	*this = other;
}

ClapTrap::ClapTrap(const std::string name): _name(name), _hitP(10), _energyP(10), _attackP(0){
	std::cout << "Constructor called\n";
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called\n";
}

//Asignment operator

ClapTrap &ClapTrap::operator=(const ClapTrap& other){
	if (this != &other)
	{
		this->_name = other._name + ".copy";
		this->_hitP = other._hitP;
		this->_energyP = other._energyP;
		this->_attackP = other._attackP;
	}
	return *this;
}

//Functions

void	ClapTrap::attack(const std::string& target){
	if(!_hitP){
		std::cout << "ClapTrap " << _name << ":\twants to attack but is O.K.\n";
		return;
	}
	if(_energyP > 0){
		std::cout << "ClapTrap " << _name << ":\tattacks " << target << ", causing " << _attackP << " points of damage!\n";
		--_energyP;
	}
	else
		std::cout << "ClapTrap " << _name << ":\twants to attack but has no Energy Points left\n";
}

void	ClapTrap::takeDamage(unsigned int amount){
	if(_hitP > amount){
		std::cout << "ClapTrap " << _name << ":\ttakes " << amount << " Points of damage\n";
		_hitP -= amount;
	}
	else if (_hitP > 0){
		std::cout << "ClapTrap " << _name << ":\ttakes " << _hitP << " Points of damage and is O.K.\n";
		_hitP = 0;
	}
	else
		std::cout << "ClapTrap " << _name << ":\tis O.K.\n";
}

void	ClapTrap::beRepaired(unsigned int amount){
	if(!_hitP){
		std::cout << "ClapTrap " << _name << ":\twants to repair itself but is O.K.\n";
		return;
	}
	if(_energyP > 0){
		std::cout << "ClapTrap " << _name << ":\trepairs itself gaining " << amount << " Hit points\n";
		--_energyP;
		_hitP += amount;
	}
	else
		std::cout << "ClapTrap " << _name << ":\twants to repair itself but has no Energy Points left\n";
}