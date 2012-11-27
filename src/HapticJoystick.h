#ifndef HAPTIC_JOYStICK_H
#define HAPTIC_JOYSTICK_H

#include "Joystick.h"
#include "jsexception/exceptions.h"
#include <SDL_haptic.h>
#include "Effect.h"

class HapticJoystick : public Joystick{
public:
	HapticJoystick(void);
	HapticJoystick(int joystick_id) throw(jsexception::NoJoystickFoundException);
	~HapticJoystick(void);
	int init(int joystick_id) throw(jsexception::NoJoystickFoundException);
	int applyEffect(int x,int y, int strength); 
	int applyEffect(int angle, int strength);
protected:
	SDL_Haptic *haptic;
	Effect *effect;
};


#endif
