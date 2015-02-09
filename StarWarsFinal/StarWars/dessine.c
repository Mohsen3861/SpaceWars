

#include "mainHeader.h"
#include "dessine.h"
#include "variables.h"

GLMmodel* pmodel=NULL;

void
drawmodel(void)
{
// cette fonction est tiré d'un des programmes qui se trouve sur le site
    if (!pmodel) {

			pmodel = glmReadOBJ(vaiseau);

       if (!pmodel) exit(0);
       glmUnitize(pmodel);
       glmFacetNormals(pmodel);
       glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel,GLM_SMOOTH |GLM_MATERIAL  );
}


float red=0.0;
float vert=1.0;
float blue=0.0;

void dessinCarre(){
	
  glBegin(GL_LINES);

	glColor3f(red,vert,blue);
	glVertex3f(1.0,1.0,0.0);
	
	glColor3f(red,vert,blue);
	glVertex3f(-1.0,1.0,0.0);

	glColor3f(red,vert,blue);
	glVertex3f(-1.0,-1.0,0.0);

	glColor3f(red,vert,blue);
	glVertex3f(1.0,-1.0,0.0);

	glColor3f(red,vert,blue);
	glVertex3f(-1.0,-1.0,0.0);

	glColor3f(red,vert,blue);
	glVertex3f(-1.0,1.0,0.0);

	glColor3f(red,vert,blue);
	glVertex3f(1.0,-1.0,0.0);
	
	glColor3f(red,vert,blue);
	glVertex3f(1.0,1.0,0.0);

	
	glColor3f(red,vert,blue);
	glVertex3f(0.0,1.0,0.0);
	
	glColor3f(red,vert,blue);
	glVertex3f(0.0,0.7,0.0);

	glColor3f(red,vert,blue);
	glVertex3f(1.0,0.0,0.0);
	
	glColor3f(red,vert,blue);
	glVertex3f(0.7,0.0,0.0);

	glColor3f(red,vert,blue);
	glVertex3f(-1.0,0.0,0.0);
	
	glColor3f(red,vert,blue);
	glVertex3f(-0.7,0.0,0.0);

	glColor3f(red,vert,blue);
	glVertex3f(0.0,-1.0,0.0);
	
	glColor3f(red,vert,blue);
	glVertex3f(0.0,-0.7,0.0);

	glEnd();

}


int disTarget=50;
float positionTarget=0.0;


void dessineTarget(){
	positionTarget= (disTarget*(sin(-angleUpandDown*pi/180)))+((-	angleUpandDown*3)/30);
// on calcule la position du viseur quand l'angle de la vaisseau change
	glPushMatrix();

	glTranslatef(0.0,positionTarget,0.0);
	glBegin(GL_LINES);
// on dessine
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(posx-3.0,posy,posz-disTarget);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(posx-1.0,posy,posz-disTarget);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(posx+1.0,posy,posz-disTarget);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(posx+3.0,posy,posz-disTarget);


	glColor3f(1.0,1.0,1.0);
	glVertex3f(posx,posy+1.0,posz-disTarget);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(posx,posy+3.0,posz-disTarget);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(posx,posy-1.0,posz-disTarget);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(posx,posy-3.0,posz-disTarget);

	glEnd();
	glPopMatrix();

}



float xradar;
float yradar;
int yyy;

void radar(){
	xradar=-((posx-enemie[0].x) * 140)/1200;
	yradar=((posz-enemie[0].z) * 135)/1000;
// on calcule la position de l'enemie
	yyy=0;
// selon https://www.youtube.com/watch?v=elE__Nouv54
	GLdouble matrix[16];//...

	glMatrixMode(GL_PROJECTION);// ...
	glGetDoublev(GL_PROJECTION_MATRIX,matrix);// ...
	glLoadIdentity();// ...
	glOrtho(0,800,0,600,-5,5);// ...
	glMatrixMode(GL_MODELVIEW);// ...
	glLoadIdentity();// ...
	glPushMatrix();// ...
	glLoadIdentity();// ...
	glRasterPos2f( 300, 300 );//..

// anti aliasing lignes
// selon http://artgrammer.blogspot.fr/2011/05/drawing-nearly-perfect-2d-line-segments.html
	glEnable(GL_LINE_SMOOTH);//...
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);//...
  glEnable(GL_BLEND);//...
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//...
	
	 
// on commence à dessiner les lignes 

	glBegin(GL_LINES);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(330.0,170.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(470.0,170.0);
	
	glColor3f(0.0,0.6,0.0);
  glVertex2f(330.0,30.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(470.0,30.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(330.0,170.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(330.0,30.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(470.0,170.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(470.0,30.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(400.0,30.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(330.0,100.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(400.0,30.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(470.0,100.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(400.0,30.0);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(400.0,170.0);
	
	glEnd();
// on évite les debordements 
	if(xradar>70)xradar=65;
	if(xradar<-70)xradar=-70;
	if(yradar>140)yradar=135;
	if(yradar<0)yradar=0;

// on dessine une carrée rouge qui représente la position d'ennemie
	glBegin(GL_QUADS);

	glColor3f(1.0,0.0,0.0);
  glVertex2f(400.0+xradar,35.0+yradar);
	
	glColor3f(1.0,0.0,0.0);
  glVertex2f(405.0+xradar,35.0+yradar);

	glColor3f(1.0,0.0,0.0);
  glVertex2f(405.0+xradar,30.0+yradar);

	glColor3f(1.0,0.0,0.0);
  glVertex2f(400.0+xradar,30.0+yradar);
	
	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.0,1.0,0.0);
  glVertex2f(398.0,35.0);
	
	glColor3f(0.0,1.0,0.0);
  glVertex2f(402.0,35.0);

	glColor3f(0.0,1.0,0.0);
  glVertex2f(402.0,30.0);

	glColor3f(0.0,1.0,0.0);;
  glVertex2f(398.0,30.0);
	
	glEnd();
	
	

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_BLEND);

}


char vitChar[5];
void cokbit(){

	GLdouble matrix[16];
	float x=250;
	float y=200;
	char ongleChar[5];
	int i;
// selon https://www.youtube.com/watch?v=elE__Nouv54

	glMatrixMode(GL_PROJECTION);//...
	glGetDoublev(GL_PROJECTION_MATRIX,matrix);//...
	glLoadIdentity();//...
	glOrtho(0,800,0,600,-5,5);//...
	glMatrixMode(GL_MODELVIEW);//...
	glLoadIdentity();//...
	glPushMatrix();//...
	glLoadIdentity();//...
	glRasterPos2f( 300, 300 );//...

// anti aliasing lignes
// selon http://artgrammer.blogspot.fr/2011/05/drawing-nearly-perfect-2d-line-segments.html

	 	glEnable(GL_LINE_SMOOTH);//...
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);//...
    glEnable(GL_BLEND);//...
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//...


	
// on dessine
	glBegin(GL_LINES);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(0.0+x,0.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(300.0+x,0.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(0.0+x,200.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(300.0+x,200.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(0.0+x,200.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(0.0+x,0.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(300+x,200.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(300+x,0.0+y);

	glEnd();


	glBegin(GL_LINES);

	for(i=0;i<4;i++){
		glColor3f(0.0,0.6,0.0);
    glVertex2f(100.0+x,25.0+y+(i*50));

	  glColor3f(0.0,0.6,0.0);
    glVertex2f(200.0+x,25.0+y+(i*50));

	  glColor3f(0.0,0.6,0.0);
    glVertex2f(125.0+x,50.0+y+(i*50));

	  glColor3f(0.0,0.6,0.0);
    glVertex2f(175.0+x,50.0+y+(i*50));

	}
	glEnd();



	glBegin(GL_LINES);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(40.0+x,0.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(40.0+x,200.0+y);
	
	glColor3f(0.0,0.6,0.0);
  glVertex2f(260.0+x,0.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(260.0+x,200.0+y);
	
	glColor3f(0.0,0.6,0.0);
  glVertex2f(0.0+x,90.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(40.0+x,90.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(0.0+x,115.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(40.0+x,115.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(300.0+x,90.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(260.0+x,90.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(300.0+x,115.0+y);

	glColor3f(0.0,0.6,0.0);
  glVertex2f(260.0+x,115.0+y);

	glEnd();
	

	snprintf(ongleChar,sizeof(vitChar),"%f",-angleUpandDown);
	// on récupére l'angle de la vaiseau
	displayText( 260.0+x,100.0+y, 0.0, 0.6, 0.0 ,ongleChar);
	// on l'affiche
	snprintf(vitChar,sizeof(vitChar),"%f",vit*50);
	// on récupére la vitesse 
	displayText( 2.0+x,100.0+y, 0.0, 0.6, 0.0 ,vitChar);
	// on l'affiche
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_BLEND);

}





