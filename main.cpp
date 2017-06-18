/*TRUCS A FAIRE IMPORTANT:
	Déjà bonjour. J'espere que tu as passé une bonne soirée hier et que tu as bien dormi.

	Bon, en fait c'est un petit peu la galere, y a encore pas mal de trucs à faire. Et je t'ecris ce message à 2h40 du mat' avec la tête dans le cul,
	après avoir passé une heure et demi à aider une amie sur son rush de piscine PHP.

	Donc en gros j'ai pensé à pas mal de concepts un peu chiant qu'il va falloir implementer, genre par exemple simplement les delete.
	En fait faut qu'on réflechisse à où est ce qu'on veut delete chaque truc. Je pense que c'est le moteur de collision qui va le plus gérer ça,
	du coup il faudra qu'il est aisément accès à nos différents moteurs pour pouvoir virer les trucs des moteurs à leur mort/disparition.

	Je pense que notre truc de gerage de collisions va devoir gérer les collisions pour n'importe quel IMovable. Meme les bullets. Parce que de toutes façons,
	pour l'instant en tous cas, n'importe quel truc qui bouge peut taper des trucs ou sortir de la fenetre x).

	Alors du coup pour les bullets va falloir les supprimer lorsqu'elles sortent de la fenetre ou qu'elles tapent une cible.
	Pareil pour les ennemis.

	Du coup pour en revenir au truc de collisions, je sais pas trop sous quelle forme faire ça. Ptet un CollisionMotor qui aura en permanence un tableau de IMovable* rempli dynamiquement à la facon des autres motors.
	A la différence qu'il aura une fonction qui renverra un booleen selon si un objet en touche un autre. En appelant genre une fonction `bool IPrintable::doesCollide(IPrintable *object)` que chaque IPrintable* devra
	implémenter qui renverra vrai ou faux selon si deux elements données se superposent ou pas.
	En y refléchissant on pourrait peut être implémenter ça direct dans MotorMachine(). Le truc important est qu'un IPrintable détruit par les collisions devra être delete à cet endroit-ci du code (et pas autre part du coup)

	Sinon il reste le spawn d'ennemis aléatoires dans un endroit cool de la map. Apres la comme tu le verras plus bas, j'ai réussi à implémenter un moyen simple de faire un évènement toutes les X millisecondes. Du coup je doute que ce soit très complexe.

	En fait en ecrivant ça je me rends compte que ça peut aller le taff qu'il reste, en gros je vois:
	 (1): Bidouiller MotorMachine et IPrintable pour rajouter quelques fonctions de gestion de collisions, et pour qu'il delete les items détruits.
	 (2): Implémenter le spawn d'ennemis.

	Je pense que tu devrais faire l'implémentation de la gestion de collision en priorité, car c'est le plus difficile des deux, et le plus à risque (il est préfeerable que notre gestion de collisions soit biens et notre systeme
	de spawn de mobs merdique que l'inverse).

	Je pense sincerement que tu devrais faire l'implementation de la facon dont je l'ai décrite ci-dessus, donc dans MotorMachine, ça m'a vraiment l'air le plus simple pour plusieurs raisons :
		- On a deja acces à notre MotorMachine dans MotorMachine donc pas de soucis de parametres à faire transiter par 15 fonctions. Par contre faudra trouver un moyen de le virer de notre RenderMachine si un item est détruit. au pire on peut rajouter un attribut RenderMachine à notre MotorMachine qui donnerait l'adresse de la RenderMachine pour pouvoir supprimer les items.
		- On s'est déjà fait chier à faire un systeme de tableau dynamique dans RenderMachine dans lequel sont logiquement tous les trucs collisionables.

	Après si tu penses que ca a plus de sens de le faire autre part, fais comme tu veux. Juste on a plus énormément de temps et je commence un peu à stresser x)

	Bon allez, bon courage, moi je vais me coucher pour éviter de venir trop tard demain !
*/




#include "Enemy.class.hpp"
#include "EnemyA.class.hpp"
#include "EnemyB.class.hpp"
#include "EnemyEvents.hpp"
#include "GameEntity.class.hpp"
#include "Hero.class.hpp"
#include "Bullet.class.hpp"
#include "IPrintable.class.hpp"
#include "RenderMachine.class.hpp"
#include "display.hpp"
#include "direction.enum.hpp"
#include "AMovable.class.hpp"
#include "MotorMachine.class.hpp"
#include "IMachine.class.hpp" /*	J'avais du ajouter cette interface en faisant des tests, c'est juste un truc ou j'ai mis une fonction au hasard, on pourrait faire ça plus proprement, mais est-ce vraiment nécéssaire.. X)
																	Du coup finalement j'ai décidé de la laisser parce que je pense que ça risque de nous être utile de pouvoir foutre nos RenderMachine et nos MotorMachine dans un même tableau via du polymorphisme */
#include "Timer.class.hpp"
#include <curses.h>
#include <unistd.h>
#include <fstream>
#include <ctime>

int main() {

	RenderMachine rmachine;
	MotorMachine	mmachine;
	Hero hero;
	EnemyA enemy;
	EnemyB enemy2;
	Timer t1, t2; /*Timer est une classe qui permet de créer un chronometre. On le démarre avec start() et on peu ensuite récupérer le temps écoulé depuis son démarrage avec Timer::getDiffAsMillis(). Y a aussi la methode restart() qui fait
									exactement la même chose que la méthode start(), mais je trouvais start plus claire. Ici, on crée un timer par intervalle de temps qu'on souhaite tester. */
	int ch ;

	rmachine.addPrintable(&hero);
	mmachine.addMovable(&hero);

	rmachine.addPrintable(&enemy);
	mmachine.addMovable(&enemy);
	enemy.setDirectionX(1);

	std::fstream file("a", std::fstream::out | std::fstream::trunc); //Simple fichier permettant de faire des debugs simples sans avoir à passer par la console. Faudra virer ça au rendu :).
	file << "hei" << std::endl;

	init_ncurse();
	t1.start();
	t2.start();
	while (1) {
		/*
			Il suffit de créer des timers comme suit pour les evenements arrivant toutes les quelques secondes. ici par exemple, tous les ennemis vont bouger 5 fois par secondes, et un nouvel ennemi popera toutes les trois secondes.
			ceci sans interrompre les actions du joueur.
		*/
		if(t1.getDiffAsMillis() >= 3000) {
			t1.restart();
			Enemy *x = new EnemyA;
			rmachine.addPrintable(x);
			mmachine.addMovable(x);
			x->setDirectionX(0.2);
		}
		if(t2.getDiffAsMillis() >= 1000 / 5) {
			t2.restart();
			mmachine.moveAllExcept(&hero);
		}
		clear();
		// mmachine.moveAll();
		hero.move();
		rmachine.renderAll();
		refresh();
		timeout(0); //Permet de rendre l'appel à getch() non bloquant.
		ch = getch();
		switch (ch) {
			case 27: //Echap
				close_ncurse();
				return (0);
				break;
			case KEY_UP:
				hero.setDirectionX(0);
				hero.setDirectionY(-0.5);
				break;
			case KEY_DOWN:
				hero.setDirectionX(0);
				hero.setDirectionY(0.5);
				break;
			case KEY_LEFT:
				hero.setDirectionY(0);
				hero.setDirectionX(-0.5);
				break;
			case KEY_RIGHT:
				hero.setDirectionY(0);
				hero.setDirectionX(0.5);
				break;
			case ' ':
				hero.attack(); // <---- Ce serait une bonne chose de renommer "attack()" en "shoot()" pour plus de clarté, je trouve. Mais flemme.
				break;
			default:
				hero.setDirectionY(0);
				hero.setDirectionX(0);
				break;
		}
		hero.colide(rmachine.getAmount(),(GameEntity**)rmachine.getPrintableAll());
	}
}
