#pragma once
#include <vector>
#include <memory>
#include "Valuabal.h"
#include "constants.h"

class CFunction;

class CVariable : public Valuabal
{
public:
	CVariable() = default;
	void SetValue(double value);
	void AppendDependentFunctions(std::shared_ptr<CFunction> function);
private:
	std::vector<std::shared_ptr<CFunction>> m_dependentFunctions;
};