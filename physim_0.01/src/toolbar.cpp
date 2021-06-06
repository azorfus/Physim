#include "toolbar.h"


Toolbar::Toolbar(int x, int y, int w, int h) : Fl_Group(x, y, w, h)
{
	box(FL_UP_BOX);
	control.button = new Fl_Toggle_Button(x, y, 24, 24);
	control.button->tooltip("Run/Stop simulation (Left Alt)");
	control.pixmap = new Fl_Pixmap(run_xpm);
	control.button->image(control.pixmap);
	control.button->shortcut(FL_Alt_L);
	control.state = false;
	x+=24;
	particle.button = new Fl_Toggle_Button(x, y, 24, 24);
	particle.button->tooltip("Add particle");
	particle.pixmap = new Fl_Pixmap(particle_xpm);
	particle.button->image(particle.pixmap);
	particle.state = false;

}
