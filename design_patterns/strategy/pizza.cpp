#include "pizza.h"

Pizza::Pizza()
{

}

Pizza::Pizza(unsigned int ingNumb, string name, bool isForVegetarians, bool hasSeaFood, unsigned int newPizzaSize)
    : numberOfIngredients(ingNumb), nameOfPizza(name), isVege(isForVegetarians), seaFood(hasSeaFood), pizzaSize(newPizzaSize)
{

}

unsigned int Pizza::getIngNumber() const
{
    return numberOfIngredients;
}

string Pizza::getPizzaName() const
{
    return nameOfPizza;
}

bool Pizza::getIsVege() const
{
   return isVege;
}

bool Pizza::getSeaFood() const
{
    return seaFood;
}

unsigned int Pizza::getPizzaSize() const
{
    return pizzaSize;
}
