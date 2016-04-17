#include "CubeHandler.h"

CubeHandler::CubeHandler()
{
    //ctor
}

CubeHandler::~CubeHandler()
{
    //dtor
}

/*
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && animate == false) {
		mouse_click = true;
		//printf("mouse clicked at %d %d\n", x, y);
		mouseX = x;
		mouseY = GH-y-1;
		//check to see if we've selected a cubelet
		if ( (selected_cubelet = doPicking(x,y)) < 0)
			picked_cubelet = false;
		else
			picked_cubelet = true;

		//initialize v1,v2 for trackball rotations
		initialize_vectors();
	} else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && animate == false) {
		mouse_click = false;
		angle_of_rotation = 0;
	}
}

 void mouseMove(int x, int y) {
	//printf("mouse moved at %d %d\n", x, GH-y-1);
	if (animate == false && mouse_click == true && picked_cubelet == false) {
		endX = x;
		endY = GH-y-1;
		track = true;
		//do trackball stuff
		trackBall();
		glutPostRedisplay();
	} else if (picked_cubelet == true) {
		int i;
		//check to see if the mouse has changed positions (from one cubelet
		//to another cubelet).  If so, then we need to do a slice
		//rotation.
		if (selected_cubelet != (i = doPicking(x,y))) {
			rotateSlice(selected_cubelet,i);
			picked_cubelet = false;
			mouse_click = false;
		}
	}
}

//****************************************************************************

int doPicking(int x,int y) {
	GLint viewport[4];

	//set the select buffer and enter SELECT mode
	glSelectBuffer(BUFSIZE,selectBuf);
	glRenderMode(GL_SELECT);

	//store the current viewing
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	//set up the viewing
	glGetIntegerv(GL_VIEWPORT,viewport);

	//set up pixel picking region near mouse
	gluPickMatrix((GLdouble)x,(GLdouble)viewport[3]-y,PICK_REGION,PICK_REGION,viewport);
	glOrtho( (-(float)GW/GH), ((float)GW/GH), -1, 1, -1, 1);

	//return to model matrix
	glMatrixMode(GL_MODELVIEW);

	//draw the cube
	renderObjs();

	// restoring the original projection matrix
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glutSwapBuffers();

	//get the number of hits
	unsigned int hits = glRenderMode(GL_RENDER);

	if (hits != 0) { //we clicked on the cube somewhere
		unsigned int i;
		GLuint names, *ptr, minZ,*ptrNames, numberOfNames;

		ptr = (GLuint *) selectBuf;
		ptrNames = ptr;
		minZ = 0xffffffff;
		for (i = 0; i < hits; i++) {
			names = *ptr;
			ptr++;
			if (*ptr < minZ) {
				selected_face = *ptrNames;
				numberOfNames = names;
				minZ = *ptr;
				ptrNames = ptr+2;
			}

			ptr += names+2;
		}
		//printf ("Selected cubelet: [%d]\n",*ptrNames);
		//printf ("Selected face: [%d]\n",selected_face);
		//return the name of the selected cubelet
		return *ptrNames;
	}
	return -1;
}
*/
