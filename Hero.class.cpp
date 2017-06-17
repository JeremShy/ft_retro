Hero::Hero(void) : GameEntity(this->c_model){
	this->setHealth(this->c_health);
	this->setDamage(this->c_damage);
	return;
}

Hero::Hero(Hero const & cpy) : GameEntity(cpy.getModel()){
	*this = cpy;
	return;
}

Hero::~Hero(void){
	return;
}

Hero &			Hero::operator=(Hero const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setPositionX(rhs.getPositionX());
		this->setPositionY(rhs.getPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}

Hero *			Hero::clone(void){
	return new Hero(*this);
}

void			Hero::attack(void) const{

}

void			Hero::takeDamage(unsigned int damage){
	this->setHealth(this->getHealth() - damage);
	if (this->getHealth() == 0){
		//die + end of game
	}
	return;
}