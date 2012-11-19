#include "Joystick.h"
#include <sstream>
#include <string>
#include "jsutility/utility.h"
#include <limits.h>

Joystick::Joystick(void){
	this->joystick_id = 0;
}

Joystick::Joystick(int joystick_id) throw(jsexception::NoJoystickFoundException){
	this->init(joystick_id);
}

void Joystick::init(int joystick_id) throw(jsexception::NoJoystickFoundException){
	if(this->joystickOpened()){
		return;
	}
	this->joystick_id = joystick_id;
	this->joystick = SDL_JoystickOpen(this->joystick_id);
	if(this->joystick == NULL){
		throw jsexception::NoJoystickFoundException(this->joystick_id); 
	}
	this->enableState(SDL_QUERY);
	this->poll(); 
}

Joystick::~Joystick(){
	SDL_JoystickClose(this->joystick);
}

void Joystick::poll(void){
	SDL_JoystickUpdate();
}

int Joystick::getJoystickId(void){
	return this->joystick_id;
}

int Joystick::enableState(int state){
	return SDL_JoystickEventState(state);
}

int Joystick::numOfHats(void){
	return SDL_JoystickNumHats(this->joystick);
}

bool Joystick::joystickOpened(void){
	return SDL_JoystickOpened(this->joystick_id);	
}

int Joystick::numOfButtons(void){
	return SDL_JoystickNumButtons(this->joystick);
}

int Joystick::numOfAxes(void){
	return SDL_JoystickNumAxes(this->joystick);
}

int Joystick::numOfBalls(void){
	return SDL_JoystickNumBalls(this->joystick);
}

std::string Joystick::getName(void){
	return jsutility::toString(SDL_JoystickName(this->joystick_id));
}

Sint16 Joystick::getAxisVal(int axis){
	this->poll();
	return SDL_JoystickGetAxis((*this).joystick,axis);
}

float Joystick::getX(void){
  	return this->axisValToFloat(this->getAxisVal(0));
}

float Joystick::getY(void){
  	return this->axisValToFloat(this->getAxisVal(1));
}

float Joystick::getZ(void){
	return this->axisValToFloat(this->getAxisVal(2));
}

float Joystick::axisValToFloat(Sint16 axisVal){
	return (float) (1.0*axisVal)/(1.0*SHRT_MAX);
}
