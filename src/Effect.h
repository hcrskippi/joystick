#ifndef EFFECT_H
#define EFFECT_H

#include <SDL.h>
#include <SDL_haptic.h>
#include <math.h>

#define PI 3.14159265

class Effect{
public:
	/**
	 *Constructor that takes as parameter an SDL_Haptic pointer
	 *If the haptic pointer is null, no exception is raised
	 *@param haptic pointer to haptic device*/
	Effect(SDL_Haptic *haptic);

	/**
	 *Default destructor. Destroys the effect.
	 */
	~Effect(void);

	/**
	 *Applies a constant feedback to direction 
	 *given by co-ordinate x & y and strength
	 *
	 *@param x
	 *@param y
	 *@param strength
	 *@return 0 on success.
	 **/
	int apply(int x, int y, int strength);
	
	/**
	 *Applies constant feedback to direction
	 *given by an angle and strength.
	 *
	 *@param angle
	 *@param strength
	 *@return 0 on success*/
	int apply(int angle, int strength);

protected:
	int effect_id;
	SDL_HapticEffect effect;
	SDL_Haptic *haptic;
};

#endif
