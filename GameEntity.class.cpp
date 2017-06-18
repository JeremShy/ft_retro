#include "GameEntity.class.hpp"
#include "display.hpp"

GameEntity::GameEntity(char model, unsigned int x = 0, unsigned int y = 0, unsigned int health = 0, unsigned int damage = 0) : AMovable(x, y), _model(model), _health(health), _damage(damage){
	return;
}

GameEntity::GameEntity(GameEntity const & cpy) : AMovable(cpy.getRealPositionX(), cpy.getRealPositionY()), _model(cpy.getModel()), _health(cpy.getHealth()), _damage(cpy.getDamage()){
	return;
}

GameEntity::~GameEntity(void){
	return;
}

GameEntity & 		GameEntity::operator=(GameEntity const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setRealPositionX(rhs.getRealPositionX());
		this->setRealPositionY(rhs.getRealPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}

GameEntity *		GameEntity::clone(void){
	return new GameEntity(*this);
}

void						GameEntity::attack(void) {
	// Is this method really useful ?
}

void					GameEntity::takeDamage(unsigned int amount) {
	//Maybe decrement with the armor of the GE.
	this->_health -= amount;
}

/*-----------------------------------------------------------getter*/

char				GameEntity::getModel(void) const{
	return this->_model;
}

unsigned int 		GameEntity::getHealth(void) const{
	return this->_health;
}

unsigned int 		GameEntity::getDamage(void) const{
	return this->_damage;
}

/*-----------------------------------------------------------setter*/

void				GameEntity::setModel(char model){
	this->_model = model;
	return;
}

void				GameEntity::setHealth(unsigned int health){
	this->_health = health;
	return;
}

void				GameEntity::setDamage(unsigned int damage){
	this->_damage = damage;
	return;
}

void				GameEntity::display(void) {
	mvaddch(this->getPositionY(), this->getPositionX(), this->getModel());
	// std::cout << "Displaying with values : " << this->getPositionX() << " - " << this->getPositionY() << std::endl;
}

void				GameEntity::erase(void) {
	mvdelch(this->getPositionY(), this->getPositionX());
}

int					GameEntity::colide(int amount, GameEntity** props){
	int			deathCount = 0;

	for (int i = 0; i < amount; i++){
		for (int y = i + 1; y < amount; y++){
			if (props[i] != NULL && props[y] != NULL){
				if (props[i]->getPositionX() == props[y]->getPositionX() && props[i]->getPositionY() == props[y]->getPositionY()){
					std::cout << "colision" << std::endl;
					props[i]->takeDamage(props[y]->getDamage());
					props[y]->takeDamage(props[i]->getDamage());
					if (props[i]->getHealth() == 0){
						deathCount++; props[i]->erase();delete props[i]; props[i] = NULL;
					}
					if (props[y]->getHealth() == 0){
						deathCount++; props[y]->erase();delete props[y]; props[y] = NULL;
					}
				}
			}
		}
	}
	return deathCount;
}
