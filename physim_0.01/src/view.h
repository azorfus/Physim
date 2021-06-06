#ifndef VIEW_H
#define VIEW_H

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include "scene.h"

class Physim;
class View : public Fl_Group
{
	public:
		View(int x, int y, int w, int h, Physim* parent);
		Scene* scene;
};

#endif //VIEW_H
