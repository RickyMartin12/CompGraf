

#include <Windows.h>
#include <gl/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "lapras.h"
#include "pokebola_baixo.h"
#include "pokebola_cima.h"
#include "pokebola_meio.h"
#include "pika.h"

//#pragma comment( lib, "opengl32.lib" )
#pragma comment( lib, "glu32.lib" )
#pragma comment( lib, "glew32.lib" )



const int font=(int)GLUT_BITMAP_9_BY_15;
GLfloat angle, fAspect;
GLfloat win, r, g, b;
char string[64];
GLint view_w, view_h, primitiva;
static GLfloat rotacao = 0.0;
GLfloat PosX,PosY;    
GLfloat rotX=0,rotY=0;
GLfloat x, y, z, w, radius=1, a=10, f, g, h;


double  xCamara=0,yCamara=20,zCamara=100;

int value;
int musica;
boolean key_button[256];

// Desenhar o wall-e exportado em blender - Modelo da Representação (modelo de arames ou objeto sólido, com textura)

void lapras (void)
{
	glColor3f (1.0f, 1.0f, 1.0f);
	glTranslatef (0,-20,0);
	glRotatef (270, 1, 0, 0);
	glRotatef (270, 0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof (struct vertex_struct), vertices);
	glNormalPointer(GL_FLOAT,sizeof (struct vertex_struct),&(vertices[0].nx));
	
	glDrawElements(GL_TRIANGLES , sizeof (indexes)/sizeof(unsigned short), GL_UNSIGNED_SHORT , indexes);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glutPostRedisplay ();

	
}

void pokebola_baixo (void)
{
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof (struct vertex_struct_poke_baixo), vertices_poke_baixo);
	glNormalPointer(GL_FLOAT,sizeof (struct vertex_struct_poke_baixo),&(vertices_poke_baixo[0].nx));
	
	glDrawElements(GL_TRIANGLES , sizeof (indexes_poke_baixo)/sizeof(unsigned short), GL_UNSIGNED_SHORT , indexes_poke_baixo);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glutPostRedisplay ();

	
}

void pokebola_cima (void)
{
	glColor3f (1.0f, 0.0f, 0.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof (struct vertex_struct_poke_cima), vertices_poke_cima);
	glNormalPointer(GL_FLOAT,sizeof (struct vertex_struct_poke_cima),&(vertices_poke_cima[0].nx));
	
	glDrawElements(GL_TRIANGLES , sizeof (indexes_poke_cima)/sizeof(unsigned short), GL_UNSIGNED_SHORT , indexes_poke_cima);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glutPostRedisplay ();

	
}

void pokebola_meio (void)
{
	glColor3f (0.0f, 0.0f, 0.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof (struct vertex_struct_poke_meio), vertices_poke_meio);
	glNormalPointer(GL_FLOAT,sizeof (struct vertex_struct_poke_meio),&(vertices_poke_meio[0].nx));
	
	glDrawElements(GL_TRIANGLES , sizeof (indexes_poke_meio)/sizeof(unsigned short), GL_UNSIGNED_SHORT , indexes_poke_meio);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glutPostRedisplay ();

	
}


void pikachu (void)
{
	glColor3f (1.0f, 1.0f, 0.0f);
	glScalef (2,2,2);
	glTranslatef (-0.3,-1, 0);
	glRotatef (270, 1, 0, 0);
	glRotatef (270, 0, 0, 1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof (struct vertex_struct_pika), vertices_pika);
	glNormalPointer(GL_FLOAT,sizeof (struct vertex_struct_pika),&(vertices_pika[0].nx));
	
	glDrawElements(GL_TRIANGLES , sizeof (indexes_pika)/sizeof(unsigned short), GL_UNSIGNED_SHORT , indexes_pika);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glutPostRedisplay ();

	
}

void pokebola (void)
{
	glColor3f (1.0f, 1.0f, 1.0f);
	glScalef (5,5,5);
	glTranslatef (0.2, 2, 0);
	glRotatef (270, 1, 0, 0);
	glRotatef (270, 0, 0, 1);
	pokebola_baixo ();
	pokebola_cima ();
	pokebola_meio();
}


// Função callback chamada para fazer o desenho - Desehar todos os objectos da cena
void Desenha(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	y = 70 * cos(f);
    z = 50 * sin(g);
	x = 2 * sin(h);
	w = 70 * cos(g);
	// Carregar a inicialização e a finalizaçõa da textura ---- ver texture.h

	glPushMatrix ();
	glTranslatef (y, abs(z),0);
		pokebola ();
	glPopMatrix ();

	// direito
	
	glPushMatrix ();
	glTranslatef (70, x, 0);
		lapras ();
	glPopMatrix ();

	glPushMatrix ();
	glTranslatef (70, x, 0);
		pikachu ();
	glPopMatrix ();
	
	

	

	// esquerda
	
	glPushMatrix ();
	glTranslatef (-70, -x, 0);
	glRotatef (180,0,1,0);
		lapras ();
	glPopMatrix ();

	glPushMatrix ();
	glTranslatef (-70, -x, 0);
	glRotatef (180,0,1,0);
		pikachu ();
	glPopMatrix ();

	//baixo

	/*
	glPushMatrix ();
	glTranslatef (0, x, 70);
	glRotatef (270,0,1,0);
		lapras ();
	glPopMatrix ();

	glPushMatrix ();
	glTranslatef (0, x, 70);
	glRotatef (270,0,1,0);
		pikachu ();
	glPopMatrix ();
	*/

	glutSwapBuffers();
}


// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
	
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

	// Carregar a textura de uma imagem de fundo - NAO ESTA A FUNCIONAR - VER no Trabalho prático 3

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);
	
	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
	angle=90;

	
}

// Função usada para especificar o volume de visualização - Alterar as Vistas da camara F1 e F6, através gluLookAt
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();
	// Especifica a projeção perspectiva
	gluPerspective(angle,fAspect,0.4,500);
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	
	// Especifica posição do observador e do alvo
	gluLookAt(xCamara,yCamara,zCamara, 0,0,0, 0,1,0);

}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

void spinDisplay(void)
{
   //rotacao = rotacao - 0.1;
    rotacao = rotacao - 1;
   g = g - 0.005;
   f = f - 0.005;
   h = h + 0.005;
   if (rotacao > 360.0)
   {
	   rotacao = rotacao - 360.0;
   }
      
   glutPostRedisplay();
}

// menu - Trabalho 2

void MenuRepresentacao (int op)
{
   switch(op) {
            case 0:
					 glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
                     break;
            case 1:
					 glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                     break;
    }
    glutPostRedisplay();
}           

void MenuIluminacao (int op)
{
	switch(op) 
	{
		case 0: glEnable(GL_LIGHTING); 
			break;
		case 1: glDisable(GL_LIGHTING);
			break;
	}
	glutPostRedisplay();
}

void MenuGourand_Shading (int op)
{
	switch(op) 
	{
		case 0: glShadeModel(GL_SMOOTH);
			break;
		case 1: glShadeModel (GL_FLAT);
			break;
	}
	glutPostRedisplay();
}

void MenuAntialiasing(int op)
{
	switch (op)
	{
		case 0: 
			glEnable( GL_LINE_SMOOTH );
            glEnable( GL_SMOOTH );
		break;
		case 1: 
			glDisable( GL_LINE_SMOOTH );
            glDisable( GL_SMOOTH );
		break;
	}
	glutPostRedisplay();
}

// Gerenciamento do menu principal           
void MenuPrincipal(int op)
{
}
              
// Criacao do Menu
void CriaMenu() 
{
    int menu, submenu1, submenu3, submenu4, submenu5;

    submenu1 = glutCreateMenu(MenuRepresentacao);
    glutAddMenuEntry("Flat",0);
    glutAddMenuEntry("Wireframe",1);



    submenu3 = glutCreateMenu(MenuIluminacao);
    glutAddMenuEntry("On",0);
    glutAddMenuEntry("Off",1);

    submenu4 = glutCreateMenu(MenuGourand_Shading);
    glutAddMenuEntry("On",0);
    glutAddMenuEntry("Off",1);

    submenu5 = glutCreateMenu(MenuAntialiasing);
    glutAddMenuEntry("On",0);
    glutAddMenuEntry("Off",1);

    menu = glutCreateMenu(MenuPrincipal);
    glutAddSubMenu("Representacao",submenu1);
    glutAddSubMenu("Iluminacao",submenu3);
	glutAddSubMenu("Gourand Shading",submenu4);
    glutAddSubMenu("Antialiasing",submenu5);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


           
// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	PosX=x; PosY=y;
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_UP)
		 {
			 //glutTimerFunc (33, Timer_left, 72);
			  glutIdleFunc(spinDisplay);
		 }
            
         break;
	  case GLUT_MIDDLE_BUTTON:
         if (state == GLUT_UP)
			 glutIdleFunc(NULL);
		 break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_UP)
         {
			 //glutTimerFunc (33, Timer_right, 72);
			  CriaMenu();
		 }
         break;
      default:
         break;
   }
}

// Indicar o tempo em que vai aumentar ou diminuir a velocidade

void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);
}


void sound (void)
{

		PlaySound(TEXT("C:\\Users\\boxpc\\Desktop\\Pokemon Pikachu Talking.wav"), NULL,SND_ASYNC);
		//PlaySound(TEXT("C:\\Users\\boxpc\\Desktop\\1.wav"), NULL,SND_ASYNC);
}

void stop (void)
{

		PlaySound(NULL, 0, 0);

}



void GerenciaTeclado(unsigned char key, int x, int y) {
  int warning;
  warning = x + y; // apenas para evitar um warning na compilacao
  
  value=0;

  if (key == 27)
  {
	  	 exit (0);
  }
  if (key == '-')
  {
	if (angle <= 130)
	  {
		  angle += 5;
		  EspecificaParametrosVisualizacao ();
	  }
  }

  // Alterar as Vistas - Zoom in e Zoom Out
  if (key == '+')
  {
	if (angle >= 10)
	{
		  angle -= 5;
		  EspecificaParametrosVisualizacao ();
	}
	  
  }
  if (key == 13)
  {
	  sound ();
  }
  if (key == 32)
  {
	  stop ();
  }

  glutPostRedisplay ();
  
}


void TeclasEspeciais (int key, int x, int y)
{
	  //Vistas com as teclas Especiais
	//Tecla F1 - Cima
	if (key == GLUT_KEY_F1)
  {
	  xCamara=0;
      yCamara=10; 
	  zCamara=100;
	EspecificaParametrosVisualizacao();
  }
	//Tecla F2 - Baixo
    if (key == GLUT_KEY_F2) // Tecla F2 da camara 1
  {
	  xCamara=0;
      yCamara=0; 
	  zCamara=100;
	  EspecificaParametrosVisualizacao();
  }
	//Tecla F3 - Atrás
  if (key == GLUT_KEY_F3) // Tecla F3 da camara 3
  {
	  xCamara=0;
      yCamara=20; 
	  zCamara=100;
	  EspecificaParametrosVisualizacao();
  }
  //Tecla F4 - Lado Esquerdo
  	  if (key == GLUT_KEY_F4) // Tecla F1 da camara 1
  {
	  xCamara=-20;
      yCamara=100; 
	  zCamara=0;
	  EspecificaParametrosVisualizacao();
  }
	  //Tecla F5 - Lado Direito
    if (key == GLUT_KEY_F5) // Tecla F2 da camara 1
  {
	  xCamara=20;
      yCamara=100; 
	  zCamara=0;
	  EspecificaParametrosVisualizacao();
  }
	//Tecla F6 - Perspectiva inicial
  if (key == GLUT_KEY_F6) // Tecla F3 da camara 3
  {
	  xCamara=0;
      yCamara=20; 
	  zCamara=-100;
	  EspecificaParametrosVisualizacao();
  }
glutPostRedisplay ();

}

// Programa Principal
int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1350,800);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutKeyboardFunc (GerenciaTeclado);
	glutKeyboardUpFunc (GerenciaTeclado);
	glutMouseFunc(GerenciaMouse);
	glutSpecialFunc(TeclasEspeciais); 
	Inicializa();
	glutMainLoop();
}

