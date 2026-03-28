#pragma once

class IDeliveryStrategy
{
public:
	virtual ~IDeliveryStrategy() = default;
	virtual	float calculateCost(float weight, float distance) = 0;
};