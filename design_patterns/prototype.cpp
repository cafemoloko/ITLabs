#include <iostream>
#include <map>
#include <string>
//#include <cstdint>

using namespace std;

enum PROCESSOR_TYPE
{
  RYZEN,
  ATHLON,
  PHENOM
};

/**
 * Processor Prototype
 */

class Processor
{
  public :

    Processor() {}

    virtual ~Processor() {}

    virtual Processor* Clone() const= 0;

    virtual void GetInfo() const= 0;
};

/**
 * Concrete VW Prototype
 */

class VWCar : public Car
{
  private :
    string m_VWName;

    uint32_t m_VWNumber;

  public :

    VWCar(const string& newCarName, uint32_t newCarNo)
      : Car(),
        m_VWName(newCarName),
        m_VWNumber(newCarNo)
    {
    }

    VWCar(const VWCar& newVWCar)
      : Car()
    {
      m_VWName = newVWCar.m_VWName;
      m_VWNumber = newVWCar.m_VWNumber;
    }

    ~VWCar() {}

    VWCar* Clone() const
    {
      return new VWCar(*this);
    }

    void GetInfo() const
    {
      cout << "VW " << endl
        << "Name  : " << m_VWName << endl
        << "Number: " << m_VWNumber << endl << endl;
    }
};


/**
 * Concrete Fiat Prototype
 */

class FiatCar : public Car
{
  private :
    string m_FiatName;

    uint32_t m_FiatNumber;

  public :
    FiatCar(const string& newCarName, uint32_t newCarNo)
      : Car(),
        m_FiatName(newCarName),
        m_FiatNumber(newCarNo)
    {
    }

    FiatCar(const FiatCar& newFiatCar)
      : Car()
    {
      m_FiatName = newFiatCar.m_FiatName;
      m_FiatNumber = newFiatCar.m_FiatNumber;
    }

    ~FiatCar() {}

    FiatCar* Clone() const
    {
      return new FiatCar(*this);
    }

    void GetInfo() const
    {
      cout << "Fiat " << endl
        << "Name  : " << m_FiatName << endl
        << "Number: " << m_FiatNumber << endl << endl;
    }
};


/**
 * Concrete Opel Prototype
 */

class OpelCar : public Car
{
  private :
    string m_OpelName;

    uint32_t m_OpelNumber;

  public :
    OpelCar(const string& newCarName, uint32_t newCarNo)
      : Car(),
        m_OpelName(newCarName),
        m_OpelNumber(newCarNo)
    {
    }

    OpelCar(const OpelCar& newOpelCar)
      : Car()
    {
      m_OpelName = newOpelCar.m_OpelName;
      m_OpelNumber = newOpelCar.m_OpelNumber;
    }

    ~OpelCar() {}

    Car* Clone() const
    {
      return new OpelCar(*this);
    }

    void GetInfo() const
    {
      cout << "Opel " << endl
        << "Name : " << m_OpelName << endl
        << "Number  : " << m_OpelNumber << endl << endl ;
    }
};


/**
 * CarFactory - client
 */

class CarFactory
{
  private :
    map<CAR_TYPE, Car* > m_allCarsList;

  public :
    CarFactory()
    {
      m_allCarsList[VW]    = new VWCar("Passat", 55665);
      m_allCarsList[FIAT]   = new FiatCar("Tipo", 67534);
      m_allCarsList[OPEL] = new OpelCar("Astra", 97543);
    }

    ~CarFactory()
    {
      delete m_allCarsList[VW];
      delete m_allCarsList[FIAT];
      delete m_allCarsList[OPEL];
    }

    Car* CreateCar(CAR_TYPE enType)
    {
      return m_allCarsList[enType]->Clone();
    }
};

int main()
{
  CarFactory* myCarFactory = new CarFactory();

  Car* someCar;
  someCar = myCarFactory->CreateCar(VW);
  someCar->GetInfo();
  delete someCar;

  someCar = myCarFactory->CreateCar(FIAT);
  someCar->GetInfo();
  delete someCar;

  someCar = myCarFactory->CreateCar(OPEL);
  someCar->GetInfo();
  delete someCar;

  delete myCarFactory;
  return 0;
}
