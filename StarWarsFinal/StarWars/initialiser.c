

#include "mainHeader.h"

#include "variables.h"

#include "initialiser.h"


char astrtext[100];
int astrmin;
int astrmax;

void 
InitText(void){
  Image *image1;
  
  image1 = (Image *) malloc(sizeof(Image));
  if (image1 == NULL) {
    fprintf(stderr, "Probleme d'allocation d'espace memoire\n");
  }

      

  glEnable(GL_TEXTURE_2D);
  glGenTextures(2, texture);
// on génére 2 ids et on les enregistre dans un tableau

  if (!ImageLoad(astrtext, image1)) {
    fprintf(stderr, "Impossible d'ouvrir ce fichier\n");
  }        

  glBindTexture(GL_TEXTURE_2D, texture[0]); 
	// on binde la texture

  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	// Paramètrage de la texture 
  glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
// chargement de l'image

  if (!ImageLoad(lev[gameLevel].textures, image1)) {
    fprintf(stderr, "Impossible d'ouvrir ce fichier\n");
  }        
  glBindTexture(GL_TEXTURE_2D, texture[1]); 
	// on binde la texture
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// Paramètrage de la texture 
  glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
	// chargement de l'image

 // quadrique
  quadAtmosphere=gluNewQuadric();
// on alloue une space memoire pour stocker les paramètres
  gluQuadricNormals(quadAtmosphere, GLU_SMOOTH);
// on active les normales
  gluQuadricTexture(quadAtmosphere, GL_TRUE);
// on active les textures
  

  free(image1->data);
  free(image1);
  

}



void initVBO(){

glGenBuffers( 1,&numero );
// on génére un id
 glBindBuffer(GL_ARRAY_BUFFER, numero);
// on binde l'id
 glBufferData(GL_ARRAY_BUFFER,sizeof (face),face , GL_STATIC_DRAW); 
// on sauvegarde les informations
glBindBuffer(GL_ARRAY_BUFFER, 0);  
// et on reinitialise

}


void initBullet1(){
int i;

	for(i=0;i<100;i++){
	bul[i].valid=0;
	bul[i].move=10;
	bul[i].angleUpDown=0;
	bul[i].angleLR=0;
	}
}


void initBullet2(int i){
bul[i].startX=posx;
bul[i].startY=posy;
bul[i].startZ=posz;
bul[i].angleUpDown=-angleUpandDown;
bul[i].angleLR=-angleRightandLeft;
bul[i].valid=1;

}

void Initobs(){

 srand(time(NULL));

  int i;
  for (i=0;i<maxobs;i++){

obs[i].x=RandomValeur(-worldsize,worldsize );
obs[i].y=RandomValeur(-worldsize,worldsize);
obs[i].z=RandomValeur(-worldsize,worldsize-3000 );
obs[i].a=RandomValeur(5,16);
obs[i].b=RandomValeur(5,16);
obs[i].size=RandomValeur(astrmax,astrmin);

  }


}



	void reinitAlien(int i){
		enemie[i].x=RandomValeur(posx-600,posx+600);
		enemie[i].y=RandomValeur(posy-300,posy+300);
		enemie[i].z=RandomValeur(posz-3000,posz-2000);
		enemie[i].ok=1;
		enemie[i].animation=0;
	verifierPositionAlien();

}


void verifierPositionAlien(){
int i,j;
GLfloat disx,disy,disz;

	for(i=0;i<maxenem;i++){
		for(j=0;j<maxobs;j++){

				// on calcule la distance
				disx=abs(enemie[i].x-obs[j].x);
				disy=abs(enemie[i].y-obs[j].y);
				disz=abs(enemie[i].z-obs[j].z);
				// si la distance est moins que la taille de l'astèroïde on reinitialise la position
				if(sqrt(disx*disx + disy*disy +disz*disz )<=obs[j].size+obs[j].size*0.5){
					printf(" bad pos \n ");	
					reinitAlien(i);
					

				}
			}

		}

	


}


void initAlien(){

int i;

	for(i=0;i<maxenem;i++){

		enemie[i].x=RandomValeur(posx-600,posx+600);
		enemie[i].y=RandomValeur(posy-300,posy+300);
		enemie[i].z=RandomValeur(posz-3000,posz-2000);
		enemie[i].ok=1;
		
	}
verifierPositionAlien();

}


					





		

