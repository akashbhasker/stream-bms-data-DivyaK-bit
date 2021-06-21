/*
 * BMS_Receiver_Core.cpp
 *
 *  Created on: Jun 20, 2021
 *      Author: ahk7kor
 */

#include <sstream>
#include "boost/property_tree/ptree.hpp"

#include "JsonFormat_Utils.h"
#include "BMS_Receiver_Core.h"

using namespace std;

#define PARAMDATA_BUFFER_SIZE 5


BMSReceiver::BMSReceiver()
{

}

BMSReceiver::~BMSReceiver()
{

}

bool BMSReceiver::insertParamsData_JSON_String(std::string paramsData)
{
	if(isInput_in_JSONFormat(paramsData))
	{
	 boost::property_tree::ptree Jsondata = convert_String_To_JSon(paramsData);
	 updateParametersMap_withData(Jsondata);
	 return true;
	}
	return false;
}

void BMSReceiver::initializeParametersMap(boost::property_tree::ptree paramsData)
{
	for (boost::property_tree::ptree::const_iterator it = paramsData.begin(); it != paramsData.end(); ++it)
	{
		parametersMap[it->first] = new ParameterData_Handler(PARAMDATA_BUFFER_SIZE);
	}
}

void BMSReceiver::updateParametersMap_withData(boost::property_tree::ptree paramsData)
{
	if(parametersMap.empty())
	{
		initializeParametersMap(paramsData);
	}

	for (boost::property_tree::ptree::const_iterator it = paramsData.begin(); it != paramsData.end(); ++it)
	{
		double value = std::stod((it->second).get_value<std::string>());
		parametersMap[it->first]->insert(value);
	}
}

std::string BMSReceiver::get_ParamsDataStats_String()
{
	std::string outputStr;
	std::unordered_map<std::string,ParameterData_Handler*>::iterator it = parametersMap.begin();
	for( ; it != parametersMap.end(); ++it)
	{
		boost::property_tree::ptree Jsondata;

		Jsondata.put("ParameterName", it->first);
		Jsondata.put("Current", it->second->getCurrentValue());
		Jsondata.put("Min", it->second->getMinVal());
		Jsondata.put("Max", it->second->getMaxVal());
		Jsondata.put("Avg", it->second->getRunningAvg());

		stringstream output;
		boost::property_tree::json_parser::write_json(output, Jsondata, false);

		outputStr = outputStr + output.str();
	}
	return outputStr;
}






