#ifndef _MAIN_ 
#define _MAIN_

#define  GL_GLEXT_PROTOTYPES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "bmp.h"
#include "glm.h"
#include <stdarg.h>

#if defined(__APPLE__) || defined(MACOSX)
# include <GLUT/glut.h> 
#else
# include <GL/glut.h>
#endif


#define ESC 27 
#define DIS 4000
#define maxobs 200000
#define maxenem 1
#define maxz 100000
#define maxx 10000
#define maxy 1000
#define worldsize 50000
#define pi 3.1415
#define INFOOBJ if(0) printf
#define INFOTRE2 if(0) printf
#define DATA if(0) 
extern GLfloat vit;
extern GLfloat red;
extern GLfloat vert;
extern GLfloat blue;
extern GLUquadricObj *quadAtmosphere;
extern GLfloat posx,posy,posz;
extern GLfloat xbullet,ybullet,zbullet;
extern GLchar vitChar[5];
extern GLuint texture[4];
// la tableau  qui reçoit les ids générée par "glGenTextures"
extern GLuint  numero;
// la variable qui reçoit l'id générée par "glGenBuffers"
extern GLMmodel* pmodel ;




extern GLfloat RandomValeur(GLfloat a, GLfloat b);
/*
* Fonction qui génère une valeur aléatoire
* arguments : float a =  minimum  , float b = maximum
* la valeur retournée: GLfloat 
*/

extern void attention(int i);
/*
* Fonction pour changer la couleur de carrée qui est autour de l'enemie
* arguments : le numero d'enemie
* la valeur retournée: rien
*/

extern void tecturesChar(void);
/*
Fonction pour verifier les nomes des textures
* arguments : rien
* la valeur retournée: rien
*/

void InitGL(void);
/*
Fonction pour initialiser OpenGL
* arguments : rien
* la valeur retournée: rien
*/

extern void displayText( float x, float y, float r, float g, float b,  char *string );
/*
Fonction pour afficher un texte sur l’écran 
* arguments : la position (x,y,z) , la couleur (r,g,b), texte(string)
* la valeur retournée: rien
*/

extern void lireParam(void);
/*
Fonction pour lire les paramétrés depuis le fichier "parametres.txt"
* arguments : rien
* la valeur retournée: rien
*/

extern void lireData(void);
/*
Fonction pour lire les information des niveaux depuis le fichier "niveau.niv"
* arguments : rien
* la valeur retournée: rien
*/

extern void niveauTermine(void);
/*
Fonction pour initialiser le niveau suivant
* arguments : rien
* la valeur retournée: rien
*/

extern void enemieShow(void);
/*
Fonction pour afficher les ennemies qui restent
* arguments : rien
* la valeur retournée: rien
*/

extern int ReturnStable(void);

/*
Fonction pour afficher les ennemies qui restent
* arguments : rien
* la valeur retournée: retourn un entier
*/

extern void showVitesse(void);
/*
Fonction pour afficher la vitesse
* arguments : rien
* la valeur retournée: rien
*/

extern void showNiveau(void);
/*
Fonction pour afficher le niveau
* arguments : rien
* la valeur retournée: rien
*/

extern void timeShow(void);
/*
Fonction pour afficher le temps
* arguments : rien
* la valeur retournée: rien
*/

extern void perdu(void);

/*
Fonction pour vérifier la distance entre l’ennemie et la vaisseau
* arguments : rien
* la valeur retournée: rien
*/

extern void showMessage(void);
/*
Fonction pour afficher les messages
* arguments : rien
* la valeur retournée: rien
*/


extern void textCorrection(char * text);
/*
Fonction pour supprimer les 2 dernier caractères d'un chêne de caractères
* arguments : le text ( char )
* la valeur retournée: rien
*/



struct obstacle {

  GLfloat x;
  GLfloat y;
  GLfloat z;
  GLfloat size;
  GLfloat a;
  GLfloat b;
};


struct alien {

  GLfloat x;
  GLfloat y;
  GLfloat z;
  GLfloat size;
  GLint ok;
  GLubyte animation;
};

struct missile{

  GLfloat startX;
  GLfloat startY;
  GLfloat startZ;
  GLfloat angleUpDown;
  GLfloat angleLR;
  GLubyte valid;
  GLint move;

};


struct niveux{
GLint niveux;
GLchar  textures[100];
GLint time;
GLint enemie;
GLubyte win;
};



typedef struct niveux niveux;

typedef struct obstacle obstacle;

typedef struct alien alien;

typedef struct missile missile;

missile bul[100];

niveux lev[7];

obstacle obs[maxobs];

alien enemie[maxenem];



#endif
