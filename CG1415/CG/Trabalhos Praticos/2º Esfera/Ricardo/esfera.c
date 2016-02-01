/********************************************************/
/****************** Nome: Ricardo Peleira ***************/
/***************** Número: a44377 ***********************/
/****************** Tema 2: Desenhar a esfera em 3D *************/


/* 
Totalidade do Trabalho de CG:

- Esfera; 
- Rotação;
- Cores Diferentes;
- Movimento do rato em OpenGL;
- Translação em circulo
*/

// Compilar no Mingw programa que executa a linguagem c em OpenGL

// Demonstração: $ gcc -o  T2 T2.c -lGL -lGLU -lglut -lm

// Referencias Web para o 2º Trabalho de CG

/*
- http://www.cburch.com/cs/490/sched/feb8/
- http://keisan.casio.com/exec/system/1359534351
- http://mathworld.wolfram.com/Sphere.html
- http://pt.wikipedia.org/wiki/Esfera
- http://blog.johnryding.com/post/3087060819/opengl-circles
- https://www.cs.umd.edu/class/spring2013/cmsc425/OpenGL/OpenGLSamples/OpenGL-3D-Sample/OpenGL-3D-Sample-ForC/opengl-3D-sample.c
*/




#pragma comment(lib, "winmm.lib")
#include <gl/glut.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define PI 3.1415926535898

// Sites Vistos na Web (2º TRabalho - Desenhar Esfera)

// Eixo de Rotação para ordem x

//double pi = 4.0 * atan(1.0);
GLfloat angle, fAspect,button, state, ang, ang2;
static GLfloat rotacao = 0.0;
GLfloat PosX,PosY,moveX,moveY,dX,dY;
GLfloat x, y, z, radius=1, a=10, f, g;
GLfloat x_0, y_0, z_0;
double pi=0.0;
int v;

// Variaveis da equação cartesiana

GLfloat x_cartesian, y_cartesian, z_cartesian, t, ap;

GLdouble theta, phi, eyeX, eyeY, eyeZ, r, theta, upX, upY, upZ;
	GLsizei winHeight, winWidth;
	GLfloat eyeXtemp, eyeYtemp, eyeZtemp, dt;





typedef struct 
{
  double x;
  double y;
  double z;
} Vertices;

//Vertices v[100000];

GLfloat color_array[][3] = {
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 0.5, 1.0},
	{0.57, 0.5, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 0.5, 1.0},
	{0.57, 0.5, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 0.5, 1.0},
	{0.57, 0.5, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 0.5, 1.0},
	{0.57, 0.5, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 0.5, 1.0},
	{0.57, 0.5, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 0.5, 1.0},
	{0.57, 0.5, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 0.5, 1.0},
	{0.57, 0.5, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 0.5, 1.0},
	{0.57, 0.5, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 0.5, 1.0},
	{0.57, 0.5, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 0.5, 1.0},
	{0.57, 0.5, 0.0}
};


void vertices_esfera (GLfloat lan, GLfloat log)
{
	//double phi=0.0, theta=0.0;
	int i;
	/*
	Vertices *v = (Vertices *) malloc (nvertices * sizeof(Vertices));
	GLfloat radius = (double) (PI / 180.0);
	pi = 4.0 * atan(1.0);
    
	glBegin(GL_TRIANGLE_FAN);
	for (i=0; i <= nvertices; i++)
	{
		v[i].x = raio * sin(radius*lan) * cos(radius*log);
		v[i].y = raio * sin(radius*lan) * sin(radius*log);
		v[i].z = raio * cos(radius*lan);
		glVertex3f (v[i].x, v[i].y, v[i].z);
	}
	glEnd();
	*/


	int lineAmount = 100; //# of triangles used to draw circle
	Vertices *v = (Vertices *) malloc (lineAmount * sizeof(Vertices));

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;


	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount;i++) 
		{ 
			v[i].x = radius * cos(i *  twicePi / lineAmount);
			v[i].y = radius * sin(i * twicePi / lineAmount);
			v[i].z = 0;
			glVertex3f(v[i].x , v[i].y , v[i].z);
		}
	glEnd();
}


void desenhar_esfera (int dimensao)
{
		
	int i;
	//glRotatef (90.0, 0, 1, 0);
	//glRotatef (90.0, 1, 0, 0);
	//glVertex2f(0.0f,0.5f);
	//cos(verticalAngle) * sin(horizontalAngle),
    //sin(verticalAngle),
    //cos(verticalAngle) * cos(horizontalAngle)
	glBegin(GL_TRIANGLE_FAN);
	//glVertex3f(0.0f,0.0f, 2.0f);
	for(i = 0; i <= dimensao; i++) 
	{ 
		//glVertex3f ((2 + i * sin(3.14159f) * cos(2*3.14159f)), (2 + (dimensao/2) * sin(3.14159f) * sin(2*3.14159f)), (2 + (dimensao/2) * cos(3.14159f)));
		glVertex3f((2 * cos(i *  (2*3.14159f) / dimensao)), (2 * sin(i * (2*3.14159f) / dimensao)),(cos(2*3.14159f) * sin(2*3.14159f)));
	}
	glEnd();
}



            
// Função callback chamada para fazer o desenho da esfera em 3D

void drawSphere(double r, int vertices) 
{
      int i, j;
	 
	  glBegin(GL_TRIANGLE_FAN);
      for(i = 0; i <= vertices; i++) // latitude
	  {
          double lat0 = PI * (-0.5 + (double) (i - 1) / vertices);
         double z0  = r * sin(lat0);
         double zr0 =  r * cos(lat0);
    
         double lat1 = PI * (-0.5 + (double) i / vertices);
         double z1 = r * sin(lat1);
         double zr1 = r * cos(lat1);
		 for(j = 0; j <= vertices; j++) // longitude
		 {
               double lng = 2 * PI * (-0.45 + (double) (j - 1) / vertices);
               double x2 = cos(lng);
               double y2 = sin(lng);
			   //glColor3ub( 255.0, 0.0, 0.0 );
			    glColor3fv(color_array[j]);
					//glNormal3f(x2 * zr0, y2 * zr0, z0);			
					glVertex3f(x2 * zr0, y2 * zr0, z0);
					//glColor3ub( 0.0 , 0.0, 255.0 );
					//glNormal3f(x2 * zr1, y2 * zr1, z1);			
					glVertex3f(x2 * zr1, y2 * zr1, z1);
			  
          }
      }
      glEnd();

 }


void Desenha (void)
{
	int i=0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
	//glScalef (x_0, y_0, z_0);
	//glRotatef (270, 1, 0, 0);
	//glRotatef (rotacao, 0, 0, 1);
	glRotatef (rotacao, 1, 1, 1);

		
		
		drawSphere(1.0+x_0,100+v);
		//vertices_esfera (1.0);
		//desenhar_esfera (100);
	
	
	//glutWireSphere (1.0,10,10);
	//desenhar_esfera (100);
	
	glPopMatrix();

	glutSwapBuffers();

}


// Inicializa parâmetros de rendering
void Inicializa (void)
{ 


 	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	

	
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	angle=90;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();
	
	gluPerspective(angle,fAspect,0.5,2000);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(0,1,4, 0,0,0, 0,0.5,0);
	
	
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
   rotacao = rotacao - 1;
   if (rotacao > 360.0)
      rotacao = rotacao - 360.0;
   glutPostRedisplay();
}


void spinDisplay2(void)
{
   rotacao = rotacao + 1;
   if (rotacao > 360.0)
      rotacao = rotacao - 360.0;
   glutPostRedisplay();
}

void onMouseMove(int x, int y) 
{
	
// Mouse point to angle conversion
   theta = (360.0/winHeight)*x*3.0;    //3.0 rotations possible
   phi = (360.0/winWidth)*y*3.0;

// Restrict the angles within 0~360 deg (optional)
   if(theta > 360)theta = fmod((double)theta,360.0);
   if(phi > 360)phi = fmod((double)phi,360.0);

// Spherical to Cartesian conversion.   
// Degrees to radians conversion factor 0.0174532
   eyeX = r * sin(theta*0.0174532) * sin(phi*0.0174532);
   eyeY = r * cos(theta*0.0174532);
   eyeZ = r * sin(theta*0.0174532) * cos(phi*0.0174532);

// Reduce theta slightly to obtain another point on the same longitude line on the sphere.
    dt=1.0;
    eyeXtemp = r * sin(theta*0.0174532-dt) * sin(phi*0.0174532);
    eyeYtemp = r * cos(theta*0.0174532-dt);
    eyeZtemp = r * sin(theta*0.0174532-dt) * cos(phi*0.0174532);

// Connect these two points to obtain the camera's up vector.
   upX=eyeXtemp-eyeX;
   upY=eyeYtemp-eyeY;
   upZ=eyeZtemp-eyeZ;

   glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) 
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_UP)
		 {
			 glutIdleFunc (spinDisplay);
		 }
            
         break;
	  case GLUT_MIDDLE_BUTTON:
         if (state == GLUT_UP)
			 glutIdleFunc(NULL);
		 break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_UP)
         {
			 glutIdleFunc (spinDisplay2);
		 }
         break;
      default:
         break;

   }
}


void Keyboard(unsigned char key, int x, int y)
{
    switch (key) 
	{
            case 27: 
					 exit (0);
                     break;
			case '+':
					x_0 += 0.1;
					break;
			case '-':
					x_0 -= 0.1;
					break;
			// figura em wireframe
			case 'b': 
				glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
				break;
			// figura em solido
			case 'n':
				glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
				break;
			// diminuir o numero de triangulos
			case 'a':
				if (v >= -70)
				{
					v -= 10;
				}
				break;
			// aumentar o numero de triangulos
			case 's':
				if (v <= -5)
				{
					v += 10;
				}
				
				break;
    }
    glutPostRedisplay();
}

int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("2º Trabalho - Desenho da esfera");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(mouse);
	//glutPassiveMotionFunc(onMouseMove);
	Inicializa();
	glutMainLoop();
}