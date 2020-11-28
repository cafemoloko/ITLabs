#include <QCoreApplication>
#include <iostream>

using namespace std;


class Wheels{
    public:
    virtual Wheels* getWheels() = 0;
    virtual ~Wheels(){}
};
class Seats{
    public:
    virtual Seats* getSeats() = 0;
    virtual ~Seats(){}
};
class Engine{
    public:
    virtual Engine* getEngine() = 0;
    virtual ~Engine(){}
};

class Alarm{
public:
    virtual Alarm* getAlarm() = 0;
    virtual ~Alarm(){}
};


class VWWheels: public Wheels{
    private:
    string name;
public:
    VWWheels(){name = "Wheels for VW";}
    Wheels* getWheels()
    {
        cout<<"Adding: "+name<<endl;
        return new VWWheels();
    }
};

class VWSeats: public Seats{
    private:
    string name;
public:
    VWSeats(){name = "Seats for VW";}
    Seats* getSeats()
    {
        cout<<"Adding: "+name<<endl;
        return new VWSeats();
    }
};
class VWEngine: public Engine{
    private:
    string name;
public:
    VWEngine(){name = "Engine for VW";}
    Engine* getEngine()
    {
        cout<<"Adding: "+name<<endl;
        return new VWEngine();
    }
};

class VWAlarm: public Alarm{
    private:
    string name;
public:
    VWAlarm(){name = "Alarm for VW";}
    Alarm* getAlarm()
    {
        cout<<"Adding: "+name<<endl;
        return new VWAlarm();
    }
};

class FiatWheels: public Wheels{
    private:
    string name;
public:
    FiatWheels(){name = "Wheels for Fiat";}
    Wheels* getWheels()
    {
        cout<<"Adding: "+name<<endl;
        return new FiatWheels();
    }
};

class FiatSeats: public Seats{
    private:
    string name;
public:
    FiatSeats(){name = "Seats for Fiat";}
    Seats* getSeats()
    {
        cout<<"Adding: "+name<<endl;
        return new FiatSeats();
    }
};

class FiatEngine: public Engine{
    private:
    string name;
public:
    FiatEngine(){name = "Engine for Fiat";}
    Engine* getEngine()
    {
        cout<<"Adding: "+name<<endl;
        return new FiatEngine();
    }
};

class FiatAlarm: public Alarm{
    private:
    string name;
public:
    FiatAlarm(){name = "Alarm for Fiat";}
    Alarm* getAlarm()
    {
        cout<<"Adding: "+name<<endl;
        return new FiatAlarm();
    }
};

class SkodaWheels: public Wheels{
    private:
    string name;
public:
    SkodaWheels(){name = "Wheels for Skoda";}
    Wheels* getWheels()
    {
        cout<<"Adding: "+name<<endl;
        return new SkodaWheels();
    }
};

class SkodaSeats: public Seats{
    private:
    string name;
public:
    SkodaSeats(){name = "Seats for Skoda";}
    Seats* getSeats()
    {
        cout<<"Adding: "+name<<endl;
        return new SkodaSeats();
    }
};

class SkodaEngine: public Engine{
    private:
    string name;
public:
    SkodaEngine(){name = "Engine for Skoda";}
    Engine* getEngine()
    {
        cout<<"Adding: "+name<<endl;
        return new SkodaEngine();
    }
};

class SkodaAlarm: public Alarm{
    private:
    string name;
public:
    SkodaAlarm(){name = "Alarm for Skoda";}
    Alarm* getAlarm()
    {
        cout<<"Adding: "+name<<endl;
        return new SkodaAlarm();
    }
};

class CarFactory{
    public:
    virtual Wheels* produceWheels() = 0;
    virtual Seats* produceSeats() = 0;
    virtual Engine* produceEngine() = 0;
    virtual Alarm* produceAlarm() = 0;
    virtual ~CarFactory(){}
};

class VWCarFactory : public CarFactory
{
    public:
    Wheels * produceWheels()
    {
        return new VWWheels();
    }
    Seats * produceSeats()
    {
        return new VWSeats();
    }
    Engine * produceEngine()
    {
        return new VWEngine();
    }
    Alarm * produceAlarm()
    {
        return new VWAlarm();
    }

};

class FiatCarFactory : public CarFactory
{
    public:
    Wheels * produceWheels()
    {
        return new FiatWheels();
    }
    Seats * produceSeats()
    {
        return new FiatSeats();
    }
    Engine * produceEngine()
    {
        return new FiatEngine();
    }
    Alarm * produceAlarm()
    {
        return new FiatAlarm();
    }
};

class SkodaCarFactory : public CarFactory
{
    public:
    Wheels * produceWheels()
    {
        return new SkodaWheels();
    }
    Seats * produceSeats()
    {
        return new SkodaSeats();
    }
    Engine * produceEngine()
    {
        return new SkodaEngine();
    }
    Alarm * produceAlarm()
    {
        return new SkodaAlarm();
    }
};

class SomeNewCar
{
    protected:
    Seats* seats, *seats_tmp;
    Wheels* wheels, *wheels_tmp;
    Engine* engine, *engine_tmp;
    Alarm* alarm, *alarm_tmp;

    virtual void assembling() = 0;
    public:
    void selling()
    {
        cout<<"selling..."<<endl;
    }
    virtual ~SomeNewCar(){}
};

class VWNewCar : public SomeNewCar
{
    private:
    VWCarFactory* f;
    protected:
    void assembling()
    {
        seats_tmp = f->produceSeats();
        seats = seats_tmp->getSeats();
        wheels_tmp = f->produceWheels();
        wheels = wheels_tmp->getWheels();
        engine_tmp = f->produceEngine();
        engine = engine_tmp->getEngine();
        alarm_tmp = f->produceAlarm();
        alarm = alarm_tmp->getAlarm();
    }
    public:
    VWNewCar(VWCarFactory* fVW):
        f(fVW)
    {
        assembling();
    }
    ~VWNewCar()
    {
        delete seats; delete seats_tmp;
        delete wheels; delete wheels_tmp;
        delete engine; delete engine_tmp;
        delete alarm; delete alarm_tmp;
        delete f;
    }
};

class FiatNewCar : public SomeNewCar
{
    private:
    FiatCarFactory* f;
    protected:
    void assembling()
    {
        seats_tmp = f->produceSeats();
        seats = seats_tmp->getSeats();
        wheels_tmp = f->produceWheels();
        wheels = wheels_tmp->getWheels();
        engine_tmp = f->produceEngine();
        engine = engine_tmp->getEngine();
        alarm_tmp = f->produceAlarm();
        alarm = alarm_tmp->getAlarm();
    }
    public:
    FiatNewCar(FiatCarFactory* fF):
        f(fF)
    {
        assembling();
    }
    ~FiatNewCar()
    {
        delete seats; delete seats_tmp;
        delete wheels; delete wheels_tmp;
        delete engine; delete engine_tmp;
        delete alarm; delete alarm_tmp;
        delete f;
    }
};

class SkodaNewCar : public SomeNewCar
{
    private:
    SkodaCarFactory* f;
    protected:
    void assembling()
    {
        seats_tmp = f->produceSeats();
        seats = seats_tmp->getSeats();
        wheels_tmp = f->produceWheels();
        wheels = wheels_tmp->getWheels();
        engine_tmp = f->produceEngine();
        engine = engine_tmp->getEngine();
        alarm_tmp = f->produceAlarm();
        alarm = alarm_tmp->getAlarm();
    }
    public:
    SkodaNewCar(SkodaCarFactory* fS):
        f(fS)
    {
        assembling();
    }
    ~SkodaNewCar()
    {
        delete seats; delete seats_tmp;
        delete wheels; delete wheels_tmp;
        delete engine; delete engine_tmp;
        delete alarm; delete alarm_tmp;
        delete f;
    }
};


class CarChooser
{
    private:
    SomeNewCar* assemblyCar(string model)
    {
        SomeNewCar* newCar;
        if("VW" == model)
        {
            newCar = new VWNewCar(new VWCarFactory());
        }
        else if("Fiat" == model)
        {
            newCar = new FiatNewCar(new FiatCarFactory());
        }
        else
        {
            newCar = new SkodaNewCar(new SkodaCarFactory());
        }
        return newCar;
    }
    public:
    SomeNewCar* getCar(string model)
    {
        SomeNewCar* newCar = assemblyCar(model);
        newCar->selling();
        return newCar;
    }
};





int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CarChooser* carChooser = new CarChooser();

    SomeNewCar* vw = carChooser->getCar("VW");
    SomeNewCar* fiat = carChooser->getCar("Fiat");
    SomeNewCar* skoda = carChooser->getCar("Skoda");

    delete carChooser;
    delete vw;
    delete fiat;
    delete skoda;

    return a.exec();
}
