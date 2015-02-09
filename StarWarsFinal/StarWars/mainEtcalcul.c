
#include "mainHeader.h"
#include "collision.h"
#include "variables.h"
#include "display.h"
#include "initialiser.h"
#include "dessine.h"

enum key_state {NOTPUSHED, PUSHED} keyarr[127];


GLint t1 = 0, t2 = 0, fps = 0; 
GLfloat vit=1;
GLfloat distanceEneme;
GLfloat xbullet,ybullet,zbullet;
GLfloat tcx,tcy,tcz;
GLfloat vitmax;
GLfloat posx=0.0,posy=0.0,posz=48000;
GLfloat light_diffuse[]={1.0,1.0,1.0,0.0};
GLfloat light_position[]={-10000.0,-20.0, 0.0,0.0};
GLint gameLevel;
GLint niveauSuivant;	
GLint sec=0;
GLint compt=0;
GLint record=0;
GLint pause=0; 
GLint min;
GLint testRightandLeft=0;
GLint niveau;
GLchar minChar[2];
GLchar secChar[3];
GLchar vaiseau[100];
GLUquadricObj *quadAtmosphere;



void InitGL(){
	// activer les textures 
	glEnable(GL_TEXTURE_2D);
	//les parametres de la lumiere
 	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	// activer la lumiere
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	// initialiser les textures
  InitText();
  glClearColor (0.0, 0.0, 0.0, 0.0); 
	// avtiver le tampon de profondeur					       
  glEnable (GL_DEPTH_TEST);

} 



	      
void tecturesChar(){

	int i,j;

	i=0;
		for(j=0;j<7;j++){
			while(lev[j].textures[i]!='\0'){
				if(lev[j].textures[i]=='\n'){
				lev[j].textures[i]='\0';
				lev[j].textures[i-1]='\0';
				}
				i++;
			}
			i=0;
   }
}



void textCorrection(char * text){

	int i=0;
	while( text[i]!='\0'){
		if(text[i]=='\n'){
			text[i]='\0';
			text[i-1]='\0';
		}
		i++;
	}

}


void lireParam(){

 FILE* fichier = NULL;
	// ouvrir le fichier
 fichier = fopen("parametres.txt", "r");
 if (fichier != NULL)
 {
		// decaler 8 caracteres 
		fseek(fichier,8 , SEEK_CUR);
		// on recupere les donnée
    if( fgets(vaiseau,36,fichier)!=NULL);
			textCorrection(vaiseau);
		
    fseek(fichier,12 , SEEK_CUR);
    if( fscanf(fichier, "%f", &vitmax)!=0);

    fseek(fichier,24 , SEEK_CUR);
    if( fscanf(fichier, "%d", &astrmin)!=0);

    fseek(fichier,24 , SEEK_CUR);
    if(fscanf(fichier, "%d", &astrmax)!=0);

    fseek(fichier,21 , SEEK_CUR);
    if( fgets(astrtext,36,fichier)!=NULL);

	  textCorrection(astrtext);
    fseek(fichier,15 , SEEK_CUR);
    if( fscanf(fichier, "%d", &niveau)!=0);

    gameLevel=niveau;

		vit=1;
		// affichage les informations 
		DATA{
 			printf("vaiseau %s\n",vaiseau );
 			printf("vitmax %f\n",vitmax );
			printf("astrmin %d\n",astrmin );
			printf("astrmax %d\n", astrmax);
			printf("astrtext %s\n",astrtext );
			printf("niveau %d\n",niveau );
		};
		// fermeture 
		fclose(fichier);
	}    

}



void lireData(){

	FILE* fichier = NULL;
  int i;
	// ouverture 
	fichier = fopen("niveux.niv", "r");
    if (fichier != NULL)
    {
       for(i=0;i<7;i++){
					// decalage de 8 caracteres
      	 fseek(fichier,8 , SEEK_CUR);
					// recuperation des données
      	 lev[i].niveux=fgetc(fichier);


       	 fseek(fichier,11 , SEEK_CUR);
     		 if( fgets(lev[i].textures,100,fichier)!=NULL);

       	 fseek(fichier,5 , SEEK_CUR);
         if(fscanf(fichier, "%d", &lev[i].time)!=0);

				 fseek(fichier,9 , SEEK_CUR);
				 if(fscanf(fichier, "%d", &lev[i].enemie)!=0);

				 fseek(fichier,+2 , SEEK_CUR);


				 lev[i].win=0;
					// affichage 
         DATA{
           printf("level %c\n", lev[i].niveux);
           printf("texture %s", lev[i].textures);
           printf("time %d\n", lev[i].time);
           printf("enmies %d\n\n\n", lev[i].enemie);
         };
       }
				// fermeture
       fclose(fichier);

    }else{
			printf("imposible d'ouvrir ce fichier ! \n");
		}

	tecturesChar();
   

}
    
 




void niveauTermine(){

	if(niveauSuivant==1){
		// reititialiser les balles 
		initBullet1();
		// aller au niveau suivant 
		gameLevel++;
		
		if(gameLevel>6){
			printf(" vous avez reussi tous les niveux \n");
			exit(0);				
		}
		// initialiser le temps 
		min=lev[gameLevel].time;
		sec=0;
		// initialiser la position
    posz=49000.0;
		vit=1;
		// reinitailiser les tectures 
  	InitText();
		niveauSuivant=0;
		// reinitialiser les enemies
	  initAlien();
		NiveauMessage=0;
		pause=0;

	}
	
}


void enemieShow(){

	char enemieChar[5];
	
	// convertir en char
	snprintf(enemieChar,sizeof(enemieChar),"%d",lev[gameLevel].enemie);
	// affichage
  displayText( 40.0,550.0, 1.0, 1.0, 0.0 ,"enemies : ");
  displayText( 110.0,550.0, 1.0, 1.0, 1.0 ,enemieChar);

}

char vitChar[5];
void showVitesse(){
	
	// convertir en char
	snprintf(vitChar,sizeof(vitChar),"%f",vit*50);
 	displayText( 750.0,50.0, 1.0, 1.0, 1.0 ,vitChar);
	displayText( 690.0,50.0, 1.0, 0.0, 1.0 ,"vitesse : ");

}



void showNiveau(){
	char nivChar[5];
	// convertir en char
	snprintf(nivChar,sizeof(nivChar),"%d",gameLevel+1);
 	displayText( 750.0,550.0, 1.0, 1.0, 1.0 ,nivChar);
	displayText( 690.0,550.0, 0.0, 0.5, 1.0 ,"niveau : ");

}


GLfloat RandomValeur(GLfloat a, GLfloat b){

// source:  http://fr.openclassrooms.com/informatique/cours/l-aleatoire-en-c-et-c-se-servir-de-rand-1/restez-entre-les-bornes-1

return (rand()/(GLfloat)RAND_MAX) * (b-a) +a;

}



static void
FPS(void){
  t1 = glutGet(GLUT_ELAPSED_TIME);
  if(t1 - t2 > 1000) {
	printf("%g\n", (1000.0 * fps)/(t1-t2));
	t2 = t1;
	fps = 0;
  }
  fps++;
}



static void
timejeu(void){

  t1 = glutGet(GLUT_ELAPSED_TIME);

  if(t1 - t2 > 1000) {
		if(sec ==0 && min ==0){
			printf(" time is over !! \n" );
			exit(0);
		}
		if(sec==0 && min!=0){
		sec=60;
		min--;
		}

		sec--;

  }

}




void perdu(){

	int i;

	for(i=0;i<maxenem;i++){
		if(enemie[i].ok==1){
			if(enemie[i].z>posz){
				
				exit(0);
			}
		}
	}
}




void attention(int i){

	int disx,disy,disz;

	disx=abs(enemie[i].x- posx);
	disy= abs(enemie[i].y-posy);
	disz=abs(enemie[i].z-posz);

	if(sqrt(disx*disx+disy*disy+disz*disz)<=800.0){
		red=1.0;
		vert=0.0;
		blue=0.0;
	}
	else{
		red=0.0;
		vert=1.0;
		blue=0.0;
	}

}




void 
Reshape(int width, int height){

  glViewport(0,0,(GLsizei)(width),(GLsizei)(height));
  glLoadIdentity();					
  glMatrixMode(GL_PROJECTION);
  gluPerspective(100.0f, (GLfloat)width/height, 0.01f, 1000000.0f);			
  glMatrixMode(GL_MODELVIEW);
			       			
}




static  GLfloat ongle=0;

int  ReturnStable(){

	if(angleUpandDown==0 && angleRightandLeft ==0) return 0;
	if(angleRightandLeft>0)angleRightandLeft--;
	if(angleRightandLeft<0) angleRightandLeft++;
	if(angleUpandDown>0)angleUpandDown--;
	if(angleUpandDown<0) angleUpandDown++;

return 0;
}




GLfloat bord=0.0;
GLint t=-2;
GLfloat tirex,tirey,tirez;
GLint testobs=0;
GLint distance=800;

void displayText( float x, float y, float r, float g, float b,  char *string ) {
// source : https://www.youtube.com/watch?v=elE__Nouv54

	int j = strlen( string );
 	int i;
	GLdouble matrix[16];
	glMatrixMode(GL_PROJECTION);
	
	glGetDoublev(GL_PROJECTION_MATRIX,matrix);
	glLoadIdentity();
	glOrtho(0,800,0,600,-5,5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	
	glColor3f( r, g, b );
	glRasterPos2f( x, y );
	for( i = 0; i < j; i++ ) {
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, (int)string[i] );
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);

}






void timeShow(){

	GLfloat r,g,b;
	r=1.0;g=1.0;b=1.0;

	if(min==0 && sec<20){
		g=0.0;
		b=0.0;
	}

	// convertion en char
	snprintf(secChar,sizeof(secChar),"%d",sec);
 	displayText( 50.0, 50.0, r, g, b,secChar);
 	displayText( 41.0, 51.0, r, g, b," : ");
	
	// convertion en char
	snprintf(minChar,sizeof(minChar),"%d",min);
	displayText( 37.0, 50.0, r, g, b,minChar);


}


void showMessage(){

	if(CollisionMessage==1)
		displayText( 300, 500, 1.0, 0.0, 0.0,  "collision avec l'asteroide !" );

	if(CollisionEnemieMessage==1)
 		displayText( 300, 500, 1.0, 0.0, 0.0,  "collision avec l'enemie !" );

	if(distroyEnemyMessage==1)
 		displayText( 350, 500, 0.0, 1.0, 0.0,  "Cible détruite!" );

	if(NiveauMessage==1){

		if(gameLevel==6)
		displayText( 150,400, 0.0, 0.7, 1.0,  " bravo !! vous avez reussi tous les 	niveaux ! (appuyez sur Entrée pour sortir)" );

		else
		displayText( 200,400, 0.0, 0.7, 1.0,  " niveau termine ! appuyez sur Entrée 	pour commencer le niveau suivant ..." );

	}

	if(sec==compt) distroyEnemyMessage=0;
 			
}





GLint cockpittest=0;
GLint test=0;
GLfloat possp[16];

void Display(){

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	if(keyarr['z']){
		testUpandDown=1;
		if(angleUpandDown>-30) angleUpandDown-=0.1;
	}

	if(keyarr['s']){
		testUpandDown=1;
		if(angleUpandDown<30) angleUpandDown+=0.1;
	}

	if(keyarr['q']){
		testRightandLeft=1;
		if(angleRightandLeft>-60) angleRightandLeft-=0.2;
	}

	if(keyarr['d']){
		testRightandLeft=1;
		if(angleRightandLeft<60) angleRightandLeft+=0.2;
	}



	if(cockpittest==0){
 	 gluLookAt(posx,posy+(angleUpandDown/30)+1.0,posz+2.0, posx, posy, 						posz-30,angleRightandLeft/60 , 1.0,0.0);
	}


	if(cockpittest==1){
		glRotatef(angleUpandDown,1.0,0.0,0.0);
		gluLookAt(posx,posy,posz-2, posx, posy, posz-30,angleRightandLeft/60 , 1.0,0.0);
	}

	glPushMatrix();

	// activer la lumiere
 	glEnable(GL_LIGHTING);

	glPopMatrix();
	// dessiner les asteroides
	if(testobs==0) dessineObs();
	// afficher les enemies 
	displayAlien();
	//detection des collisiones  entre la vaisseau et les astéroïdes
	collisionSpaceShipe();
	// afficher la vaiseau
	spaceship();
	INFOOBJ ("  X = %f  Y = %f  Z = %f  \n",posx, posy, posz);
	// desactiver la lumiere
	glDisable(GL_LIGHTING); 
	// afficher le monde
	displayWorld();
	// dessiner le viseur
	dessineTarget();
	// afficher les balles
	displayBullet();
	// afficher le temps
	timeShow();

	showNiveau();
	
	if(cockpittest==1) {
		// afficher le radar
		radar();
		// affichage de la deuxieme vue
		cokbit();
	}
	else
	// afficher la vitesse 
	showVitesse();
	// afficher les messages
	showMessage();
	// afficher le nombre des enemie qui reste
	enemieShow();
	// initialiser le niveau suivant 
	niveauTermine();
	// calculer le temps
	timejeu();
	// calculer FPS
	FPS();
	
 	glutSwapBuffers();

}



GLint nbrBullet=0;
void Keyboard(unsigned char key, int x, int y){

  switch(key){

		case 'p':
 			if(pause==0) pause=1;
			else
    	pause=0;
			break;

		case 'k':
			if(cockpittest==0) cockpittest=1;
			else
			cockpittest=0;
			break;

  	case ESC : 
    	exit(0); 
			break;

		case 'z': 
			keyarr['z'] = PUSHED;
			break;

		case 's': 
			keyarr['s'] = PUSHED;
			break;

		case 'q': 
			keyarr['q'] = PUSHED;
			break;

		case 'd':
			keyarr['d'] = PUSHED;
			break;

  	case '8':
			if(vit>0 && vit<(vitmax/50))
			vit+=0.1;
			posz-=vit;
			break;

  	case '2':
			if(vit>1 && vit<=(vitmax/50)+1)
			vit-=0.1;
			posz+=vit;
			break;

  	case '6':
			ongle++;
			break;

 		case '5':
			ReturnStable();
			break;

 		case '4':
			ongle--;
			break;

		case 13:
			if(NiveauMessage==1){
				niveauSuivant=1;
				pause=0;
			}
			break;

		case 32:
			initBullet2(nbrBullet);
			nbrBullet++;
			if(nbrBullet>100) nbrBullet=0;
			break;


		default : 
			printf("unused key \n");
    	break;

  }

	if(!pause) glutPostRedisplay();

}


void idle(){

	if(!pause){
		if(angleUpandDown<0)
			posy+=angleUpandDown*angleUpandDown*vit/500;
		

		if(angleUpandDown>0)
			posy-=angleUpandDown*angleUpandDown*vit/500;
		

		if(angleRightandLeft>0)
			posx+=angleRightandLeft*angleRightandLeft*vit/500;

		if(angleRightandLeft<0)
			posx-=angleRightandLeft*angleRightandLeft*vit/500;

  	posz-=vit;

  	glutPostRedisplay();

	}

}


void keyUp (unsigned char key, int x, int y) {  

	if (key == 'z') {
		keyarr['z'] = NOTPUSHED;
	} 

	if (key == 's') {
		keyarr['s'] = NOTPUSHED;
	}

	if (key == 'q') {
		keyarr['q'] = NOTPUSHED;
	}

	if (key == 'd') {
		keyarr['d'] = NOTPUSHED;
	}


} 



int 
main(int argc, char **argv){

	// lire les informations
  lireData();
	// lire les parametres
  lireParam();
	// initialiser le temps
	min=lev[gameLevel].time;

  glutInit(&argc, argv); 
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH ); 
  glutInitWindowSize (1000, 800); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow (argv[0]);  
	// initialiser les balles
	initBullet1();
  InitGL();
	// initialiser la VBO
  initVBO();
	// initialiser les asteroides
  Initobs();
	// initialiser les enemies
  initAlien();

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(Keyboard);
  glutKeyboardUpFunc(keyUp);
  glutIdleFunc(idle);
  glutMainLoop(); 


  return 0; 
}
