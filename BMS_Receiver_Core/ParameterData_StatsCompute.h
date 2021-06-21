/*
 * ParameterData_StatsCompute.h
 *
 *  Created on: Jun 20, 2021
 *      Author: ahk7kor
 */

#ifndef RECEIVER_PARAMETERDATA_STATSCOMPUTE_H_
#define RECEIVER_PARAMETERDATA_STATSCOMPUTE_H_

#include <iostream>
#include <queue>

class ParameterData_Statistics
{
public :
	ParameterData_Statistics(unsigned int bufferSize);
	virtual ~ParameterData_Statistics();

	virtual void insert(double inputValue);
	double getCurrentValue();
	double getRunningAvg();
	double getMaxVal();
	double getMinVal();

private :

	void updateMin(double inputValue);
	void updateMax(double inputValue);
	void updateRunningTotal(double inputValue);
	void updateBuffer(double inputValue);

	unsigned int windowSize;
	double runningTotal;
	double maxVal;
	double minVal;
	std::queue<double> buffer;
};



#endif /* RECEIVER_PARAMETERDATA_STATSCOMPUTE_H_ */
