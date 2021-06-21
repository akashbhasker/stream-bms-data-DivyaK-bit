/*
 * ParameterData_StatsCompute.cpp
 *
 *  Created on: Jun 20, 2021
 *      Author: ahk7kor
 */

#include "ParameterData_StatsCompute.h"

ParameterData_Statistics::ParameterData_Statistics(unsigned int bufferSize)
: windowSize(bufferSize)
, runningTotal(0.0)
, maxVal(0.0)
, minVal(-1)
{

}

ParameterData_Statistics::~ParameterData_Statistics()
{
}

void ParameterData_Statistics::insert(double inputValue)
{
	updateBuffer(inputValue);
	updateMin(inputValue);
	updateMax(inputValue);
	updateRunningTotal(inputValue);
}

void ParameterData_Statistics::updateBuffer(double inputValue)
{
	/*check if buffer is full*/
	if (buffer.size() == windowSize)
	{
		runningTotal -= buffer.front(); /*subtract front value from running total*/
		buffer.pop();                   /*delete value from front of std::queue*/
	}

	buffer.push(inputValue);    /*add new value*/
}

void ParameterData_Statistics::updateMin(double inputValue)
{
	if(inputValue < minVal || minVal == -1)
	{
		minVal = inputValue;   /*update min value*/
	}
}

void ParameterData_Statistics::updateMax(double inputValue)
{
	if(inputValue > maxVal)
	{
		maxVal = inputValue;   /*update max value*/
	}
}

void ParameterData_Statistics::updateRunningTotal(double inputValue)
{
	runningTotal += inputValue; /*update running total*/
}

double ParameterData_Statistics::getCurrentValue()
{
	return buffer.back();
}

double ParameterData_Statistics::getRunningAvg()
{
	return static_cast<double>(runningTotal / buffer.size());
}

double ParameterData_Statistics::getMaxVal()
{
	return maxVal;
}

double ParameterData_Statistics::getMinVal()
{
	return minVal;
}



