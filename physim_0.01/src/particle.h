#ifndef PARTICLE_H
#define PARTICLE_H

class Physim;
class Particle
{
	public:
		Particle(Physim* parent, int x, int y, int r, char* label);
		void update(Physim* parent);
		char* label;
		float x;
		float y;
		float r;
		float velocity_y; 	
};

#endif // PARTICLE_H
