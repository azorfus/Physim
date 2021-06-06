#ifndef SCENE_H
#define SCENE_H

#include <FL/Fl_Box.H>
#include <FL/Fl_Scroll.H>

class Physim;
class Scene : public Fl_Box
{
	public:
		Scene(int x, int y, int h, int w);
		void draw();
		int handle(int event);
		Physim* parent;
};

#endif // SCENE_H
