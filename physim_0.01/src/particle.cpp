#include "particle.h"
#include "physim.h"

Particle::Particle(Physim* parent, int gx, int gy, int gr, char* label)
{
	x = gx;
	y = gy;
	r = gr;
	velocity_y = 2;
	fl_begin_offscreen(parent->offscreen_buffer);
	fl_color(FL_YELLOW);
	fl_pie(gx-5, gy-5, 10, 10, 0, 360);
	fl_color(FL_BLACK);
	fl_arc(gx-5, gy-5, 10, 10, 0, 360);
	fl_end_offscreen();
	parent->redraw();
}

void Particle::update(Physim* parent)
{
	if(y<300)
	{
		velocity_y = y/20;
		fl_begin_offscreen(parent->offscreen_buffer);
		fl_color(FL_WHITE);
		fl_pie(x, y, 10, 10, 0, 360);
		//x+=1;
		y+=velocity_y;
		fl_color(FL_YELLOW);
		fl_pie(x, y, 10, 10, 0, 360);
		fl_color(FL_BLACK);
		fl_arc(x, y, 10, 10, 0, 360);
		fl_end_offscreen();
		parent->redraw();
	}
	if(y>300)
	{
		y = 300;
		velocity_y*=-2;
	}
}
