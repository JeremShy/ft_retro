#include "Enemy.class.hpp"
#include "EnemyA.class.hpp"
#include "EnemyB.class.hpp"
#include "GameEntity.class.hpp"
#include "Hero.class.hpp"
#include "IPrintable.class.hpp"
#include "RenderMachine.class.hpp"
#include "display.hpp"


int main() {
	Enemy **tab = new Enemy*[20];
	*tab = new EnemyA[10];
	*(tab + 10) = new EnemyB[10];
}
