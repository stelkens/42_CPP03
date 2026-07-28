#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: ClapTrap("noname", 100, 100, 30)
{
	std::cout << "FragTrap Constructor called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called for " << _name << "\n";
	*this = other;
}

FragTrap::FragTrap(const std::string name)
	: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap Constructor called for " << name << " \n";
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called for " << _name << " \n";
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << _name << ":\trequests a high five\n";
}

void	FragTrap::attack(const std::string& target){
	if(!_hitP){
		std::cout << "FragTrap " << _name << ":\twants to attack but is O.K.\n";
		return;
	}
	if(_energyP > 0){
		std::cout << "FragTrap " << _name << ":\tattacks " << target << ", causing " << _attackP << " points of damage!\n";
		--_energyP;
	}
	else
		std::cout << "FragTrap " << _name << ":\twants to attack but has no Energy Points left\n";
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if(_hitP > amount){
		std::cout << "FragTrap " << _name << ":\ttakes " << amount << " Points of damage\n";
		_hitP -= amount;
	}
	else if (_hitP > 0){
		std::cout << "FragTrap " << _name << ":\ttakes " << _hitP << " Points of damage and is O.K.\n";
		_hitP = 0;
	}
	else
		std::cout << "FragTrap " << _name << ":\tis O.K.\n";
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if(!_hitP){
		std::cout << "FragTrap " << _name << ":\twants to repair itself but is O.K.\n";
		return;
	}
	if(_energyP > 0){
		std::cout << "FragTrap " << _name << ":\trepairs itself gaining " << amount << " Hit points\n";
		--_energyP;
		_hitP += amount;
	}
	else
		std::cout << "FragTrap " << _name << ":\twants to repair itself but has no Energy Points left\n";
}