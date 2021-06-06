#include "physim.h"
#include "scene.h"
#include "particle.h"

Physim::Physim(int w, int h, const char* title) : Fl_Double_Window(0, 0, w, h, title)
{
	menubar = new Fl_Menu_Bar(0, 0, 640, 20);
	menubar->add("&File");
	menubar->add("&View");
	menubar->add("&About");
	pcount = 0;
	Fl_Scroll* scr = new Fl_Scroll(0, 45, 600, 400);
    scene = new Scene(0, 45, 600, 400);
	scene->parent = this;
	scr->end();
	toolbar = new Toolbar(0, 20, 600, 25);
	this->resizable(scene);
	this->show();
	scene->draw();
}

void Physim::update()
{
	for(int i=0;i<pcount;i++)
	{
		if(i<=particles.size())
		{
			particles[i].update(this);	
		}
	}
}
