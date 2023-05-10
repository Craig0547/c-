#include <iostream>

using namespace std;
class Animal{
    public:

    //attributes
    string species, name;
    int age;
    //methods
    void AddAnimal()
    {
        cout<<"Input the animal's species, name and age:\n";
        cin>>species>>name>>age;
    }
    void Speak()
    {
        if(species=="Cat")cout<<"MEOW!\n";
        else if(species=="Goat")cout<<"BAAA!\n";
        else if(species=="Cow")cout<<"MOO!\n";
        else cout<<"Invalid Species. Maybe even a UFO\n";
    }
};

int main()
{
    cout<<"Add animal\n";
    Animal a1;
    a1.AddAnimal();
    a1.Speak();
    Animal a2;
    a2.AddAnimal();
    a2.Speak();
    return 0;
}
