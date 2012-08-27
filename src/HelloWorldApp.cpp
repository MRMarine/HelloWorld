#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HelloWorldApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
  private:
	float red, green, blue;
};

void HelloWorldApp::setup()
{
}

void HelloWorldApp::mouseDown( MouseEvent event )
{
	// change the screen color by checking the mouse position in the window
	// and dividing by the height/width to get a ratio from 0 to 1 for red and green
	
	// viewport saves as an array [0, 0, width, height] if I'm not mistaken.
	GLint window_viewport[4];

	glGetIntegerv( GL_VIEWPORT, window_viewport );
	
	red = (float)(event.getX()) / window_viewport[2];
	green = (float)(event.getY()) / window_viewport[3];
	// set the blue ratio to a random float between 0 and 1.
	blue = rand() % 10 / 10.0;
}

void HelloWorldApp::update()
{
}

void HelloWorldApp::draw()
{
	// clear out the window to the value determined by the RGB set in mouseDown( MouseEvent )
	gl::clear( Color( red, green, blue ) ); 
}

CINDER_APP_BASIC( HelloWorldApp, RendererGl )
