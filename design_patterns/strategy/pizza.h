#ifndef PIZZA_H
#define PIZZA_H
#include <string>

using namespace std;

class Pizza
{
public:
    Pizza();
    Pizza(unsigned int ingNumb, string name, bool isForVegetarians, bool seaFood, unsigned int newPizzaSize);

    unsigned int getIngNumber() const;
    string getPizzaName() const;
    bool getIsVege() const;
    bool getSeaFood() const;
    unsigned int getPizzaSize() const;

private:
    unsigned int numberOfIngredients;
    string nameOfPizza;
    bool isVege;
    bool seaFood;
    unsigned int pizzaSize;
};

#endif // PIZZA_H
