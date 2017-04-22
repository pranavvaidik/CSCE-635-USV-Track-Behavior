/*
 * serial_communication.h
 *
 *  Created on: Apr 18, 2017
 *      Author: haresh
 */

#ifndef SERIAL_COMMUNICATION_H_
#define SERIAL_COMMUNICATION_H_
#include <iostream>
#include <SerialStream.h>
#include <string>
#include <math.h>
using namespace std;
using namespace LibSerial;

class serial_comm
{
SerialStream serial;
public:
    serial_comm();
    int send_char(char);
    void send_serial_command(string);
    void gimbal_roll(float);
    void gimbal_pitch(float);
    void fotokite_yaw(float);
};

serial_comm::serial_comm()
{
    serial.Open("/dev/ttyACM0");
    serial.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
    serial.SetBaudRate(SerialStreamBuf::BAUD_115200);
    serial.SetNumOfStopBits(1);
    serial.SetFlowControl(SerialStreamBuf::FLOW_CONTROL_NONE);
    serial<<"RemoteControl start";
}

void serial_comm::send_serial_command(string str){
    serial<<str<<endl;
    cout << "command sent: "<< str <<endl;
    return;
}

int serial_comm::send_char(char a){
    serial<<a<<endl;
    return 0;
}

void serial_comm::gimbal_roll(float value)
{
    string serial_command = "GimbalRoll " + to_string(value) + "<CR>";
    send_serial_command(serial_command);
    //serial<<endl;
}
void serial_comm::gimbal_pitch(float value)
{
    string serial_command = "GimbalPitch " + to_string(value) + "<CR>";
    send_serial_command(serial_command);
    //serial<<endl;
}
void serial_comm::fotokite_yaw(float value)
{
     string serial_command = "GimbalYaw " + to_string(value) + "<CR>";
    send_serial_command(serial_command);
    //serial<<endl;
}

#endif /* SERIAL_COMMUNICATION_H_ */

