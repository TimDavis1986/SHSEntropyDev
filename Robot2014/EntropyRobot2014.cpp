#include "WPILib.h"
#include "IODefinitions.h"
#include "EntropyDrive.h"
#include "EntropyJoystick.h"
#include "ExampleSHS.h"
#include "EntropyInfraredSensor.h"
#include "AcquisitionArms.h"
#include "GenericHID.h"
#include "Math.h"
#include "Kicker.h"
#include "EntropyCompressor.h"
//#include "Autonomy.h"


class EntropyRobot2014 : public IterativeRobot
{
	// Declare variable for the robot system
		
	// Declare a variable to use to access the driver station object
	DriverStation *EntropyDriverStation;			// driver station object
	UINT32 m_priorPacketNumber;					// keep track of the most recent packet number from the DS
	UINT8 m_dsPacketsReceivedInCurrentSecond;	// keep track of the ds packets received in the current second
	
	// Declare variables for the two joysticks being used
	EntropyJoystick *DriveStick;			// EntropyJoystick used for robot driving
	EntropyJoystick *GameStick;			// EntropyJoystick for all other functions		
	float m_turnSpeed;
	
	//Output to Driver Station;
	DriverStationLCD *ds; 
	
	// Declare SHS Subsystems here
	EntropyCompressor MyCompressor;
	EntropyDrive MyRobot;		// The Robot Drive instance
	AcquisitionArms Arm;	
    Kicker MyKicker; 			//The Shooter instance
    //Autonomy* MyAutoRobot;
    
	// Local variables to count the number of periodic loops performed
	UINT32 m_autoPeriodicLoops;
	UINT32 m_disabledPeriodicLoops;
	UINT32 m_telePeriodicLoops;
	
	//Creating a test "InfraredSensor", by way of using an Autonomous Selector Switch
	EntropyInfraredSensor InfraredSensor;
	
	
public:
/**
 * Constructor for this "EntropyRobotDrive2014" Class.
 */
	EntropyRobot2014(void)	
	{
		printf(" Constructor Started\n");

		// Establish Hardware IO Controllers
		DriveStick = new EntropyJoystick(IODefinitions::USB_PORT_1);
		GameStick = new EntropyJoystick(IODefinitions::USB_PORT_2);			
		MyCompressor.Initialize();
			
		// Acquire the Driver Station object
		EntropyDriverStation = DriverStation::GetInstance();
		m_priorPacketNumber = 0;
		m_dsPacketsReceivedInCurrentSecond = 0;

		// Initialize counters to record the number of loops completed in autonomous and teleop modes
		m_autoPeriodicLoops = 0;
		m_disabledPeriodicLoops = 0;
		m_telePeriodicLoops = 0;

		ds = DriverStationLCD::GetInstance();
		
		m_turnSpeed=1.0;
		printf("EntropyBot14 Constructor Completed\n");
	}
	
	
	/********************************** Init Routines *************************************/

	void RobotInit(void) 
	{
		// Actions which would be performed once (and only once) upon initialization of the
		// robot would be put here.
		
		
		// Initialize SHS Subsystems here
		MyRobot.Initialize();
		MyCompressor.Initialize();
		Arm.Initialize();
		InfraredSensor.Initialize();
        MyKicker.Initialize();
        
        //MyAutoRobot = new Autonomy(MyRobot);
        
		printf("RobotInit() completed.\n");
	}
	
	void DisabledInit(void) 
	{
		m_disabledPeriodicLoops = 0;			// Reset the loop counter for disabled mode
	}

	void AutonomousInit(void) 
	{
		m_autoPeriodicLoops = 0;				// Reset the loop counter for autonomous mode
		
	}

	void TeleopInit(void) 
	{
		m_telePeriodicLoops = 0;				// Reset the loop counter for teleop mode
		m_dsPacketsReceivedInCurrentSecond = 0;	// Reset the number of dsPackets in current second
				
		Arm.TeleopInitialize();
	}

	/********************************** Periodic Routines *************************************/
	
	void DisabledPeriodic(void)  
	{
		
		//Disable Drive
		MyRobot.Cleanup();
		Arm.Cleanup();
		MyKicker.Cleanup();
		InfraredSensor.Cleanup();
		
	}

	void AutonomousPeriodic(void) 
	{
		
		m_autoPeriodicLoops++;
		//MyAutoRobot->Update(GetClock());
	}

	
	void TeleopPeriodic(void) 
	{
		// increment the number of teleop periodic loops completed
		m_telePeriodicLoops++;
		
		//Feed joystick inputs to each subsystem here
        MyKicker.Kick(GameStick->GetRawButton(IODefinitions::KICKER_PREPAREKICK), 
        GameStick->GetRawButton(IODefinitions::KICKER_TRIGGERKICK));
        
		MyRobot.DriveRobot(DriveStick->GetY(),DriveStick->GetRawAxis(4));
		
		Arm.UpperVerticalPos(GameStick);
		Arm.LowerVerticalPos(GameStick);
		Arm.Extend(GameStick);
		Arm.BeltEnable(GameStick);

		
	} // TeleopPeriodic(void)
			
};

START_ROBOT_CLASS(EntropyRobot2014);
