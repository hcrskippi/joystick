#include "HapticJoystick.h"


HapticJoystick::HapticJoystick(void){
	this->joystick_id = 0;
}

HapticJoystick::HapticJoystick(int joystick_id) throw(jsexception::NoJoystickFoundException){	
	this->init_haptic(joystick_id);		
}

HapticJoystick::~HapticJoystick(void){
	delete effect;
	SDL_HapticClose(this->haptic);
}

int HapticJoystick::init_haptic(int joystick_id) throw(jsexception::NoJoystickFoundException){
	Joystick::init(joystick_id);
	this->haptic = SDL_HapticOpenFromJoystick(joystick);	
	if (haptic == NULL){
		throw jsexception::NoHapticJoystickFoundException(joystick_id);
	}

	(*this).effect = new Effect(this->haptic);
}

int HapticJoystick::applyEffect(int x,int y, int strength){
	effect->apply(x,y,strength);
} 
  
int HapticJoystick::applyEffect(int angle, int strength){
	effect->apply(angle,strength);
}



