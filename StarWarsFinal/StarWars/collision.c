
#include "mainHeader.h"
#include "collision.h"

//initialisation 
 int CollisionMessage=0;
 int distroyEnemyMessage=0;
 int CollisionEnemieMessage=0;
 int NiveauMessage=0;


/*
void asteroidBullet(){

int i,j;
float disx;
float disy;
float disz;
	for(i=0;i<maxobs;i++){
		if( abs((obs[i].z)- posz) <DIS/2 &&
     	 abs((obs[i].y)- posy)<DIS/2 && abs((obs[i].x)- posx)<DIS/2
    	  )
			for(j=0;j<100;j++){

				if(bul[j].valid==1){
			
					disx=obs[i].x- xbullet;
					disy= obs[i].y-ybullet;
					disz=obs[i].z-zbullet;
	
					if(sqrt(disx*disx+disy*disy+disz*disz)<obs[i].size){
				
						bul[j].valid=0;
			
				
			}

		}
		}

	}
}

*/


void collisionSpaceShipe(){

int i;
float disx,disy,disz;
// pour calculer la distance
	for(i=0;i<maxobs;i++){
		if( abs((obs[i].z)- posz) <obs[i].size &&
     	 abs((obs[i].y)- posy)<obs[i].size && abs((obs[i].x)- posx)<obs[i].size
      	){
		//on verifie seulment les plus proches astéroïdes
			disx=abs(obs[i].x-posx);
			disy=abs(obs[i].y-posy);
			disz=abs(obs[i].z-posz);
			//on calcule la distance
			if(sqrt(disx*disx+disy*disy+disz*disz)<obs[i].size){
			// si la distance est plus petit que la taille de l'astéroïde , il y aura une collision
				CollisionMessage=1;
				//on affiche le message 
				vit=0;
				// et on la vaiseau ne bouge plus
			}else
				CollisionMessage=0;
		}
	}
}





void collisionAlien(){

int i;
int disx,disy,disz;

	for(i=0;i<maxenem;i++){
		if(enemie[i].ok==1){
			disx=abs(enemie[i].x- posx);
			disy= abs(enemie[i].y-posy);
			disz=abs(enemie[i].z-posz);
			// on calcule la distance
				if(sqrt(disx*disx+disy*disy+disz*disz)<=50.0){
			// si la distance est plus petit que 50 on affiche le message 
			// et la vaiseau ne bouge plus
					CollisionEnemieMessage=1;
					vit=0;

				}else
					CollisionEnemieMessage=0;
		}

	}
}



void detruireAlien2(){

int i,j;
float disx;
float disz;

	for(i=0;i<maxenem;i++){
		for(j=0;j<100;j++){
		
			if(enemie[i].ok==1 && bul[j].valid==1){
				disx=enemie[i].x- xbullet;
				disz=enemie[i].z-zbullet;

				if((enemie[i].y>=ybullet && enemie[i].y<=posy) || (enemie[i].y<=ybullet && enemie[i].y>=posy) )
				// si l'enemie est entre la Y actuelle de la vaiseau et Y maximume de la balle d'arme
				if(sqrt(disx*disx+disz*disz)<50.0){
				enemie[i].animation=1;
				enemie[i].ok=0;	
				
				// si la distance de Y et Z est moin 50
					lev[gameLevel].enemie--;
				// on décrémente le nobmre d'enemies
					bul[j].valid=0;
				// on affiche 

					distroyEnemyMessage=1;
				// on affiche le message
					compt=sec-2;
				// on sauvgarde la seconde actuelle moin 2 
				// pour qu'on puisse l'afficher pendant 2 secondes

			        if(lev[gameLevel].enemie==0 && gameLevel<7){
					// si tous les enemies sont detruit 
					// et le niveau de jeu est moin de 7 ( car il existe 6 missions )
						NiveauMessage=1;
						// on affiche le message
						pause=1;
						// on attends que le joueur confirme de commencer le niveau suivant
						glClearColor(0.0,0.0,0.0,0.0);
				 		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
						// à ce memont là on met la fenêtre en noir
				
					}
				
	
					// si il reste encore des enemies à detruire 
					// on crée un nouvel enemie
						
					
				}
					//printf(" %d \n",enemie[i].animation);
					
			}
	
		}
		
	}

}
