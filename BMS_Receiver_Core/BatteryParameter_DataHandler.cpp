/*
 * BatteryParameter_DataHandler.cpp
 *
 *  Created on: Jun 21, 2021
 *      Author: ahk7kor
 */


#include "BatteryParameter_DataHandler.h"

ParameterData_Handler::ParameterData_Handler(unsigned int bufferSize)
: ParameterData_Statistics(bufferSize)
{

}

ParameterData_Handler::~ParameterData_Handler()
{

}

void ParameterData_Handler::insert(double inputValue)
{
	ParameterData_Statistics::insert(inputValue);
}


