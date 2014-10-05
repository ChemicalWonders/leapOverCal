#ifndef __SAMPLELISTENER_H__
#define __SAMPLELISTENER_H__

#include <iostream>
#include "Leap.h"

using namespace Leap;

class SampleListener : public Listener {
    public:
    virtual void onConnect(const Controller&);
    virtual void onFrame(const Controller&);
};

void SampleListener::onConnect(const Controller& controller) {
    std::cout << "Connected" << std::endl;
}

void SampleListener::onFrame(const Controller& controller) {

    //Frame frame = controller.frame();
    //Finger finger = frame.finger(frame.id());
    //FingerList fingers = frame.fingers();
	//int fingerCount = fingers.extended().count();
	//std::cout << fingerCount << std::endl;
}

#endif