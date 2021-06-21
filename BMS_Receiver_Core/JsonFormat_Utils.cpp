
#include <iostream>


#include "JsonFormat_Utils.h"

bool isInput_in_JSONFormat(std::string data)
{
	try
	{
		std::stringstream input;
		input.str(data);
		boost::property_tree::ptree Jsondata;
		boost::property_tree::json_parser::read_json(input,Jsondata);
	}
	catch (const boost::property_tree::ptree_error &e)
	{
		std::cout<<"ERROR : bad data"<<std::endl;
		return false;
	}
	return true;
}


boost::property_tree::ptree convert_String_To_JSon(std::string data)
{
	std::stringstream input;
	input.str(data);
	boost::property_tree::ptree Jsondata;
	boost::property_tree::json_parser::read_json(input,Jsondata);

	return Jsondata;
}

boost::property_tree::ptree get_Json_From_String(std::string data)
{
	std::stringstream input;
	input.str(data);
	boost::property_tree::ptree Jsondata;
	boost::property_tree::json_parser::read_json(input,Jsondata);

	return Jsondata;
}
