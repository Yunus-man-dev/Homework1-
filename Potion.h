// Yunus Emre Sayılır Cs201 Section 2 22402272
#ifndef POTION_H
#define POTION_H
#include <iostream>
using namespace std;

class Potion{

    public:

        Potion(const Potion& copy);

        Potion(std::string potion, int stre);

        std::string getName() const;

        int getStrength() const ;


    private:

    // For the same student, potion names must be different than each other(case sensitive)
        string potionName;

        int strength;




};
#endif