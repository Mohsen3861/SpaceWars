#ifndef _INIT_ 
#define _INIT_ 


extern void initVBO(void);
/*
* Fonction pour initialiser la VBO
* arguments : rien
* la valeur retournée: rien 
*/

extern void initBullet1(void);
/*
* Fonction pour initialiser les balles
* arguments : rien
* la valeur retournée: rien 
*/

extern void initBullet2(int i);
/*
* Fonction pour reinitialiser les balles si elles ne sont pas à la bonne position
* arguments : numero de balle
* la valeur retournée: rien 
*/

extern void Initobs(void);
/*
* Fonction pour initialiser les astèroïdes
* arguments : rien
* la valeur retournée: rien 
*/

extern void initAlien(void);
/*
* Fonction pour initialiser les enemies
* arguments : rien
* la valeur retournée: rien 
*/

extern void verifierPositionAlien(void);
/*
* Fonction pour verifier les position générée . parce que parfois ça peut arriver que les positions sera dans les astèroïdes. donc pour éviter cela on verifie les positions.
* arguments : rien
* la valeur retournée: rien 
*/

extern void reinitAlien(int i);
/*
* Fonction pour reinitialiser les positions  des enemies .
* arguments : rien
* la valeur retournée: rien 
*/

extern void InitText(void);
/*
* Fonction pour initialiser les tectures
* arguments : rien
* la valeur retournée: rien 
*/




#endif
