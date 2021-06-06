#ifndef PHYSIM_H
#define PHYSIM_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include <stdio.h>
#include <vector>
#include "particle.h"
#include "toolbar.h"

class Scene;
class Physim : public Fl_Double_Window
{
	public:
		Physim(int w, int h, const char* title);
		void update();
		Fl_Offscreen offscreen_buffer = 0;
		Scene* scene;
		Fl_Menu_Bar* menubar;
		Toolbar* toolbar;
		std::vector <Particle> particles;
		int pcount;
};

#endif // PHYSIM_H
