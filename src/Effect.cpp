#include "Effect.h"
#define MAX_STRENGTH 32767


Effect::Effect(SDL_Haptic *haptic) : haptic(haptic){                     
	//Create effect, set all values to zero
	effect.type = SDL_HAPTIC_CONSTANT;
	effect.constant.direction.type = SDL_HAPTIC_CARTESIAN; // 
	effect.constant.direction.dir[0] = 0; // x-direction = 0
	effect.constant.direction.dir[1] = 0; // y-direction = 0
	effect.constant.delay = 0; // 0 ms
	effect.constant.level = 0; // 0/32767 strength
	effect.constant.attack_level = 0;/// 0 seconds
	effect.constant.length = SDL_HAPTIC_INFINITY;
	effect.constant.attack_length = 0; // Takes 0 seconds to get max strength
	effect.constant.fade_length = 0; // Takes 0 seconds to fade away

	// Initialise the effect id
	effect_id = SDL_HapticNewEffect(this->haptic, &effect);
	//Run once for updating the effect later on
	SDL_HapticRunEffect(this->haptic,effect_id,1);
}

Effect::~Effect(void){
	SDL_HapticDestroyEffect(haptic, effect_id);
}


int Effect::apply(int x, int y, int strength){
	effect.constant.direction.dir[0] = x; // x-axis
	effect.constant.direction.dir[1] = y; // y-axis
	effect.constant.level = strength; // strength
	// Update effect
	return(SDL_HapticUpdateEffect(haptic, effect_id, &effect));
}

int Effect::apply(int angle, int strength){
	int x = 1000.0*cos((float)angle*PI/180.0);
	int y = 1000.0*sin((float)angle*PI/180.0);
	return this->apply(x, y, strength);
}
