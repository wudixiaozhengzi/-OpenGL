#include <GL/glut.h> 

void myDisplay(void) { 
		glClear(GL_COLOR_BUFFER_BIT); 
		glPointSize(5.0f);
		glBegin( GL_POINTS);        
			glVertex2f(0.1f, 0.1f);    
			glVertex2f(-0.5f, 0.0f);
		glEnd();     
		glFlush();
}


int main(int argc, char *argv[]) { 
	glutInit(&argc, argv);     
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);     
	glutInitWindowPosition(100, 100);     
	glutInitWindowSize(400, 400);    
	glutCreateWindow("绘制点线面");     
	glutDisplayFunc(&myDisplay);     
	glutMainLoop();    
	return 0; 
}
