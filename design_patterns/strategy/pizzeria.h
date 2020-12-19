#ifndef PIZZERIA_H
#define PIZZERIA_H

#include <string>
#include <iostream>
#include <vector>

#include "pizza.h"
#include "PizzaValidator.h"

using namespace std;

class Pizzeria
{
    PizzaFilter* validator;
    vector<Pizza> pizzas;
public:
    Pizzeria();
    Pizzeria(PizzaFilter *pizzaValidator);
    void addPizza(Pizza const &givenPizza);
    void showPizzas() const;
};

#endif // PIZZERIA_H
