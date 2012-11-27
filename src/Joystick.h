#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_joystick.h>

#include "jsexception/exceptions.h"

class Joystick{
public:
	/**
	 *Default contructor. Initialises joystick_id to 0*/
	Joystick();

	/**
	 *Constructor initialises a joystick with joystick_id
	 *
	 *@param joystick_id
	 *@throw jsexception::NoJoystickFoundException
	 **/
	Joystick(int joystick_id) throw(jsexception::NoJoystickFoundException);

	/**
	 *Default destructor*/
	~Joystick();

	/**
	 *Initialises joystick with joystick_id
	 *@param joystick_id
	 *@throw jsexception::NoJoystickFoundException*/
	void init(int joystick_id) throw(jsexception::NoJoystickFoundException);

	/**
	 *joystick_id getter function
	 *@return joystick id
	 */
	int getJoystickId(void);

	/**
	 *@return Returns the recognised name of the joystick
	 **/
	std::string getName(void);

	/*Meta data about the joystick*/
	/**
	 *@return number of axes available for the joystick*/
	int numOfAxes(void);
	
	/**
	 *@return*/
	int numOfBalls(void);
	
	/**
	 *@return number of buttons available for the joystick*/
	int numOfButtons(void);

	/**
	 *@return number of hats*/
	int numOfHats(void);

	/**
	 *@return true if joystick is opened*/
	bool joystickOpened(void);

	/*Event state enable:
	 *1) SDL_QUERY
	 *2) SDL_ENABLE
	 *3) SDL_IGNORE
	 * Returns 1 if enabled 
	 * Returns 0 if disabled
	 *
	 *@return 0 on success.*/
	int enableState(int state);
	
	/**
	 *Updates the state of the joystick*/
	void poll(void);
	
	/*Getter functions for X, Y & Z axis*/
	/**
	 *@return qeuries for the X co-ordinate*/
	float getX(void);
	
	/**
	 *@return queries for the y co-ordinate*/
	float getY(void);

	/**
	 *@return queries for the z co-ordinate*/
	float getZ(void);	

protected:
	Sint16 getAxisVal(int axis);
	float axisValToFloat(Sint16 axisVal);
	int joystick_id;
	SDL_Joystick *joystick;
};

#endif
