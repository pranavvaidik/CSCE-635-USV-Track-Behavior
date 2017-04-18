#include <iostream>
#include <SerialStream.h>
#include "serial_communication.h"
#include<math.h>
using namespace std;
using namespace LibSerial;

int main() {
	serial_comm test;
	//test.send_char('a');
	test.fotokite_yaw(0.2f);
	int x,y;
	int avgx , avgy;
	x = 10;
	y = 10;
	avgx=0;
	avgy=0;
	//change x and y to keep origin at centre
	x = x - avgx;
	y = y - avgy;

	//convert to r and theta;
	float r = pow(x*x+y*y,0.5);
	float theta = tan(float(y/x));
	//cout<<r<<" "<<theta;

	return 0;
}
