#ifndef PIZZAVALIDATOR_H
#define PIZZAVALIDATOR_H
#include "pizza.h"

class PizzaFilter
{
public:
    virtual ~PizzaFilter(){}
    virtual bool validate(Pizza const&) = 0;
};

class PizzaSizeFilter : public PizzaFilter
{
public:
    bool validate(Pizza const& givenPizza)
    {
        return givenPizza.getPizzaSize() > 40;
    }
};

class VegePizzaFilter : public PizzaFilter
{
public:
    bool validate(Pizza const& givenPizza)
    {
        return givenPizza.getIsVege();
    }
};

class SeaFoodPizzaFilter : public PizzaFilter
{
public:
    bool validate(Pizza const& givenPizza)
    {
        return givenPizza.getSeaFood() && givenPizza.getPizzaSize() > 40;
    }
};

#endif // PIZZAVALIDATOR_H
