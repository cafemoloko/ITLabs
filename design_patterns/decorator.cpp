/* Napisz program tworzący kawę za pomocą wzorca dekorator:

- Klasa bazowa „Napoj”, pochodne Kawa, Espresso oraz „SkladnikDekorator”,
- Dodatki: mleko, czekolada, bita smietana, mocno palona, bezkofeinowa,
- Program powinien wypisywać typ kawy, dodatki oraz cenę. */

#include <iostream>
#include <string>
using namespace std;

// Base beverage
class Beverage {
    protected:
    string beverageType;
    int value;

    public:
    Beverage(){
        beverageType = "Base beverage";
        value = 0;
    }

    virtual~Beverage(){}

    virtual string getInfo(){
        return beverageType;
    }

    virtual int price(){
        return value;
    }
};


// Abstract decorator
class Decorator : public Beverage {
    public:
    virtual string getInfo(){
        return " ";
    }
};

// Beverage Types
class Coffee : public Beverage {
    public:
    Coffee() : Beverage(){
        beverageType = "Coffee";
        value = 5;
    }
};


class Espresso : public Beverage {
    public:
    Espresso() : Beverage() {
        beverageType = "Espresso";
        value = 4;
    }
};


// Extras: mleko, czekolada, bita smietana, mocno palona, bezkofeinowa
class RoastedCoffee : public Decorator {
    Beverage *b;
    int roastedCoffeePrice = 2;

    public:
    RoastedCoffee(Beverage *drink):Decorator(){b = drink;}
    string getInfo(){return b->getInfo()+ " + roasted coffee";}
    int price(){return b->price()+roastedCoffeePrice;}

};


class DecaffeinatedCoffee : public Decorator {
    Beverage *b;
    int decaffeinatedCoffeePrice = 2;

    public:
    DecaffeinatedCoffee(Beverage *drink):Decorator(){b = drink;}
    string getInfo(){return b->getInfo()+ " + decaffeinated coffee";}
    int price(){return b->price()+decaffeinatedCoffeePrice;}

};


class Milk : public Decorator {
    Beverage *b;
    int milkPrice = 1;

    public:
    Milk(Beverage *drink):Decorator(){b = drink;}
    string getInfo(){return b->getInfo()+ " + milk";}
    int price(){return b->price()+milkPrice;}

};


class Chocolate : public Decorator {
    Beverage *b;
    int chocolatePrice = 2;

    public:
    Chocolate(Beverage *drink):Decorator(){b = drink;}
    string getInfo(){return b->getInfo()+ " + chocolate";}
    int price(){return b->price()+chocolatePrice;}

};


class WhippedCream : public Decorator {
    Beverage *b;
    int whippedCreamPrice = 4;

    public:
    WhippedCream(Beverage *drink):Decorator(){b = drink;}
    string getInfo(){return b->getInfo()+ " + whipped cream";}
    int price(){return b->price()+whippedCreamPrice;}

};


int main(){
    Beverage *coffee = new Coffee();
    Beverage *espresso = new Espresso();

    cout<<"Basic beverages: " <<coffee->getInfo()<<", "<<espresso->getInfo()<<endl<<endl;

    cout<<"Monday Mornings Coffee"<<endl;
    Beverage *mondayMornings = new RoastedCoffee(new RoastedCoffee(new Espresso())); //double roasted for extra flavour
    cout<<mondayMornings->getInfo()<<" "<<endl;
    cout<<"PRICE: "<<mondayMornings->price()<<endl<<endl;

    cout<<"Lazy Sunday Coffee"<<endl;
    Beverage *sundayCoffee = new DecaffeinatedCoffee(new Milk(new WhippedCream(new Coffee())));
    cout<<sundayCoffee->getInfo()<<" "<<endl;
    cout<<"PRICE: "<<mondayMornings->price()<<endl;


}






