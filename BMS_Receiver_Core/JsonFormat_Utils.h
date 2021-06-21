/*
 * JsonFormat_Utils.h
 *
 *  Created on: Jun 21, 2021
 *      Author: ahk7kor
 */

#ifndef BMS_RECEIVER_CORE_JSONFORMAT_UTILS_H_
#define BMS_RECEIVER_CORE_JSONFORMAT_UTILS_H_

#include "boost/property_tree/json_parser.hpp"

bool isInput_in_JSONFormat(std::string data);
boost::property_tree::ptree convert_String_To_JSon(std::string data);
boost::property_tree::ptree get_Json_From_String(std::string data);


#endif /* BMS_RECEIVER_CORE_JSONFORMAT_UTILS_H_ */
