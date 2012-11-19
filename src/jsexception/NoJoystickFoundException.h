#ifndef NO_JOYSTICK_EXCEPTION
#define NO_JOYSTICK_EXCEPTION
#include <iostream>
#include <string>
#include <sstream>
#include "../jsutility/utility.h"


namespace jsexception{
/* Exception thrown when a particular joystick is not found
 */
class NoJoystickFoundException : public std::exception{
public:
        NoJoystickFoundException(int joystick_id) : 
		message("joystick '" + jsutility::toString(joystick_id) + "' not found"), 
		joystick_id(joystick_id){
        };  
        ~NoJoystickFoundException() throw(){};
     
        const char* what() const throw(){
                const std::string ret = this->message;
                return ret.c_str();
        }   

        std::string getMessage(void){
                return this->message;
        }   

	int getJoystickIdWithError(void){
		return this->joystick_id;
	}

protected:
	NoJoystickFoundException(void){};
        std::string message;
	int joystick_id;
};
}
#endif
