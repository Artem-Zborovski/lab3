#include <iostream>
#include <string>

using namespace std;

class AbstractOBJ {
protected:
    const int Id;
    const string Name;
    AbstractOBJ() : Id(Count++), Name("Unnamed") {}

public:
    AbstractOBJ(string aName) : Id(Count++), Name(aName) {}
    virtual string GetName()  = 0;
    virtual int GetId()  = 0;
    virtual void Show(ostream&)  = 0;
    virtual ~AbstractOBJ() {}
    static int Count;

};

int AbstractOBJ::Count = 0;

class FloatingCraft : public AbstractOBJ {
protected:
    string Brand;
    int NumberOfSails;
    float Length;
    int NumberofOars;

public:
    FloatingCraft(string aName, string brand, int sails,int oars, float length)
        : AbstractOBJ(aName), Brand(brand), NumberOfSails(sails),NumberofOars(oars), Length(length) {
    }

    string GetName() override { return Name; }
    int GetId()  override { return Id; }

    void Show(ostream& os) override {
        os << "Name: " << GetName() << endl << "Brand: " << Brand << endl << "Number of sails: " << NumberOfSails << endl<<"Number of oars: "<<NumberofOars<<endl << "Length: " << Length << endl;
    }
};

class MotorBoat : public FloatingCraft {
    int EnginePower;

public:
    MotorBoat(string aName, string brand, int enginePower,float length)
        : FloatingCraft(aName,brand,0,0,length),EnginePower(enginePower) {}

    void Show(ostream& os)  override {
        FloatingCraft::Show(os);
        os << "Engine Power: " << EnginePower << endl;
    }
};

int main() {
    FloatingCraft* boat1 = new FloatingCraft("Boat1", "Audi", 2,3, 10.5);
    MotorBoat* boat2 = new MotorBoat("Boat2", "Mercedes", 500,12.7);
   

    boat1->Show(cout);
    cout << endl;
    boat2->Show(cout);
    cout << endl;

    cout << "Number of objects: ";
    cout << AbstractOBJ::Count << endl;

    delete boat1;
    delete boat2;

    return 0;
}