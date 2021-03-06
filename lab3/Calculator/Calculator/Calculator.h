#pragma once
#include <map>
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class CValueHolder;
class CFunction;
class CVariable;

class CCalculator
{
public:
	std::shared_ptr<CValueHolder> GetElement(const std::string & ident) const;
	void AddVariable(const std::string & name, const double & value = NAN);
	void AddVariable(const std::string & name, const std::string & ident);
	void AddFunction(const std::string & name, const std::string & firstArgumentIdent, const std::string & secondArgumentIdent = "", const std::string & operation = "+");
	void SetVariableValue(const std::string & name, const double & value = NAN);
	void SetVariableValue(const std::string & name, const std::string & ident);
	std::map<std::string, std::shared_ptr<CVariable>> GetVars() const;
	std::map<std::string, std::shared_ptr<CFunction>> GetFuncs() const;
	~CCalculator();
private:
	std::vector<std::shared_ptr<CVariable>> CCalculator::GetDependentVariablesList(const std::string & ident) const;
	void CheckIdentifire(const std::string & ident);
	std::map<std::string, std::shared_ptr<CFunction>> m_functions;
	std::map<std::string, std::shared_ptr<CVariable>> m_variables;
}; 