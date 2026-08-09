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