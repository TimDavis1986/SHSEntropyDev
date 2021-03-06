#include "Kicker.h"
#include "IODefinitions.h"

Kicker::Kicker() {
	
	
}

bool Kicker::Initialize()
{
	PullMotor = new Jaguar(IODefinitions::KICKER_PULL); 
	Piston_Trigger = new Solenoid(IODefinitions::KICKER_TRIGGER);
	Piston_Shifter = new Solenoid(IODefinitions::KICKER_SHIFTER);
	Piston_Trigger->Set(LOCKED);
	Piston_Shifter->Set(DISENGAGED);
	kickerState = idle;
	pistonTimer = 0;
	pullTimer = 0;
	unwindTimer = 0;
	return true;
}

void Kicker::Cleanup()
{ 
	PullMotor->Disable();
	Piston_Trigger->Set(LOCKED);
	Piston_Shifter->Set(DISENGAGED);
}

void Kicker::Kick(bool pull, bool kick)
{
	switch(kickerState)
	{
	    default: 
		case idle: 
			
			if( true == pull)
			{
				PullMotor->Set(0.0);
				kickerState = pulling;
				pullTimer = PULLTIME;
				Piston_Shifter->Set(ENGAGED);
			}
			break;
		case pulling:
			if(pullTimer > 0)
				{
					pullTimer--;
					PullMotor->Set(0.4);
				}
			else
				{
				PullMotor->Set(0.0);
				unwindTimer = UNWINDTIME;
				kickerState = unwinding;
				}
			break;
		case unwinding:
			if(unwindTimer > 0)
			{
				unwindTimer--;
				PullMotor->Set(-0.4);
			}
			else
			{	
				PullMotor->Set(0.0);
				Piston_Shifter->Set(DISENGAGED);
				kickerState = readytoshoot;
			}
		case readytoshoot:
			if (true == kick)
			{
				Piston_Trigger->Set(RELEASED);
				pistonTimer = INITIALTIME;
				kickerState = kicked;
			}
			break;
		case kicked:
			if(pistonTimer > 0)
			{
				pistonTimer--;
			}
			else
			{
				Piston_Trigger->Set(LOCKED);
				kickerState = idle;
			}
	}
}

char * Kicker::GetFeedback(){ return NULL;}


