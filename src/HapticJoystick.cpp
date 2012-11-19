#include "HapticJoystick.h"


HapticJoystick::HapticJoystick(void){
	this->joystick_id = 0;
}

HapticJoystick::HapticJoystick(int joystick_id) throw(jsexception::NoJoystickFoundException){	
	this->init_haptic(joystick_id);		
}

HapticJoystick::~HapticJoystick(void){
	SDL_HapticClose(this->haptic);
}

int HapticJoystick::init_haptic(int joystick_id) throw(jsexception::NoJoystickFoundException){
	Joystick::init(joystick_id);
	this->haptic = SDL_HapticOpenFromJoystick(joystick);	
	if (haptic == NULL){
		throw jsexception::NoHapticJoystickFoundException(joystick_id);
	}
	/*Initialise other stuff*/
}





