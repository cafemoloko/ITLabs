#include <QCoreApplication>
#include <iostream>
#include <vector>

#include "pizza.h"
#include "PizzaValidator.h"
#include "pizzeria.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Pizza *margherita = new Pizza(3, "Margherita", true, false, 30);
    Pizza *havaii = new Pizza(4, "Havaii", false, false, 30);
    Pizza *havaiiSpeciale = new Pizza(4, "HavaiiSpeciale", true, true, 45);
    Pizza *seafoodSpeciale = new Pizza(4, "Sea Food Speciale", true, true, 45);

    PizzaSizeFilter sizeFilter;
    VegePizzaFilter vegeFilter;
    SeaFoodPizzaFilter seafoodFilter;

    Pizzeria bigPizzasPizzeria(&sizeFilter);
    Pizzeria vegePizzeria(&vegeFilter);
    Pizzeria seafoodPizzeria(&seafoodFilter);

    bigPizzasPizzeria.addPizza(*margherita);
    bigPizzasPizzeria.addPizza(*havaii);
    bigPizzasPizzeria.addPizza(*havaiiSpeciale);
    bigPizzasPizzeria.addPizza(*seafoodSpeciale);

    vegePizzeria.addPizza(*margherita);
    vegePizzeria.addPizza(*havaii);
    vegePizzeria.addPizza(*havaiiSpeciale);
    vegePizzeria.addPizza(*seafoodSpeciale);

    seafoodPizzeria.addPizza(*margherita);
    seafoodPizzeria.addPizza(*havaii);
    seafoodPizzeria.addPizza(*havaiiSpeciale);
    seafoodPizzeria.addPizza(*seafoodSpeciale);


    cout << "Big pizza: \n";
    bigPizzasPizzeria.showPizzas();

    cout << "Vege pizza:\n";
    vegePizzeria.showPizzas();

    cout << "Sea Food pizza:\n";
    seafoodPizzeria.showPizzas();

    delete margherita;
    delete havaii;
    delete havaiiSpeciale;
    delete seafoodSpeciale;

    return a.exec();
}
