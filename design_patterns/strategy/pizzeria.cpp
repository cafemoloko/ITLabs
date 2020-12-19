#include "pizzeria.h"

Pizzeria::Pizzeria()
{

}
Pizzeria::Pizzeria(PizzaFilter *pizzaValidator)
    : validator(pizzaValidator)
{

}

void Pizzeria::addPizza(Pizza const &givenPizza)
{
    if (validator->validate(givenPizza))
    {
        pizzas.push_back(givenPizza);
    }

}

void Pizzeria::showPizzas() const
{
    for(vector<Pizza>::const_iterator i = pizzas.begin(); i != pizzas.end(); ++i)
    {
        cout << i->getPizzaName()<<'\n';
    }

}
