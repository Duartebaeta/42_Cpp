#include "../incl/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_dmg = 0;
	this->max_hit = 10;
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(str new_name)
{
	this->name = new_name;
	this->hit_points = 10;
	this->max_hit = 10;
	this->energy_points = 10;
	this->attack_dmg = 0;
	std::cout << "Parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	*this = ct;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct)
{
	this->name = ct.name;
	this->hit_points = ct.hit_points;
	this->energy_points = ct.energy_points;
	this->attack_dmg = ct.attack_dmg;
	std::cout << "Copy assignment constructor called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	else if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is down, try to repair him first!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_dmg << " points of damage!" << std::endl;
	this->energy_points -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is already down, stop the violence" << std::endl;
		return ;
	}
		std::cout << "ClapTrap " << name << " has taken " << (amount > this->max_hit ? this->max_hit : amount) << " points of damage!" << std::endl;
	if (amount >= this->max_hit || this->hit_points - amount < 0)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "Debug: hit_points=" << this->hit_points << ", amount=" << amount << ", max_hit=" << this->max_hit << std::endl;

	// std::cout << "Clap " << this->name << " has " << this->hit_points << " hit point and " << this->max_hit << " max hit" << std::endl;
	if (this->energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	else if (this->hit_points >= max_hit)
	{
		std::cout << "ClapTrap " << name << " is already fully repaired!" << std::endl;
		return ;
	}
	else if (this->hit_points + amount >= this->max_hit || amount >= this->max_hit)
	{
		std::cout << "ClapTrap " << name << " has been repaired for " << this->max_hit - this->hit_points << " hit points!" << std::endl;
		this->hit_points = this->max_hit;
		this->energy_points -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << name << " has been repaired for " << amount << " hit points!" << std::endl;
		this->hit_points += amount;
		this->energy_points -= 1;
	}
}
