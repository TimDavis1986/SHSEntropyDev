#ifndef __ACQUISITION_ARMS__
#define __ACQUISITION_ARMS__

#include "WPILib.h"
#include "EntropySubsystemTemplate.h"
#include "EntropyJoystick.h"
#include "EntropyInfraredSensor.h"
#include "IODefinitions.h"

class AcquisitionArms : public EntropySubsystemTemplate
{
private:
	static const int upperSolenoidChannel = IODefinitions::ARM_ROTATION;
	static const int lowerSolenoidChannel = IODefinitions::ARM_RAIL;
	Solenoid * upperSolenoid;
	Solenoid * lowerSolenoid;
	
	EntropyInfraredSensor InfraredSensor;
	Victor * MotorBelt;
	Jaguar * MotorExtender;

public:
	AcquisitionArms();
	
	bool Initialize ();
	
	void TeleopInitialize();
		
	void Cleanup();
		
	char * GetFeedback();
	
	void UpperVerticalPos(EntropyJoystick * GameStick);
	
	void LowerVerticalPos(EntropyJoystick * GameStick);

	void Extend(EntropyJoystick * GameStick);
	
	void BeltEnable(EntropyJoystick * GameStick);
};

#endif
