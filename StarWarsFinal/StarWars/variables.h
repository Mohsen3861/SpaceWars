
#ifndef _VARIABLES_
#define _VARIABLES_

extern GLchar vaiseau[100];
// le nom de fichier .OBJ de la vaisseau
extern GLint astrmax;
// la taille maximum des astéroïdes
extern GLint astrmin;
// la taille minimum des astéroïdes
extern GLint niveau;
// le niveau initial de jeu
extern GLchar astrtext[100];

extern GLint testRightandLeft;
// la variable pour activer ou desactiver le tournage horizontal de la vaisseau
extern GLfloat angleRightandLeft;
// la variable qui reçoit l'angle horizontal de la vaisseau
extern GLint testUpandDown;
// la variable pour activer ou desactiver le tournage vertical de la vaisseau
extern GLfloat angleUpandDown;
// la variable qui reçoit l'angle vertical de la vaisseau
extern GLint niveauSuivant;
// la variable pour activer ou désactiver le niveau suivant

extern GLint destroyTest;
extern GLint gameLevel;
// le niveau de jeu

// tableau de sommet pour la VBO
static GLfloat face[]={
                 -1.0, -1.0, 0.0, 
   		 1.0, 1.0, 1.0, //rouge 
		 0.0,0.0,-1.0,

   		  1.0, -1.0, 0.0, 
   		  1.0, 1.0, 1.0, //vert 
		 0.0,0.0,-1.0,

   		  1.0, 1.0, 0.0, 
   		1.0, 1.0, 1.0, //bleu 
		 0.0,0.0,-1.0,

   		  -1.0, 1.0, 0.0,
		   1.0, 1.0, 1.0, //jeun // fait
		 0.0,0.0,-1.0,


		   1.0,1.0,2.0,
		   1.0, 1.0, 1.0,
		 0.0,0.0,1.0,

		   1.0,-1.0,2.0,
		  1.0, 1.0, 1.0,
		 0.0,0.0,1.0,

		  -1.0,-1.0,2.0,
		 1.0, 1.0, 1.0,
		 0.0,0.0,1.0,

		  -1.0,1.0,2.0,
		1.0, 1.0, 1.0,//fait 444
		 0.0,0.0,1.0,

               
	  	   1.0,1.0,0.0,
		  1.0, 1.0, 1.0,
		 1.0,0.0,0.0,

		   1.0,1.0,2.0,
		  1.0, 1.0, 1.0,
		 1.0,0.0,0.0,

		   1.0,-1.0,2.0,
		   1.0, 1.0, 1.0,
		 1.0,0.0,0.0,

		  1.0,-1.0,0,
		1.0, 1.0, 1.0, //fait
		 1.0,0.0,0.0,

		 
	  	   1.0,1.0,0.0,
		  1.0, 1.0, 1.0,
		 0.0,1.0,0.0,

		   -1.0,1.0,0.0,
		   1.0, 1.0, 1.0,
		 0.0,1.0,0.0,

		  -1.0,1.0,2.0,
		  1.0, 1.0, 1.0,
		 0.0,1.0,0.0,

		  1.0,1.0,2.0,
		 01.0, 1.0, 1.0,//fait
		 0.0,1.0,0.0,




		   -1.0,1.0,0.0,
		    1.0, 1.0, 1.0,
		 -1.0,0.0,0.0,

		   -1.0,1.0,2.0,
		    1.0, 1.0, 1.0,
		 -1.0,0.0,0.0,

		  -1.0,-1.0,2.0,
		   1.0, 1.0, 1.0,
		 -1.0,0.0,0.0,

		  -1.0,-1.0,0.0,
		 1.0, 1.0, 1.0,//fait
		 -1.0,0.0,0.0,



		  -1.0,-1.0,0.0,
		   0.0, 1.0, 0.0,
		 0.0,-1.0,0.0,

		   -1.0,-1.0,2.0,
		   1.0, 1.0, 1.0,
		 0.0,-1.0,0.0,

		   1.0,-1.0,2.0,
		   1.0, 1.0, 1.0,
		 0.0,-1.0,0.0,

		  1.0,-1.0,0.0,
		 1.0, 1.0, 1.0,//fait
		 0.0,-1.0,0.0,

		
		-1.0,1.0,0.0,
		1.0,0.0,0.0,
		0.0,1.0,0.0,

		1.0,1.0,0.0,
		1.0,0.0,0.0,
		0.0,1.0,0.0,
		
		0.0,0.0,-4.0,
		1.0,0.0,0.0,
		0.0,1.0,0.0,

		0.0,0.0,-4.0,
		1.0,0.0,0.0,
		0.0,1.0,0.0,

		
	


		1.0,1.0,0.0,
		1.0,0.0,0.0,
		1.0,0.5,0.0,

		1.0,-1.0,0.0,
		1.0,0.0,0.0,
		1.0,0.5,0.0,
		
		0.0,0.0,-4.0,
		1.0,0.0,0.0,
		1.0,0.5,0.0,

		0.0,0.0,-4.0,
		1.0,0.0,0.0,
		1.0,0.5,0.0,
	       



		-1.0,1.0,0.0,
		1.0,0.0,0.0,
		-1.0,0.5,0.0,

		-1.0,-1.0,0.0,
		1.0,0.0,0.0,
		-1.0,0.5,0.0,
		
		0.0,0.0,-4.0,
		1.0,0.0,0.0,
		-1.0,0.5,0.0,

		0.0,0.0,-4.0,
		1.0,0.0,0.0,
		-1.0,0.5,0.0,



		-1.0,-1.0,0.0,
		1.0,0.0,0.0,
		0.0,-1.0,0.0,

		1.0,-1.0,0.0,
		1.0,0.0,0.0,
		0.0,-1.0,0.0,
		
		0.0,0.0,-4.0,
		1.0,0.0,0.0,
		0.0,-1.0,0.0,

		0.0,0.0,-4.0,
		1.0,0.0,0.0,
		0.0,-1.0,0.0,
		 
	        
		 

};
#endif
