//
//  main.cpp
//  Problem Set B: Barbeque
//
//  Created by Angeline Indahsi on 10/25/16.
//  Copyright © 2016 Angeline Indahsi. All rights reserved.
//

#include <iostream>
using namespace std;

class Barbeque
{
private:
    string my_Brand;
    string my_Model;
    bool coal;
    bool lit;
    bool cooking;
public:
    Barbeque(string my_brand, string my_model);
    void loadCoals();
    void light();
    void cook();
    void reset();
    bool hasCoals();
    bool isLit();
    bool isCooking();
};

Barbeque::Barbeque (string my_brand, string my_model)
{
    this->my_Brand = my_brand;
    this->my_Model = my_model;
}
void Barbeque::loadCoals()
{
    cout <<"Loading " << my_Brand << " " << my_Model << " with coals" << endl;
}

bool Barbeque::hasCoals() {
    string coall;
    cout << "Does the grill has coals in it?" << endl;
    cin >> coall;
    if (coall == "yes")
    {
        coal = true;
        return coal;
    }
    else
    {
        cout << "Fill it with coal first!" << endl;
        coal = false;
        return coal;
    }
}


void Barbeque::light()
{
    if(coal)
        cout << "Start lighting the grill" << endl;
    else
        cout << "Fill the coal first!" << endl;
    
}

bool Barbeque::isLit()
{
    string litt;
    cout << "Is the bbq lit?" << endl;
    cin>> litt;
    if (litt == "yes")
    {
        lit = true;
        return lit;
    }
    else
        {
            cout << "You need to re-light the grill" << endl;
            lit = false;
            return lit;
        }
}

void Barbeque::cook()
{
    if(lit)
        cout << "Start cooking!" << endl;
    else
        cout << "You can't cook!" << endl;
}

bool Barbeque::isCooking()
{
    string cookk;
    cout << "Is the food cooking?" << endl;
    cin >> cookk;
    if (cookk =="yes")
    {
        cooking = true;
        return cooking;
    }
    else
    {
        cout << "You can't cook!" << endl;
    }
    return false;
}

void Barbeque::reset()
{
    lit = false;
    coal = false;
    cooking = false;
}

int main ()
{
    Barbeque bbq = Barbeque("Coleman", "Grill 101A");
    bool restart;
    do
    {
        restart = false;
        bbq.loadCoals();
        if (bbq.hasCoals())
        {
            bbq.light();
            if (bbq.isLit())
            {
                bbq.cook();
            }
            else
            {
                cout << "Error in logic." << endl;
                restart = true;
                bbq.reset();
                cout << "Let's make some errors..." << endl;
                bbq.light();
                bbq.cook();
                bbq.loadCoals();
                bbq.cook();
            }
        }
            else
            {
                restart = true;
                bbq.reset();
                cout << "Let's make some errors..." << endl;
                bbq.light();
                bbq.cook();
                bbq.loadCoals();
                bbq.cook();
            }
        }
    
    while (restart == true);
    return 0;
}
