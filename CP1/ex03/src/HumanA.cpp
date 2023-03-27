#include "../incl/HumanA.hpp"

HumanA::HumanA(str name, Weapon& weapon) : _weapon(weapon)
{
	this->_name = name;
	this->_weapon = weapon;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}