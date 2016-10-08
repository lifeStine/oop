#include "stdafx.h"
#include "replace_utils.h"

bool CheckArgumentCount(int argumentCount)
{
	if (argumentCount != 3)
	{
		std::cout << "Invalid argument count" << std::endl;
	}
	return argumentCount == 3;
}

bool CheckReplacingString(const std::string & str)
{
	if (str == "")
	{
		std::cout << "Replacing string can not be empty" << std::endl;
	}
	return str != "";
}

std::string FindAndReplace(const std::string & subject, const std::string & search, const std::string & replace)
{
	std::string result;
	std::string window = "";
	for (auto ch : subject)
	{
		window += ch;
		if (window.size() == search.size())
		{
			result += window == search ? replace : window;
			window = "";
		}
	}
	result += window;
	return result;
}