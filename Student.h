// Yunus Emre Sayılır Cs201 Section 2 22402272
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Potion.h"

class Student{

    public:

        Student(const std::string sname, const std::string shouse);

        // Copy constructor
        Student(const Student& copy);

        // Assignment operator
        Student& operator=(const Student& copy);


        Student();

        ~Student();

        void increaseArr(const std::string potionName, const int strength);

        std::string getName();

        std::string getHouse();

        int getSize();

        bool checkPotion(std::string potionName, int& index);

        void decreaseArr(std::string potionName, const int index);

        //returns the strength of potion in the index
        // int getStrengthByIndex(const int index);

        Potion** getPotions() const;

        int countTotalStrength();

    private:

        std::string name;

        std::string house;

        Potion** potions;
           
        int size;

       
        // 

       
        // creates an potion object and adds it to the potions array

        // Nasil arttiracak?
        // Potion** temp =new Potion*[size+1]
        // temp[i] = potions[i]
        // temp[size] = o yeni eklenen olacak
        // delete[] potions
        // potions = temp;
        // size++;



        // decreaseArr dan once checkPotionla potion var mi diye kontrol etmen lazim
        // eger varsa decreaseArr cagirrisin ve index olarak da checkten gelen indexi kullanirsin
      
        // Nasil size kucultturulecek?
        // size -1 olan yeni bir array olustur (Potion** tempt = new Potion*[size-1])
        // indexe kadar olan yer icin
        // temp[i] = potions[i]
        //  
        // ardindan yeni bir for, bu sefer index+1 den baslayip size e kadar git
        // tempt[i-1] = potions[i]
        //  delete[] potions
        // size--;
        // potions = tempt;






    // we will need probably resizable arrays




};
#endif