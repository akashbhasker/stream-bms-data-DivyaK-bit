/**************************************************************************************
* @file        : BMS_Receiver_Main.cpp
* @brief       :
*
**************************************************************************************/

#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <unordered_map>

#include "../BMS_Receiver_Core/BMS_Receiver_Core.h"

using namespace std;

#define START_CONDITION "START"
#define STOP_CONDITION  "STOP"

#define SUCCESS 0

/**
 * Description     : Method to check and handle console input
 *                   Condition to start                  : console input as "START"
 *                   Condition to stop                   : console input as "STOP"
 *
 */
bool checkFor_Start()
{
	std::string input;

	while(true)
	{
		std::getline(cin,input);
		if( input.compare(START_CONDITION) == SUCCESS )
		{
			return true;
		}
	}
}

void printToConsole(std::string data)
{
	cout<<data;
}

void receiveParametersData()
{
	std::string input;
	BMSReceiver receiverObj;

	while(true)
	{
		std::getline(cin,input);
		if( input.compare(STOP_CONDITION) == SUCCESS )
		{
			return ;
		}

		receiverObj.insertParamsData_JSON_String(input);
		printToConsole(receiverObj.get_ParamsDataStats_String());
	}
}

/**
 * Description     : Main Method
 *
 */
int main()
{
	bool startReceiver = checkFor_Start();
	if(startReceiver)
	{
		std::thread inp(receiveParametersData);

		inp.join();
	}

	return 0;

}
