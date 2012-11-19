program_NAME := joystick
program_C_SRCS := $(wildcard *.c)
program_CXX_SRCS := main.cpp Joystick.cpp HapticJoystick.cpp
program_C_OBJS := ${program_C_SRCS:.c=.o}
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_OBJS := $(program_C_OBJS) $(program_CXX_OBJS)
program_INCLUDE_DIRS := /usr/local/include/SDL2 $(ROS_WORKSPACE)/joystick/src
program_LIBRARY_DIRS :=
program_LIBRARIES := SDL2
CPPFLAGS += -g `sdl-config --cflags --libs`
 
CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I $(includedir))
LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L $(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l $(library))

.PHONY: all clean distclean

all: $(program_OBJS)

$(program_NAME) : $(program_OBJS)
	$(LINK.cc) $(program_OBJS) -o $(program_NAME) $(LDFLAGS)

main.o : main.cpp
	$(LINK.cc) -c -o main.o main.cpp $(LDFLAGS)


Joystick.o : Joystick.cpp
	$(LINK.cc) -c -o Joystick.o Joystick.cpp  $(LDFLAGS)

clean:
#	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean
