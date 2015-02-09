
#include "mainHeader.h"
#include "display.h"
#include "collision.h"
#include "dessine.h"
float angleRightandLeft=0;
// la variable qui reçoit l'angle horizontal de la vaisseau
float angleUpandDown=0;
// la variable qui reçoit l'angle vertical de la vaisseau
int testUpandDown=0;
// la variable pour activer ou desactiver le tournage vertical de la vaisseau
GLuint texture[4]; 
// la tableau  qui reçoit les ids générée par "glGenTextures"
GLuint  numero;
// la variable qui reçoit l'id générée par "glGenBuffers"


void displayVBO(){



  glBindBuffer(GL_ARRAY_BUFFER,numero);
//on bind l'id 
  glEnableClientState(GL_VERTEX_ARRAY);
//on active les vertexes
  glEnableClientState(GL_COLOR_ARRAY);
// on active les couleurs
  glEnableClientState(GL_NORMAL_ARRAY);
// on active les normales
  glVertexPointer(3, GL_FLOAT, 9*sizeof(GLfloat),0);
// on donne les positions des sommets dans le tableau
  glColorPointer(3, GL_FLOAT, 9*sizeof(GLfloat), (void*)(3*sizeof(float)));
// on donne les positions des couleurs 
  glNormalPointer( GL_FLOAT, 9*sizeof(GLfloat), (void*)(6*sizeof(float)));
// et les normales
  glDrawArrays(GL_QUADS,0,40);
// on dessine 
	glDisableClientState(GL_NORMAL_ARRAY); 
// et à la fin on désactive les normales
  glDisableClientState(GL_COLOR_ARRAY); 
// , les couleurs
  glDisableClientState(GL_VERTEX_ARRAY);
// et les vertexes
  glBindBuffer(GL_ARRAY_BUFFER, 0);
// on met à zéro l'id 

}

float k=1.0;
void animationAlien(int i){

	glPushMatrix();

	glTranslatef(enemie[i].x,enemie[i].y,enemie[i].z);
	// on translate le matrice	
		if(enemie[i].animation==1 ){

			if(k<49.0){
			
				k+=1.0;
			// on compte jusqu'à 50.0			
			}

			else{

				k=1.0;
				enemie[i].ok=0;
				enemie[i].animation=0;
				record++;
				// on incrémente le nombre des enemies qui sont detruit
						
					}

			glScalef(50.0-k,50.0-k,50.0-k);
			// on diminue la taille 
			glEnable(GL_LIGHTING);
				
			drawmodel();
			// on affiche la vaiseau
			glDisable(GL_LIGHTING);
			attention(i);
			dessinCarre();

			if(record==maxenem && lev[gameLevel].enemie!=0  ){
			// si il reste encore des enemies à detruire 
					
				initAlien();
				// on crée un nouvel enemie
				record=0;
			}

		}

	glPopMatrix();


}


void displayAlien(){

int i;

	
for(i=0;i<maxenem;i++){
if(enemie[i].ok==0)
animationAlien(i);
		if(enemie[i].ok==1){

				glPushMatrix();

				glTranslatef(enemie[i].x,enemie[i].y,enemie[i].z);
				// on translate le matrice à la position générée d'enemie
				
				
				
				glScalef(50.0,50.0,50.0);
				// on augment la taille de matrice
				collisionAlien();
				// on verifie la collision entre la vaiseau et les vaiseaux d'enemies

				perdu();
				// on verifie si le joueur ne depasse pas de l'enemie
				// si il depasse il perde

				glEnable(GL_LIGHTING);
				
				drawmodel();
				// on affiche la vaiseau
				glDisable(GL_LIGHTING);

				attention(i);
				// on verifie si le joueur est très proche de l'enemie
				// si il est tres proche on change la couleur 

				dessinCarre();

				// on dessine une carrée autour de l'enemie pour que 
				// le joueur puisse bien distinguer l'enemie  
				glPopMatrix();
			}
	
		}
}	




void displayWorld(){

	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	// on bind l'id de texture
	gluSphere(quadAtmosphere,worldsize, 32, 32); 
	// on dessine la sphère
	glBindTexture(GL_TEXTURE_2D, 0);
	// on met l'id à zèro

}




	
float bulCoord[16];
int bx,by,bz;

void displayBullet(){
int i ; 

	for(i=0;i<100;i++){

		
		if(bul[i].valid==1){
		
			glClearColor(0.0,1.0,0.0,1.0);

			glPushMatrix();
				
			glTranslatef(bul[i].startX,bul[i].startY,bul[i].startZ);
			// on translate vers la position de la vaisseau
			glPushMatrix();
			glRotatef(bul[i].angleUpDown,1.0,0.0,0.0);
			glRotatef(bul[i].angleLR,0.0,0.0,1.0);
			//rotation des balles par rapport à la vaisseau
			glPushMatrix();
			
			//les mouvement des balles
			glTranslatef(-5.0,-2.0,-bul[i].move);
			bul[i].move+=5;
			
			if(bul[i].move>2000){
			// dés qu'il a deppassé à 2000 on l'affiche plus 
			// on on la réinitialise
			bul[i].move=0;
			bul[i].valid=0;
			}
			
			glGetFloatv(GL_MODELVIEW_MATRIX, bulCoord);
			// on recupère le matrice
   			xbullet=bul[i].startX+2.5;
   			ybullet=(tan(bul[i].angleUpDown*pi/180)*2000)+bul[i].startY;
				// on calcule la hauteur maximum que la balle peut parcourir
  			zbullet=bulCoord[14]+posz;
			//printf(" %f %f %f \n",xbullet,ybullet,zbullet);
		
			
			glScalef(0.3,0.3,0.3);
			// on diminue la taille des balles
			
			displayVBO();

			detruireAlien2();
			// on verifie la collision entre une balle et un enemie
			glPopMatrix();	
				
			glPushMatrix();
			// la deuxième balle 
			glTranslatef(5.0,-2.0,-bul[i].move);
			bul[i].move+=5;
			if(bul[i].move>2000){
			bul[i].move=0;
			bul[i].valid=0;
			}
			glScalef(0.3,0.3,0.3);
			displayVBO();	

			glPopMatrix();

			
			glPopMatrix();
			glPopMatrix();
			
				

		}

	}



}




void dessineObs(){
	int i;
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	// on bind l'id de texture
	for(i=0;i<maxobs;i++){
	// on va afficher seulement les astèroïdes qui sont proche de la vaiseau
	// et bien sûr pour cela on calcule la distance de chacun
		if( abs((obs[i].z)- posz) <DIS &&
      abs((obs[i].y)- posy)<DIS && abs((obs[i].x)- posx)<DIS
      ){


 				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				

				//l'affichage
				glTranslatef(obs[i].x,obs[i].y,obs[i].z);
				gluSphere(quadAtmosphere,obs[i].size, obs[i].a,obs[i].b);

				//glutWireSphere(500,16,16);

				glPopMatrix();
			}
		}
	glBindTexture(GL_TEXTURE_2D, 0);


}




GLfloat coordPos[16];

void spaceship(){
glClearColor(1.0,1.0,1.0,1.0);

glPushMatrix();

glTranslatef(posx,posy,posz);

glRotatef(-180.0,0.0,1.0,0.0);
glRotatef(angleRightandLeft,0.0,0.0,1.0);

glRotatef(angleUpandDown,1.0,0.0,0.0);

glEnable(GL_LIGHTING); 
//l'affichage de la vaiseau
drawmodel();
glDisable(GL_LIGHTING);

glPopMatrix();


}

