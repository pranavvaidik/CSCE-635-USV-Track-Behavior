/*
 * serial_communication.h
 *
 *  Created on: Apr 18, 2017
 *      Author: Haresh Karnan, Pranav Vaidik Dhulipala
 */

#ifndef SERIAL_COMMUNICATION_H_
#define SERIAL_COMMUNICATION_H_
#include <iostream>
#include <SerialStream.h>
#include <string.h>
#include <math.h>
using namespace std;
using namespace LibSerial;

class serial_comm
{
    SerialStream serial;
    public:
        void serial_comm_initialize();
        int send_char(char);
        void send_serial_command(string);
        void gimbal_pitch_roll(float, float);
        void gimbal_roll(float);
        void gimbal_pitch(float);
        void fotokite_yaw(float);
        void stop_remote_control();
        void stop_camera_movement();
        void close_serial_communication();
};



void serial_comm::serial_comm_initialize()
{
    serial.Open("/dev/ttyACM0");
    serial.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
    serial.SetBaudRate(SerialStreamBuf::BAUD_115200);
    serial.SetNumOfStopBits(1);
    serial.SetFlowControl(SerialStreamBuf::FLOW_CONTROL_NONE);
    
    
    //Sending 5 carriage sequences
    string carriage_sequence = "\r\r\r\r\r";
    serial<< carriage_sequence;
    
    
    //Look for the "nsh>" response from the Ground station
    char ground_station_response[4];
    serial.read(ground_station_response,4);
    
    if (strcmp(ground_station_response,"nsh>"))
    {
        cout<<"connection with Ground Station Established Successfully";
        send_serial_command("Checksum 0");
        send_serial_command("RemoteControl start");
    }
    else
    {
        cout<<"connection failed";
        return;
    }
    
    
}

void serial_comm::send_serial_command(string str){
    serial<<str<<endl;
    cout << "command sent: "<< str <<endl;
    
    int buf_size = 10;
    char ground_station_response[buf_size];
    serial.read(ground_station_response,buf_size);
    
    cout<< ground_station_response << endl;
    
    return;
}

int serial_comm::send_char(char a){
    serial<<a<<endl;
    return 0;
}

void serial_comm::stop_remote_control(){
    send_serial_command("stop");
    return;
}

void serial_comm::gimbal_pitch_roll(float pitch_value, float roll_value)
{
    string serial_command = "Gimbal " + to_string(pitch_value)+ "," + to_string(roll_value) + "<CR>";
    send_serial_command(serial_command);
    //serial<<endl;
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
    //string serial_command = "GimbalYaw " + to_string(value) + "<CR>";
    string serial_command = "Yaw " + to_string(value) + "<CR>";
    send_serial_command(serial_command);
    //serial<<endl;
}

void serial_comm::stop_camera_movement()
{
    gimbal_pitch_roll(0,0);
    fotokite_yaw(0);
    cout<<"camera movement stopped";
    //serial<<endl;
}

void serial_comm::close_serial_communication()
{
    serial.Close();
}

#endif /* SERIAL_COMMUNICATION_H_ */

