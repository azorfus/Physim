#include "physim.h"
#include "scene.h"

static Physim* physim = new Physim(600, 400, "physim");

void callback(void*)
{
	physim->update();
	Fl::repeat_timeout(0.08, callback);
}

void add_particle(Fl_Widget*)
{
	if(physim->toolbar->particle.state == false) 
		physim->toolbar->particle.state = true;
	else
		physim->toolbar->particle.state = false; 
}

void run_simulation(Fl_Widget*)
{
	if(physim->toolbar->control.state == false) 
	{
		physim->toolbar->control.state = true;
    	Fl::add_timeout(0.08, callback);
	}
	else
	{
		physim->toolbar->control.state = false; 
		Fl::remove_timeout(callback);	
	}
}

int main(int argc, char **argv)
{
	physim->toolbar->control.button->callback(run_simulation);
	physim->toolbar->particle.button->callback(add_particle);
	return Fl::run();
}
