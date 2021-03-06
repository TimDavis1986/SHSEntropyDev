#include "AcquisitionArms.h"
#include "EntropyJoystick.h"
#include "EntropyInfraredSensor.h"
#include "IODefinitions.h"

AcquisitionArms::AcquisitionArms() {

}

bool AcquisitionArms::Initialize() 
{
	upperSolenoid = new Solenoid (upperSolenoidChannel);
	lowerSolenoid = new Solenoid (lowerSolenoidChannel);
	InfraredSensor.Initialize();
	MotorBelt = new Victor(IODefinitions::MOTOR_ACQUISITION_BELT);
	MotorExtender = new Jaguar(IODefinitions::MOTOR_ACQUISITION_EXTENDER);

	return true;
}
void AcquisitionArms::TeleopInitialize()
{
	
}
void AcquisitionArms::Cleanup() 
{
	upperSolenoid->Set(false);
	lowerSolenoid->Set(false);
	MotorExtender->Set(0.0);
	MotorBelt->Set(0.0);
	
}
void AcquisitionArms::UpperVerticalPos(EntropyJoystick * GameStick) 
{
	if( GameStick->GetRawButton(IODefinitions::GAME_BUTTON_ARM_UP) 
			^ GameStick->GetRawButton(IODefinitions::GAME_BUTTON_ARM_DOWN))
	{
		upperSolenoid->Set(GameStick->GetRawButton(IODefinitions::GAME_BUTTON_ARM_UP));
	}
	
}
void AcquisitionArms::LowerVerticalPos(EntropyJoystick * GameStick)
{
	if( GameStick->GetRawButton(IODefinitions::GAME_BUTTON_CRADLE_DOWN) 
			^ GameStick->GetRawButton(IODefinitions::GAME_BUTTON_CRADLE_UP))
	{
		lowerSolenoid->Set(GameStick->GetRawButton(IODefinitions::GAME_BUTTON_CRADLE_UP));
	}
}

void AcquisitionArms::Extend(EntropyJoystick * GameStick)
{
	if (GameStick->GetRawButton(IODefinitions::GAME_BUTTON_ARM_OUT)) {
		MotorExtender->Set(0.5);
	} else if (GameStick->GetRawButton(IODefinitions::GAME_BUTTON_ARM_IN)) {
		MotorExtender->Set(-0.5);
	} else {
		MotorExtender->Set(0.0);
	}
}
void AcquisitionArms::BeltEnable(EntropyJoystick * GameStick)
{
	if (GameStick->GetRawButton(IODefinitions::GAME_BUTTON_ARM_ROLL_IN)) {
		MotorBelt->Set(1.0);
	} else if (GameStick->GetRawButton(IODefinitions::GAME_BUTTON_ARM_ROLL_OUT)){
		MotorBelt->Set(-1.0);
	} else {
		MotorBelt->Set(0.0);
	}
}

char * AcquisitionArms::GetFeedback(){ return NULL;}
