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
#include<string.h>
#include<GL/glut.h>
#include "constants.h"

// A variable used to establish a distance between two option boxes
float offset = 0.0;

// Integer color code for RGB
enum color_code {RED, GREEN, BLUE};

/*
 * =============================================================================
 *
 * A class which is the blueprint of an option box which is displayed at the top
 * right corner. It holds all the information related to constructing an option
 * box.
 *
 * =============================================================================
 */
 
class option_box {

	private:
		float bottom_corner_x, bottom_corner_y;
		float bc;
		float height, width; 
		float color[3];
		char option_name[20];
		
	public:
	
		// Empty Constructor
		option_box(){
			bottom_corner_x = 0;
			bottom_corner_y = 0;
			width = 0;
			height = 0;
			color[RED] = 0.0;
			color[GREEN] = 0.0;
			color[BLUE] = 1.0;
			strcpy(option_name, "");
		}
	
		// Constructor used to initialize all the properties of the option box
		option_box(const char name[]){
			bottom_corner_x = 600;
			bottom_corner_y = 600;
			width = 100;
			height = 50;
			color[RED] = 0.0;
			color[GREEN] = 0.0;
			color[BLUE] = 1.0;
			strcpy(option_name, name);
		}
		
		// method used to display the name of the option box  
		void display_name(char s[], float x, float y, float z = 0.0){
			glColor3f(1.0, 1.0, 0.0);
			glRasterPos3f(x, y, z);
			for(int i=0; s[i]; i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
			glFlush();
		}
		
		// method used to draw the option box and call the display_name method
		void draw_box(){
			bottom_corner_x += offset;
			bc = bottom_corner_x;
			glColor3f(color[RED], color[GREEN], color[BLUE]);
			glBegin(GL_POLYGON);
				glVertex2f(bottom_corner_x, bottom_corner_y);
				glVertex2f(bottom_corner_x + width, bottom_corner_y);
				glVertex2f(bottom_corner_x + width, bottom_corner_y + height);
				glVertex2f(bottom_corner_x, bottom_corner_y + height);
			glEnd();
			offset += 120.0;
			display_name(option_name, bottom_corner_x + 10.0, bottom_corner_y + 20.0);
		}
		
		// A function to check whether mouse was clicked on this box given the co-ordinates
		bool clicked(int x, int y){
			if( x > bc && x < bc + width)
				if( y > bottom_corner_y && y < bottom_corner_y + height)
					return true;
			return false;
		}
};
 
option_box insert_box, search_box, delete_box; 
  
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
 	option_box insert_box("Insert"), search_box("Search"), delete_box("Delete");
 	offset = 0.0;
	insert_box.draw_box();
	search_box.draw_box();
	delete_box.draw_box();
	::insert_box = insert_box;
	::search_box = search_box;
	::delete_box = delete_box;
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
 * A mouse call back function used to get the co-ordinates of a mouse click
 * This callback is used to check on which option the user has clicked and calls
 * the corresponding function accordingly
 *
 * =============================================================================
 */
 
void mouse(int button, int state, int x, int y){
	y = SCREEN_SIZE_Y - y;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if(insert_box.clicked(x, y))
			printf("Insert\n");
		if(search_box.clicked(x, y))
			printf("Search\n");
		if(delete_box.clicked(x, y))
			printf("Delete\n");
	}
		
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
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
	return 0;
}
