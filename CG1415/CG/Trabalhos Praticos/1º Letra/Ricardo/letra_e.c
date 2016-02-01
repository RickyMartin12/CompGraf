/********************************************************/
/****************** Nome: Ricardo Peleira ***************/
/***************** Número: a44377 ***********************/
/****************** Tema 1: Fazer a Letra E *************/


/* 
Totalidade do Trabalho de CG:

- 3D 
- Translação
- Rotação
- Textura
*/

// Compilar no Mingw programa que executa a linguagem c em OpenGL

// Demonstração: $ gcc -o  T1 T1.c -lGL -lGLU -lglut -lm

// Referencias Web para o 1º Trabalho de CG

/*
- http://www.cin.ufpe.br/~marcelow/Marcelow/cubo.c.html
- http://www.nullterminator.net/gltexture.html
- http://stackoverflow.com/questions/18538869/why-use-gltranslatef-why-not-just-change-the-rendering-co-ords
- http://www.dei.isep.ipp.pt/~ffp/opengl/demos.html
- http://www.gsigma.ufsc.br/~popov/aulas/cg/espaco.html
- http://w3.ualg.pt/~srnunes/CG/exemplo4.html
- http://www.gsigma.ufsc.br/~popov/aulas/cg/
*/

#include <gl/glut.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Sites Vistos na Web (1º TRabalho)

// Eixo de Rotação para ordem x

#include "textura_letra_e.h"

GLfloat angle, fAspect,button, state;
static GLuint texName;
static GLfloat rotacao = 0.0;
GLfloat PosX,PosY,moveX,moveY,dX,dY;
GLfloat x, y, z, radius=1, a=10, f, g;

void Desenha(void);
void Inicializa (void);
void EspecificaParametrosVisualizacao(void);
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void mouse(int button, int state, int x, int y);
void Timer_left(int value);
void Timer_right(int value);
void CarregarMouse (int button, int state, int x, int y);
void Translacao(int x,int y);

            
// Função callback chamada para fazer o desenho
void letra_e(void)
{

	// Fazer a letra E

	// Abordagem em 3D

	// Rotação em movimento de translação da letra
	//x = 400 * cos(50.0);
    //z = 400 * sin(50.0);
	
	//glTranslatef(x,0,z);
	
	// Parte Inicial da Letra E - (Traço) -

	// Parte 1 - Parte em baixo

	//glTranslatef (-50.0, -50.0, 10.0);
		
	//glColor4f(0.0, 1.0, 1.0, 1.0);

	glBegin (GL_QUADS);
	
	glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(20.0, 10.0, 10.0);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(140.0, 10.0, 10.0);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(140.0, 10.0, -10.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(20.0, 10.0, -10.0);
	glEnd();

	
	// Parte 2 - Parte de Trás

	//glColor4f(1.0, 0.0, 0.0, 1.0);
	
	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0); 
		glTexCoord2f(1.0f, 0.0f);glVertex3f(20.0, 10.0, -10.0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(140.0, 10.0, -10.0);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(140.0, 40.0, -10.0);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(50.0, 40.0, -10.0);
	glEnd();

	
	// Parte 3 - Parte de Frente

	//glColor4f(0.0, 1.0, 0.0, 1.0);

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0); 
		glTexCoord2f(0.0f, 0.0f);glVertex3f(20.0, 10.0, 10.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(140.0, 10.0, 10.0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(140.0, 40.0, 10.0);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(50.0, 40.0, 10.0);
	glEnd();

	// Parte 4 - Parte do lado direito

	//glColor4f(1.0, 1.0, 0.0, 1.0);

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0); 
		glTexCoord2f(1.0f, 0.0f);glVertex3f(140.0, 40.0, 10.0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(140.0, 10.0, 10.0);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(140.0, 40.0, -10.0);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(140.0, 10.0, -10.0);
	glEnd();

	// Parte 5 - Parte do lado esquerdo (para tapar a zona do traço)

	//glColor4f(1.0, 0.0, 1.0, 1.0);

	glBegin (GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0); 
		glTexCoord2f(0.0f, 0.0f);glVertex3f(140.0, 10.0, -10.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(140.0, 10.0, 10.0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(140.0, 40.0, 10.0);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(140.0, 40.0, -10.0);
	glEnd();

	// Parte 6 - Parte de cima 

	//glColor4f(1.0, 1.0, 0.0, 1.0);

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(140.0, 40.0, 10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(50.0, 40.0, 10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(50.0, 40.0, -10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(140.0, 40.0, -10.0);
	glEnd();
	
	// Parte Inicial da Letra E - (Altura da Letra) - |

	// Parte 1 - Parte em baixo

	//glColor4f(1.0, 1.0, 0.0, 1.0);

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(20.0, 10.0, -10.0);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(20.0, 10.0, 10.0);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(50.0, 40.0, 10.0);	
		glTexCoord2f(1.0f, 0.0f);glVertex3f(50.0, 40.0, -10.0);
	glEnd();
	

	//Parte 2 - Parte do lado direita

	//glColor4f(1.0, 0.0, 1.0, 1.0);

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(50.0, 40.0, 10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(50.0, 40.0,-10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(50.0, 210.0,-10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(50.0, 210.0,10.0);
	glEnd();

	//Parte 3 - Parte do lado esquerdo

	//glColor4f(0.0, 1.0, 1.0, 1.0);

	glBegin (GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0, 210.0,10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(20.0, 10.0,10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0, 10.0,-10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0, 210.0,-10.0);
	glEnd ();

	// Parte 4 - Parte de cima

	//glColor4f(1.0, 1.0, 1.0, 1.0);

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0, 210.0,10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(20.0, 210.0,-10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(50.0, 210.0,-10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(50.0, 210.0,10.0);
	glEnd();

	// Parte 5 - Parte de Trás

	//glColor4f(0.0, 0.0, 0.0, 1.0);

	glBegin (GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0, 10.0, -10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(50.0, 40.0, -10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(50.0, 210.0, -10.0);
	glEnd ();
	
	// Parte 6 - Parte de Frente

	//glColor4f(0.0, 1.0, 0.0, 1.0);

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(20.0, 10.0, 10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(50.0, 40.0, 10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(50.0, 210.0, 10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0, 210.0, 10.0);
	glEnd ();

	// Parte Inicial da Letra E - (Traço da letra) (2º vez) - (-)

	//glColor4f(0.0, 1.0, 0.0, 1.0);

	// Parte 1 - Parte de Frente

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(20.0, 210.0, 10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(140.0, 210.0, 10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(140.0, 180.0, 10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(50.0, 180.0, 10.0);
	glEnd ();

	// Parte 2 - Parte de Trás

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0, 210.0, -10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(140.0, 210.0, -10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(140.0, 180.0, -10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(50.0, 180.0, -10.0);
	glEnd ();

	// Parte 3 - Parte do Lado Esquerdo

	glBegin (GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(140.0, 180.0, -10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(140.0, 180.0, 10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(140.0, 210.0, 10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(140.0, 210.0, -10.0);
	glEnd();

	// Parte 4 - Parte do Lado Direito

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0); 
		glTexCoord2f(1.0f, 0.0f); glVertex3f(140.0, 210.0, 10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(140.0, 180.0, 10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(140.0, 210.0, -10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(140.0, 180.0, -10.0);
	glEnd();

	// Parte 5 - Parte de Cima

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0, 210.0, 10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(140.0, 210.0, 10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(140.0, 210.0, -10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0, 210.0, -10.0);
	glEnd ();

	// Parte 6 - Parte de Baixo

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0, 180.0, 10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(140.0, 180.0, 10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(140.0, 180.0, -10.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(20.0, 180.0, -10.0);
	glEnd ();

	// Parte Inicial da Letra E - (Traço da letra) (3º vez) - (-)

	//glColor4f(.75,.25,.80,1.0);

	// Parte 1 - Parte de Frente

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(50.0, 130.0, 10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(140.0, 130.0, 10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(140.0, 100.0, 10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0, 100.0, 10.0);
	glEnd ();

	
	// Parte 2 - Parte de Trás

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(50.0, 130.0, -10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(140.0, 130.0, -10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(140.0, 100.0, -10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(20.0, 100.0, -10.0);
	glEnd ();

	// Parte 3 - Parte do Lado Esquerdo

	glBegin (GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(140.0, 100.0, -10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(140.0, 100.0, 10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(140.0, 130.0, 10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(140.0, 130.0, -10.0);
	glEnd();

	// Parte 4 - Parte do Lado Direito

	glBegin (GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0); 
		glTexCoord2f(1.0f, 0.0f); glVertex3f(140.0, 130.0, 10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(140.0, 100.0, 10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(140.0, 130.0, -10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(140.0, 100.0, -10.0);
	glEnd();


		// Parte 5 - Parte de Cima

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0, 130.0, 10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(140.0, 130.0, 10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(140.0, 130.0, -10.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0, 130.0, -10.0);
	glEnd ();

	// Parte 6 - Parte de Baixo

	glBegin (GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0, 100.0, 10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(140.0, 100.0, 10.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(140.0, 100.0, -10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0, 100.0, -10.0);
	glEnd ();
	glFlush ();

}

void Desenha (void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	//glColor4f(1, 0, 1,1);
	glScalef( 0.8, 0.8, 0.8); 
	//glTranslatef(moveX, moveY, 0);
	x = 450 * cos(f);
    z = 50 * sin(g);


	glTranslatef(0,z,0);

	//glRotatef (rotacao, 0, 1, 0);
	//faz rotacao do objecto com movimento do rato
	//Desenho a letra E
	letra_e();
	
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glEnable(GL_TEXTURE_2D);
	

	
	glPopMatrix();

	glutSwapBuffers();

}
// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
 	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	angle=90;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	
	
	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	
	gluPerspective(angle,fAspect,0.5,2000);

	gluLookAt(0,200,500, 0,0,0, 0,1,0);
	

	/*
   glOrtho(-200.0, 200.0, -200.0, 200.0, 0.0, 60.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   */
   
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimensões da viewport
	glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

void spinDisplay(void)
{
   //rotacao = rotacao - 0.1;
    rotacao = rotacao - 1;
   g = g - 0.01;
   f = f - 0.01;
   if (rotacao > 360.0)
   {
	   rotacao = rotacao - 360.0;
   }
      
   glutPostRedisplay();
}

void spinDisplay2(void)
{
   //rotacao = rotacao + 0.1;
    rotacao = rotacao + 1;
   g = g + 0.001;
   f = f + 0.001;
   if (rotacao > 360.0)
   {
	   rotacao = rotacao - 360.0;
   }
   glutPostRedisplay();
}

void Timer_left(int value)
{
	if (value)
	{
		glRotatef (-5, 0, 1, 0);
		glutPostRedisplay ();
		glutTimerFunc (33, Timer_left, value-1);
	}
	else
	{
		glutMouseFunc (mouse);
	}
}

void Timer_right(int value)
{
	if (value)
	{
		glRotatef (5, 0, 1, 0);
		glutPostRedisplay ();
		glutTimerFunc (33, Timer_right, value-1);
	}
	else
	{
		glutMouseFunc (mouse);
	}
}

void mouse(int button, int state, int x, int y) 
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
			  glutIdleFunc(spinDisplay2);
		 }
         break;
      default:
         break;
   }
}



void CarregarMouse (int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		glutMouseFunc (mouse);
	}
}


void Translacao(int x,int y){
	glutMouseFunc (CarregarMouse);
	
	dX=x-PosX;
	dY=y-PosY;

	if(dX>0) moveX+=10;
	if(dX<0) moveX-=10;
	if(dY>0) moveY-=10;
	if(dY<0) moveY+=10;
	if(dX!=0) moveX+=dX/10;
	if(dY!=0) moveY-=dY/10;
	PosX=x; PosY=y;

	EspecificaParametrosVisualizacao();
	glutPostRedisplay ();
	
	

}


void Keyboard(unsigned char key, int x, int y)
{
    switch (key) 
	{
            case 27: 
					 exit (0);
                     break;
    }
    glutPostRedisplay();
}

int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("1º Trabalho - Letra E");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(mouse);
	Inicializa();
	glutMainLoop();
}