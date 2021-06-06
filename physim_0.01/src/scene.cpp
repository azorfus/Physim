#include "scene.h"
#include "physim.h"
#include "particle.h"

Scene::Scene(int x, int y, int w, int h) : Fl_Box(x,y,w,h)
{
}

void Scene::draw()
{
	if(parent->offscreen_buffer)
	{
		fl_copy_offscreen(x(), y(), w(), h(), parent->offscreen_buffer, 0,0);
	}
	else
	{
		parent->make_current();
		this->resize(0, 45, 1000, 1000);
		parent->offscreen_buffer = fl_create_offscreen( 1000, 1000 );
		if(!parent->offscreen_buffer){fprintf(stderr,"Failed buffer creation"); exit(1);}
		fl_begin_offscreen(parent->offscreen_buffer); /* Open the offscreen context */
		fl_color(FL_WHITE);
		fl_rectf(0, 0, 1000, 1000);
		//fl_rectf(0, 0, parent->w(), parent->h());
		fl_end_offscreen(); /* close the offscreen context */
		/* init screen with offscreen buffer */
		fl_copy_offscreen(x(), y(), 1000, 1000, parent->offscreen_buffer, 0,0);
	}
}

int Scene::handle(int event)
{
	int button, x, y, retvalue;
	retvalue = Fl_Box::handle(event);
	switch (event)
	{
		case FL_PUSH:
			button = Fl::event_button();
			x = Fl::event_x();
			y = Fl::event_y()-45;
			if(button==FL_LEFT_MOUSE && parent->toolbar->particle.state==true)
			{
				if(parent->pcount >= 101)
				{
					fl_message("Particle limit exceeded");
					break;
				}
				char pname[100];
				snprintf(pname, sizeof(pname), "p%d", parent->pcount);
				Particle particle(parent, x, y, 10, pname);
			
				parent->particles.push_back(particle);
				printf("%s\n", pname);
				parent->redraw();
				parent->pcount++;
			}
		break;
	};
	return retvalue;
}
