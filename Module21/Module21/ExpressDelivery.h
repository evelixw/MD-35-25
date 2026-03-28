#pragma once

#include "IDeliveryStrategy.h"

class ExpressDelivery : public IDeliveryStrategy
{
public:
    float calculateCost(float weight, float distance) override
    {
        return (weight * 2.5f) + (distance * 7.0f);
    }
};