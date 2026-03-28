#pragma once

#include <memory> 

#include "IDeliveryStrategy.h"

class DeliveryContext
{
public:
    void setStrategy(std::unique_ptr<IDeliveryStrategy> newStrategy)
    {
        strategy = std::move(newStrategy);
    }

    float calculate(float weight, float distance)
    {
        if (!strategy)
        {
            return 0.0f;
        }
        return strategy->calculateCost(weight, distance);
    }

private:
    std::unique_ptr<IDeliveryStrategy> strategy;
};