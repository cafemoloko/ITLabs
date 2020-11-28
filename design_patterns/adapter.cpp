#include <QCoreApplication>
#include <iostream>

using namespace std;

class Animal
{
    public:
    virtual void giveVoice() = 0;
    virtual void doSomething() = 0;
    virtual void sleep() = 0;
    virtual void eat() = 0;
    virtual void run() = 0;
    virtual ~Animal(){}
};

class Wolf : public Animal
{
    public:
    void giveVoice(){ cout << "Wolf gives voice"<< endl;}
    void doSomething(){ cout << "Wolf does something"<< endl;}
    void sleep(){cout <<"Wolf sleeps"<<endl;}
    void eat(){cout<<"Wolf eats"<<endl;}
    void run(){cout<<"Wolf runs"<<endl;}
};

//zewnetrzna biblioteka
class Cat
{
    public:
    void catGivesVoice(){cout <<"Cat gives voice"<< endl;}
    void catDoesSomething(){cout << "Cat does something"<< endl;}
    void catRuns(){ cout<<"Cat runs"<< endl; }
};

//adapter
class CatAnimalAdapter : private Cat, public Animal
{
    public:
    void giveVoice(){catGivesVoice();}
    void doSomething(){catDoesSomething();}
    void sleep(){};
    void eat(){};
    void run(){catRuns();}

};



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Animal* pAnimal = new Wolf();
    pAnimal->giveVoice();
    pAnimal->doSomething();
    //new methods
    pAnimal->sleep();
    pAnimal->eat();
    pAnimal->run();

    Animal *pAnimal2 = new CatAnimalAdapter();
    pAnimal2->giveVoice();
    pAnimal2->doSomething();
    pAnimal2->run();

    delete pAnimal;
    delete pAnimal2;

    return a.exec();
}
