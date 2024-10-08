#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           Motor2,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           serv3,         tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           serv4,         tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           Motor1,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           serv1,         tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           serv2,         tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int motorspeed;
int motorspeed1;
//^^for motorspeeds^^
bool onoff1;
bool onoff2;
bool onoff3;
//for on/off buttons
bool dwmodsw;
//^^drive mode switch^^
void butmove(int motorvar,int butvar,int motorsp)
//motorsp means motorspeed
//butvar stands for button variable
{
	motor[motorvar]=vexRT[butvar]*motorsp;
}
//^^^turns motor on/off^^^
	//torf stands for true or false
void butspeed(int butvar2, int speed,int motorsp1, bool torf, bool torf1)
{
	if(vexRT[butvar2]==1&&onoff1==torf){
		motorsp1=speed;
		onoff1=torf1;
	}
}
//^^chnages the speed of the motors^^
void servrev(bool torf2,bool torf3)
{
	if(vexRT[Btn8U]==1&&onoff2==torf2)
	{
		motorspeed1=-motorspeed1;
		onoff2=torf3;
	}
}
//^^chnages the diretion the servoes goes with a button^^
void modsw(int mot1,int mot2)
//^^Drive Mode switch^^
{
	if(dwmodsw==false)
		{
		motor[mot1]= vexRT[Ch2];
		motor[mot2]= vexRT[Ch3];
	}
	//^^tank dive^^
	if(dwmodsw==true)
	{
		motor[mot1]=vexRT[Ch4]+vexRT[Ch3];
    motor[mot2]=vexRT[Ch4]-vexRT[Ch3];
  }
}
void butsw(bool torf4, bool torf5)
{
	if(vexRT[Btn8D]==1&&onoff3==torf4)
	{
		motorspeed1=-motorspeed1;
		onoff3=torf5;
	}
}
  //arcarde drive line 53 and 54 code from https://www.vexforum.com/t/robot-c-arcade-drive/43348
task main()
{
	onoff1=false;
	onoff2=false;
	onoff3=false;
	//sets the on/off to be false as the defult when the code first runs
	while(true)
	{
		modsw(leftMotor,rightMotor);
		//changes between tank and arcade drive
		servrev(true,false);
		servrev(false,true);
		//^^chnages the direction of the servos^^
		butsw(true,false);
		butsw(false,true);
		//changes between acade and tank drive with a button toggle swtich
		butspeed(Btn8D,50, motorspeed,true, false);
		butspeed(Btn8D,100,motorspeed,false,true);
		butspeed(Btn8U,50, motorspeed1,true,false);
		butspeed(Btn8U,100,motorspeed1,false,true);
		//^^set the motors speed with a button^^
		butmove(Motor1,Btn5D,motorspeed);
		butmove(Motor1,Btn6U,-motorspeed);
		butmove(Motor2,Btn5U,motorspeed);
		butmove(Motor2,Btn6U,-motorspeed);
		//^^turns motors on/off^^
		butmove(serv1,Btn7R,motorspeed1);
		butmove(serv2,Btn7L,motorspeed1);
		butmove(serv3,Btn8R,motorspeed1);
		butmove(serv4,Btn8L,motorspeed1);
		//^^turns servers on/off^^
	}
}
//end task main
//aurth:@coeevee
//date: 9/26/2024
//version: 2.1
//language: RobotC
//purpose: to control a robot with a controller
//end
