/*
 * BMS_Receiver_Core.h
 *
 *  Created on: Jun 20, 2021
 *      Author: ahk7kor
 */

#ifndef RECEIVER_BMS_RECEIVER_CORE_H_
#define RECEIVER_BMS_RECEIVER_CORE_H_

#include <iostream>
#include <unordered_map>
#include "boost/property_tree/json_parser.hpp"

#include "BatteryParameter_DataHandler.h"

class BMSReceiver
{
public :
	BMSReceiver();
	~BMSReceiver();

	bool insertParamsData_JSON_String(std::string paramsData);
	std::string get_ParamsDataStats_String();

	static boost::property_tree::ptree convert_String_To_JSon(std::string data);

private:

	void initializeParametersMap(boost::property_tree::ptree paramsData);
	void updateParametersMap_withData(boost::property_tree::ptree paramsData);
	bool isInput_in_JSONFormat(std::string data);

	std::unordered_map<std::string,ParameterData_Handler*> parametersMap;

};









#endif /* RECEIVER_BMS_RECEIVER_CORE_H_ */
