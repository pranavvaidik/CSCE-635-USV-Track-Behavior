/*

 Code to control the camera gimbal pitch and fotokite yaw motion.
 It takes in 4 inputs. x,y coordinate position of EMILY and rx,ry major and minor axes lengths of the ellipse
 The ellipse is assumed to have an origin at the centre (l/2,w/2);
 The control used is a simple proportional controller.
 */
#include "serial_communication.h"
#include<math.h>
#include<iostream>
using namespace std;

class cameracontrol
{
	int l = 1280; // enter length of the image
	int h = 720; // enter height of the image
	int x,y,rx,ry
	serial_comm test2;
	public :
	
	void control(int,int,int,int);
};

void cameracontrol::control(int x, int y, int rx, int ry)
{
	//first change coordinate axis to have (0,0) at center;
	float r,theta;
	x = x - l/2;
	y = h/2 - y;
	rx = rx - l/2;
	ry = ry - h/2;
	// get length value of EMILY from centre
	r = pow((x*x + y*y),0.5);
	theta = atan(y/x);
	float k1 = 0.1;
	float k2 = 0.1;
	float tilt = 0f;
	float pan=0f;
	float val ;

	val = (x*x)/(rx*rx) + (y*y)/(ry*ry);
	if (val>1)
	{
		if (y<0)
		{
			r = -1*r;
		}
		if (theta<0)
		{
			theta = -1*theta;
		}
		//theta in degrees
		float thetad = theta*180/3.14f;
		if (thetad<=45 && thetad>=-45)
		{
			tilt = (1-k1)*theta*0.001;
			test2.fotokite_yaw(tilt);
		}
		else
		{
			pan = (1-k2)*r*0.001;
			test2.gimbal_pitch(pan);
		}
	}
}
