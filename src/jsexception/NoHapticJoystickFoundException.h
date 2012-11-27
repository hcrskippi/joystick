#include "NoJoystickFoundException.h"
#include <string>
#include "../jsutility/utility.h"

namespace jsexception{
/*Exception thrown when a haptic joystick is not found*/
class NoHapticJoystickFoundException : public jsexception::NoJoystickFoundException{
public:
	NoHapticJoystickFoundException(int joystick_id){
		std::string temp = "Haptic joystick '";
		temp += jsutility::toString(joystick_id);
		temp += "' not found";
		jsexception::NoJoystickFoundException::message = temp;
		jsexception::NoJoystickFoundException::joystick_id = joystick_id;
	};

	~NoHapticJoystickFoundException() throw() {};
};

}
