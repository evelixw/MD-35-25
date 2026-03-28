#include <iostream>

#include "DeliveryContext.h"
#include "GroundDelivery.h"
#include "AirDelivery.h"
#include "ExpressDelivery.h"

int main()
{
    DeliveryContext context;

    float weight = 10.5f;
    float dist = 100.0f;

    context.setStrategy(std::make_unique<GroundDelivery>());
    std::cout << "GroundDelivery cost: " << context.calculate(weight, dist) << std::endl;

    context.setStrategy(std::make_unique<AirDelivery>());
    std::cout << "AirDelivery cost: " << context.calculate(weight, dist) << std::endl;

    context.setStrategy(std::make_unique<ExpressDelivery>());
    std::cout << "ExpressDelivery cost: " << context.calculate(weight, dist) << std::endl;
}