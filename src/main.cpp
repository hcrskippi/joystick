#include <SDL.h>
#include <SDL_joystick.h>
#include <SDL_haptic.h>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <assert.h>
#define VERBOSE 1
#define PI 3.14159265


#include <Joystick.h>
#include <jsexception/exceptions.h>
#include <HapticJoystick.h>

int main(int argc, char * argv[]){
	SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC);
	SDL_InitSubSystem(SDL_INIT_EVERYTHING);
	try{
		HapticJoystick joystick(0);
		std::cout << joystick.getName() << std::endl;
		while(1){
			std::cout << "X : " << joystick.getX();
			std::cout << ", Y: " << joystick.getY();
			std::cout << ", Z: " << joystick.getZ() << std::endl;
			break;
		}

	for(int i = 0; i < 360; ++i){
    		int x = 1000.0*cos((float)i*PI/180.0);
    		int y = 1000.0*sin((float)i*PI/180.0);
       		std::cout << "Effect applied x = " << x << ", y = " << y << std::endl;
    		joystick.applyEffect(x,y,32767);
    		SDL_Delay(30);
   	}

	}catch (jsexception::NoJoystickFoundException &e){
		std::cout << e.what() << std::endl;
	}
	SDL_Quit();
	return 0;
}
