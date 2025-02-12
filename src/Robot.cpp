#include "WPILib.h"
#include "Mouse.h"
#include <unistd.h>

/**
 * This is a demo program showing the use of the RobotDrive class.
 * The SampleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're inexperienced,
 * don't. Unless you know what you are doing, complex code will be much more difficult under
 * this system. Use IterativeRobot or Command-Based instead if you're new.
 */
class Robot: public SampleRobot
{
	Mouse micky;
	int counterX = 0, counterY = 0;
public:
	Robot() :
			micky()
	{}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
	}

	/**
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl()
	{
		while (IsOperatorControl() && IsEnabled())
		{
			SmartDashboard::PutNumber("UID", getuid());
			if (micky.Update() == -1) {
				counterY=0;
				counterX=0;
				SmartDashboard::PutNumber("CM X Value", -1);
				SmartDashboard::PutNumber("CM Y Value", -1);
				SmartDashboard::PutNumber("X Value", -1);
				SmartDashboard::PutNumber("Y Value", -1);
			}
			else {
				counterY+=micky.GetY();
				counterX+=micky.GetX();
				SmartDashboard::PutNumber("CM X Value", counterX/800); //1200 ~ 1CM
				SmartDashboard::PutNumber("CM Y Value", counterY/2000);//20000 ~ 1CM
				SmartDashboard::PutNumber("X Value", micky.GetX());
				SmartDashboard::PutNumber("Y Value", micky.GetY());
			}
			Wait(0.005);				// wait for a motor update time
		}
	}

	/**
	 * Runs during test mode
	 */
	void Test()
	{
	}
};

START_ROBOT_CLASS(Robot);
