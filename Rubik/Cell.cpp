#include "Cell.h"
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>

Cell::Cell(const Cell& c){
    color = c.color;
    location = c.location;
    normal = c.normal;
    cellTexture = c.cellTexture;
}

Cell::Cell(int _color, Point3D _location, Point3D _normal){
    color = _color;
    location = _location;
    normal = _normal;
    cellTexture = LoadTextureRAW( "texture.raw", TRUE );
}

Cell::~Cell(){
}

int Cell::getColor(){
    return color;
}

void Cell::setColor(int _color){
    color = _color;
}

Point3D Cell::getLocation(){
    return location;
}

void Cell::setLocation(Point3D _location){
    location = _location;
}

Point3D Cell::getNormal(){
    return normal;
}

void Cell::setNormal(Point3D _normal){
    normal = _normal;
}
void Cell::setColor(){
    if(color == RED){
        glColor3f(1.0f,0.0f,0.0f);
    } else if(color == GREEN){
        glColor3f(0.0f,1.0f,0.0f);
        // glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
        // glClear( GL_COLOR_BUFFER_BIT );

        // setup texture mapping
        // glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
        // glClear( GL_COLOR_BUFFER_BIT );

        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, cellTexture );
        glEnd();
        // glPushMatrix();
        std::cout << cellTexture << std::endl;
    } else if(color == WHITE){
        glColor3f(1.0f,1.0f,1.0f);
    } else if(color == BLUE){
        glColor3f(0.0f,0.0f,1.0f);
    } else if(color == ORANGE){
        glColor3f(1.0f,0.5f,0.0f);
    } else if(color == YELLOW){
        glColor3f(1.0f,1.0f,0.0f);
    }
}

int Cell::getFace(){
    Point3D top(0,-1,0);
    Point3D bottom(0,1,0);
    Point3D right(1,0,0);
    Point3D left(-1,0,0);
    Point3D behind(0,0,-1);
    Point3D infront(0,0,1);
    if (normal.isEquals(top)) {
        return 0;
    } else if (normal.isEquals(bottom)) {
        return 1;
    } else if (normal.isEquals(right)) {
        return 2;
    } else if (normal.isEquals(left)) {
        return 3;
    } else if (normal.isEquals(behind)) {
        return 4;
    } else if (normal.isEquals(infront)) {
        return 5;
    }
}


void Cell::drawCell() {
    float size = 0.9f;
    float blackspace = 1.0f;
    float x = location.getX()*2.25;
    float y = location.getY()*2.25;
    float z = location.getZ()*2.25;
    glBegin(GL_QUADS);		// Draw The Cube Using quads

    if (getFace() == 0) {
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y+blackspace, z-blackspace);	// Top Right Of The Quad (Top)
        glVertex3f(x-blackspace, y+blackspace, z-blackspace);	// Top Left Of The Quad (Top)
        glVertex3f(x-blackspace, y+blackspace, z+blackspace);	// Bottom Left Of The Quad (Top)
        glVertex3f(x+blackspace, y+blackspace, z+blackspace);	// Bottom Right Of The Quad (Top)
        glEnd();

        //setColor();
        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, cellTexture );
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x-size, y+size, z-size);	// Top Left Of The Quad (Top)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, y+size, z-size);	// Top Right Of The Quad (Top)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, y+size, z+size);	// Bottom Right Of The Quad (Top)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x-size, y+size, z+size);	// Bottom Left Of The Quad (Top)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 1) {
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y-blackspace, z+blackspace);	// Top Right Of The Quad (Bottom)
        glVertex3f(x-blackspace, y-blackspace, z+blackspace);	// Top Left Of The Quad (Bottom)
        glVertex3f(x-blackspace, y-blackspace, z-blackspace);	// Bottom Left Of The Quad (Bottom)
        glVertex3f(x+blackspace, y-blackspace, z-blackspace);	// Bottom Right Of The Quad (Bottom)
        glEnd();

        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, cellTexture );
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x-size, y-size, z+size);	// Top Left Of The Quad (Bottom)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, y-size, z+size);	// Top Right Of The Quad (Bottom)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, y-size, z-size);	// Bottom Right Of The Quad (Bottom)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x-size, y-size, z-size);	// Bottom Left Of The Quad (Bottom)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 2) {
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(x+blackspace-0.2, y+blackspace, z-blackspace);	// Top Right Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y+blackspace, z+blackspace);	// Top Left Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y-blackspace, z+blackspace);	// Bottom Left Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y-blackspace, z-blackspace);	// Bottom Right Of The Quad (Right)
        glEnd();

        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, cellTexture );
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x+size, y+size, z+size);	// Top Left Of The Quad (Right)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, y+size, z-size);	// Top Right Of The Quad (Right)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, y-size, z-size);	// Bottom Right Of The Quad (Right)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x+size, y-size, z+size);	// Bottom Left Of The Quad (Right)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 3) {
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(x-blackspace+0.2, y+blackspace, z+blackspace);	// Top Right Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y+blackspace, z-blackspace);	// Top Left Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y-blackspace, z-blackspace);	// Bottom Left Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y-blackspace, z+blackspace);	// Bottom Right Of The Quad (Left)
        glEnd();

        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, cellTexture );
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x-size, y+size, z-size);	// Top Left Of The Quad (Left)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x-size, y+size, z+size);	// Top Right Of The Quad (Left)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x-size, y-size, z+size);	// Bottom Right Of The Quad (Left)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x-size, y-size, z-size);	// Bottom Left Of The Quad (Left)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 4) {
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y-blackspace, z-blackspace+0.2);	// Top Right Of The Quad (Back)
        glVertex3f(x-blackspace, y-blackspace, z-blackspace+0.2);	// Top Left Of The Quad (Back)
        glVertex3f(x-blackspace, y+blackspace, z-blackspace+0.2);	// Bottom Left Of The Quad (Back)
        glVertex3f(x+blackspace, y+blackspace, z-blackspace+0.2);	// Bottom Right Of The Quad (Back)
        glEnd();

        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, cellTexture );
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x-size, y-size, z-size);	// Top Left Of The Quad (Back)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, y-size, z-size);	// Top Right Of The Quad (Back)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, y+size, z-size);	// Bottom Right Of The Quad (Back)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x-size, y+size, z-size);	// Bottom Left Of The Quad (Back)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else if (getFace() == 5) {
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(x+blackspace, y+blackspace, z+blackspace-0.2);	// Top Right Of The Quad (Front)
        glVertex3f(x-blackspace, y+blackspace, z+blackspace-0.2);	// Top Left Of The Quad (Front)
        glVertex3f(x-blackspace, y-blackspace, z+blackspace-0.2);	// Bottom Left Of The Quad (Front)
        glVertex3f(x+blackspace, y-blackspace, z+blackspace-0.2);	// Bottom Right Of The Quad (Front)
        glEnd();

        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, cellTexture );
        glBegin(GL_QUADS);		// Draw The Cube Using quads
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x-size, y+size, z+size);	// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, y+size, z+size);	// Top Right Of The Quad (Front)
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, y-size, z+size);	// Bottom Right Of The Quad (Front)
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x-size, y-size, z+size);	// Bottom Left Of The Quad (Front)
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
}

// load a 256x256 RGB .RAW file as a texture
GLuint Cell::LoadTextureRAW( const char * filename, int wrap )
{
    std::cout << "LOAD TEXTURE" << std::endl;
    GLuint texture;
    int width, height;
    BYTE * data;
    FILE * file;

    // open texture data
    file = fopen( filename, "rb" );
    if ( file == NULL ) {
        printf("Image could not be opened\n");
        return 0;
    } else {
         printf("File found\n");
    }

    // allocate buffer
    width = 256;
    height = 256;
    data = (BYTE*) malloc(width * height * 3);

    // read texture data
    fread( data, width * height * 3, 1, file );
    fclose( file );

    // allocate a texture name
    glGenTextures( 1, &texture );

    // select our current texture
    glBindTexture( GL_TEXTURE_2D, texture );

    // select modulate to mix texture with color for shading
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // when texture area is small, bilinear filter the closest mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                     GL_LINEAR_MIPMAP_NEAREST );
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                     wrap ? GL_REPEAT : GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                     wrap ? GL_REPEAT : GL_CLAMP );

    // build our texture mipmaps
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,
                       GL_RGB, GL_UNSIGNED_BYTE, data );

    // free buffer
    free( data );

    return texture;
}

void Cell::FreeTexture( GLuint texture )
{

  glDeleteTextures( 1, &texture );

}

