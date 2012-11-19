#include "ros/ros.h"
#include "joystick/js_message.h"
#include "Joystick.h"
#include "jsexception/exceptions.h"
#include <SDL.h>

#define JOYSTICK_NODE "joy_node"
#define RATE 10

int main(int argc, char * argv[]){

	SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC);
	SDL_InitSubSystem(SDL_INIT_EVERYTHING);
	Joystick joystick;
	try{
		joystick.init(0);
	} catch(jsexception::NoJoystickFoundException &e){
		ROS_INFO(e.what());
		SDL_Quit();
		exit(-1);
	}

	ros::init(argc, argv, JOYSTICK_NODE);

	ros::NodeHandle n;
	
	/* Create a publisher that will publish a js_message command:
	 * js_message:
	 *	int16 x
	 *	int16 y
	 *	int16 z
	 * The message will be published on the joystick_commands topic
	 */
	ros::Publisher publisher = n.advertise<joystick::js_message>("joystick_commands",1000);
	
	ros::Rate loop(RATE);

	while(ros::ok()){
		joystick::js_message msg;
		msg.x = joystick.getX();
		msg.y = joystick.getY();
		msg.z = joystick.getZ();
		publisher.publish(msg);
		
		ros::spinOnce();
		
		loop.sleep();
	}

	SDL_Quit();

	return 0;
}
