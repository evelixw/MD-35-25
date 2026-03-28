#pragma once

#include "IDeliveryStrategy.h"

class AirDelivery : public IDeliveryStrategy
{
public:
    float calculateCost(float weight, float distance) override
    {
        return (weight * 0.5f) + (distance * 5.0f);
    }
};