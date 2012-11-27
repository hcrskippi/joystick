#include "ros/ros.h"
#include "joystick/js_axes.h"
#include "joystick/haptic_cartesian.h"
#include "joystick/haptic_polar.h"
#include "Joystick.h"
#include "jsexception/exceptions.h"
#include <SDL.h>
#include "HapticJoystick.h"

#define JOYSTICK_NODE "joy_node"
#define JOYSTICK_TOPIC "joystick_axes"
#define HAPTIC_CARTESIAN "haptic_cartesian"
#define HAPTIC_POLAR "haptic_polar"
#define RATE 10



HapticJoystick *js = new HapticJoystick();

void cartesian(const joystick::haptic_cartesian& msg){
	js->applyEffect(msg.x, msg.y, msg.strength);	
}

void polar(const joystick::haptic_polar& msg){
	js->applyEffect(msg.angle, msg.strength);
} 

int main(int argc, char * argv[]){

	SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC);
	SDL_InitSubSystem(SDL_INIT_EVERYTHING);
	

	try{
		js->init(0);
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
	ros::Publisher publisher = n.advertise<joystick::js_axes>(JOYSTICK_TOPIC,1000);

	ros::Subscriber cartesianSubscriber = n.subscribe(HAPTIC_CARTESIAN, 1000, cartesian);

	ros::Subscriber polarSubscriber = n.subscribe(HAPTIC_POLAR, 1000, polar);
	
	ros::Rate loop(RATE);

	while(ros::ok()){
		joystick::js_axes msg;
		msg.x = js->getX();
		msg.y = js->getY();
		msg.z = js->getZ();
		publisher.publish(msg);
		
		ros::spinOnce();
		
		loop.sleep();
	}

	SDL_Quit();

	return 0;
}
