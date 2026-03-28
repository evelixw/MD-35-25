#pragma once

#include "IDeliveryStrategy.h"

class GroundDelivery : public IDeliveryStrategy
{
public:
    float calculateCost(float weight, float distance) override
    {
        return (distance * 2.5f);
    }
};