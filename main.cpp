/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Binary Search Tree Simulator
 *
 *        Version:  1.0
 *        Created:  07/06/16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:	Prathik Y R 
 *
 * =============================================================================
 */
 
 #include<stdio.h>
 #include<math.h>
 #include<GL/glut.h>
 #include "constants.h"
 
  
/*
 * =============================================================================
 *
 * init function is used to initialize the co-ordinate mode and to clear the
 * background process.
 *
 * =============================================================================
 */
 
void init() {
	glClearColor(BG_R, BG_G, BG_B, BG_A);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,SCREEN_SIZE_X,0.0,SCREEN_SIZE_Y);
}

/*
 * =============================================================================
 *
 * Displays 3 boxes for operations in the upper right corner
 * The 3 operations are : Insert, Search, Delete 
 *
 * =============================================================================
 */
 
 void displayOptions(){
 
 
 }

/*
 * =============================================================================
 *
 * init function is used to initialize the co-ordinate mode and to clear the
 * background process.
 *
 * =============================================================================
 */
 
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	displayOptions();
	
	glFlush();
}
 
 
/*
 * =============================================================================
 *
 * Starting Point of the Program and is used to initialize glut and to create a
 * new glut window and initialize its attributes.
 * Registers the callback functions used in the program
 *
 * =============================================================================
 */
 
int main(int argc,char **argv) {	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(SCREEN_SIZE_X,SCREEN_SIZE_Y);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Binary Search Tree");
	glutDisplayFunc(display);
	//glutKeyboardFunc(key);
	init();
	glutMainLoop();
	return 0;
}
