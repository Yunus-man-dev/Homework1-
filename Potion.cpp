// Yunus Emre Sayılır Cs201 Section 2 22402272
#include "Potion.h"
using namespace std;

        
        Potion::Potion(const Potion& copy){

            potionName = copy.potionName;
            
            strength = copy.getStrength();

        }


        Potion::Potion(std::string potion, int stre){

            potionName = potion;
            strength = stre;

        }

        std::string Potion::getName() const
        {
            return potionName;
        }

       int Potion::getStrength()const{
            return strength;
        }








