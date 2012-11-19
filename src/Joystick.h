#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_joystick.h>

#include "jsexception/exceptions.h"

class Joystick{
public:
	/*Default contructor. Initialises joystick_id to 0*/
	Joystick();

	Joystick(int joystick_id) throw(jsexception::NoJoystickFoundException);

	~Joystick();

	void init(int joystick_id) throw(jsexception::NoJoystickFoundException);

	int getJoystickId(void);

	/*Returns the recognised name of the joystick*/
	std::string getName(void);

	/*Meta data about the joystick*/
	int numOfAxes(void);
	int numOfBalls(void);
	int numOfButtons(void);
	int numOfHats(void);

	/*Joystick status*/
	bool joystickOpened(void);

	/*Event state enable:
	 *1) SDL_QUERY
	 *2) SDL_ENABLE
	 *3) SDL_IGNORE
	 * Returns 1 if enabled 
	 * Returns 0 if disabled
	 */
	int enableState(int state);
	
	void poll(void);
	
	float getX(void);
	float getY(void);
	float getZ(void);	

protected:
	Sint16 getAxisVal(int axis);
	float axisValToFloat(Sint16 axisVal);
	int joystick_id;
	SDL_Joystick *joystick;
};

#endif
