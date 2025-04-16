#include <GL/glut.h>  // use to open the window

float CarX=0.0f; //CarX is a global variable

void specialkeys(int key,int x,int y) // used to press the arrows key
{
	switch(key)
	{
	case GLUT_KEY_LEFT:  // use to move left right
	
	CarX-=0.1f;           //move left
	break;
	
	case GLUT_KEY_RIGHT:  // use to move  right
	CarX+=0.3f;         //move right
	break;
		
	}
	glutPostRedisplay(); //use to refresh the screen so that we can see the moment
		
}

void drawCar() //car ko draw karmay ka liay hai
{
	glColor3f(1.0f,0.0f,0.0f); //(R,G,B) fOR Red color
	
	glBegin(GL_QUADS); //points denay hain ta kay 4 vertices millkar rectangle banian(Quad)
	
	glVertex2f(CarX -0.2f,-0.2f);
	glVertex2f(CarX +0.2f,-0.2f);
	glVertex2f(CarX +0.2f, 0.0f);
	glVertex2f(CarX -0.2f, 0.0f);
	glEnd(); //
	
	glColor3f(0.0f,0.0f,0.0f); //black color for wheel
	
	glBegin(GL_QUADS);  //First Wheel
	
	glVertex2f(CarX -0.15f,-0.25f);
	glVertex2f(CarX -0.05f,-0.25f);
	glVertex2f(CarX -0.05f, -0.2f);
	glVertex2f(CarX -0.15f, -0.2f);
	glEnd();
	
	glBegin(GL_QUADS);  //2nd Wheel
	
	glVertex2f(CarX -0.15f,-0.25f);
	glVertex2f(CarX -0.05f,-0.25f);
	glVertex2f(CarX -0.05f, -0.2f);
	glVertex2f(CarX -0.15f, -0.2f);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // For clean the old Screen
	glLoadIdentity(); // Coordinates(x,y axis) system ko reset karta hai
	drawCar();
	glFlush(); //Draw screen par dikhata hai 
	
}

void init() //opergl initialization k liay
{
	glClearColor(0.8f,0.8f,1.0f,1.0f); // YA  line screen Ka background ko sky blue karay ga
	glMatrixMode(GL_PROJECTION); // ye bataya ga ka screen 2D mode ma hai ya 3D ma 
	glLoadIdentity(); //Draw screen par dikhata hai 
	
}

//Main Function

int main(int argC,char** argv)
 {
	glutInit(&argC,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //ye btata ha k display mode ik hi ho ga yani k screen ik hi open ho gi or RGB	 colours hongy
	glutInitWindowSize(500,500); //ya window ka size set kry ga
	glutInitWindowPosition(100,100); //starting position batata hai
	
	
glutCreateWindow("My OperGL Window");
init();
glutDisplayFunc(display);
glutSpecialFunc(specialkeys); //handling keys
glutMainLoop(); //LOOP continue until user jab chaly
return 0;
}


