
#ifndef _COLLISON_ 
#define _COLLISON_ 

extern int NiveauMessage;
extern int CollisionMessage;
extern int distroyEnemyMessage;
extern int CollisionEnemieMessage;
//si chacun de ces variables recoit 1 on affiche le message correspondant sinon on n'affiche rien 

extern int gameLevel;
//le niveau de jeu
extern float vit;
// la vitesse 
extern int sec;
// la seconde 
extern int compt;
// on utilise cette variable pour qu'on puisse affiche une message pendant certain seconde
extern int record;
// pour compter les enemies qui sont detruit
extern int pause;
// pour activer ou désactiver la pause pendant le jeu 




extern void initAlien(void);
/*
* Fonction pour initialiser les positions des enemies
* arguments : rien
* la valeur retournée: rien 
*/
extern void collisionSpaceShipe(void);
/*
* Fonction pour détecter la collision entre la vaisseau et les astéroïdes
* arguments : rien
* la valeur retournée: rien 
*/
extern void collisionAlien();
/*
* Fonction pour détecter la collision entre la vaisseau et les vaisseau d'enemie
* arguments : rien
* la valeur retournée: rien 
*/
extern void detruireAlien2();
/*
* Fonction pour détecter la collision entre les balles d'arme et les vaisseau d'enemie
* arguments : rien
* la valeur retournée: rien 
*/


#endif



