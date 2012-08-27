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
	float r, g, b;
};

void HelloWorldApp::setup()
{
}

void HelloWorldApp::mouseDown( MouseEvent event )
{
	// change the screen color by checking the mouse position in the window
	// and dividing by the height/width to get a ratio from 0 to 1 for red and green
	GLint m_viewport[4];

	glGetIntegerv( GL_VIEWPORT, m_viewport );
	
	r = (float)(event.getX()) / m_viewport[2];
	g = (float)(event.getY()) / m_viewport[3];
	// set the blue ratio to a random float between 0 and 1.
	b = rand() % 10 / 10.0;
}

void HelloWorldApp::update()
{
}

void HelloWorldApp::draw()
{
	// clear out the window to the value determined by the RGB set in mouseDown( MouseEvent )
	gl::clear( Color( r, g, b ) ); 
}

CINDER_APP_BASIC( HelloWorldApp, RendererGl )
