#include <iostream>
#include <SerialStream.h>
#include "serial_communication.h"
#include<math.h>
#include<string.h>
using namespace std;
using namespace LibSerial;

int main() {
	serial_comm test;
	//test.send_char('a');
	test.serial_comm_initialize();
	cout<<"line passed";
	string val;
	//test.gimbal_pitch(0.1);

	while(1){
		cout<<"enter command : ";
		getline(cin,val);
		test.send_serial_command(val);
	}

	cout<<"done";
	return 0;
}
