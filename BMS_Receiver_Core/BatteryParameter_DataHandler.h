/*
 * BatteryParameter_DataHandler.h
 *
 *  Created on: Jun 21, 2021
 *      Author: ahk7kor
 */

#ifndef BATTERYPARAMETER_DATAHANDLER_H_
#define BATTERYPARAMETER_DATAHANDLER_H_

#include "ParameterData_StatsCompute.h"

class ParameterData_Handler : public ParameterData_Statistics
{
public :
	ParameterData_Handler(unsigned int bufferSize);
	virtual ~ParameterData_Handler();

	virtual void insert(double inputValue);
};



#endif /* BATTERYPARAMETER_DATAHANDLER_H_ */
