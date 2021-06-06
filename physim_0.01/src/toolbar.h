#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Pixmap.H>
#include "resource.cpp"

class Toolbar : public Fl_Group
{
	public:
		Toolbar(int x, int y, int w, int h);
		typedef struct Button
		{
			Fl_Button* button;
			Fl_Pixmap* pixmap;
		} Button;

		typedef struct T_Button
		{
			Fl_Toggle_Button* button;
			Fl_Pixmap* pixmap;
			bool state;
		} T_Button;

		T_Button control;
		T_Button particle;
};

#endif // TOOLBAR_H
