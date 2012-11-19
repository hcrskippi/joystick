#ifndef HAPTIC_JOYStICK_H
#define HAPTIC_JOYSTICK_H

#include "Joystick.h"
#include "jsexception/exceptions.h"
#include <SDL_haptic.h>

class HapticJoystick : public Joystick{
public:
	/*Default constructors and destructors*/
	HapticJoystick(void);
	HapticJoystick(int joystick_id) throw(jsexception::NoJoystickFoundException);
	~HapticJoystick(void);

	int init_haptic(int joystick_id) throw(jsexception::NoJoystickFoundException);

protected:
	SDL_Haptic *haptic;
};


#endif
