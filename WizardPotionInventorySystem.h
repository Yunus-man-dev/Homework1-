// Yunus Emre Sayılır Cs201 Section 2 22402272
#ifndef WIZARD_SYSTEM_H
#define WIZARD_SYSTEM_H
#include <iostream>
#include "Student.h"
class WizardPotionInventorySystem {

 public :
   // implemented, not tested
 WizardPotionInventorySystem ();
   // implemented, not tested
 ~ WizardPotionInventorySystem ();
    // implemented, not tested

WizardPotionInventorySystem(const WizardPotionInventorySystem& copy);

WizardPotionInventorySystem& operator=(WizardPotionInventorySystem& assignment);


WizardPotionInventorySystem& operator= (const WizardPotionInventorySystem& copy);


 void addStudentWizard ( const std::string name , const std::string house );
 
 //implemented, not tested
 void removeStudentWizard ( const std::string name );

 // implemented, not tested
 void brewPotion ( const std::string studentName ,
 const std::string potionName ,
 const int strength );

 //implemented, not tested
 void discardPotion ( const std::string studentName ,
 const std::string potionName );

 //implemented, not tested
 void transferPotion ( const std::string potionName ,
 const std::string fromStudent ,
 const std::string toStudent );

  //implemented, not tested
 void showAllStudentWizards () const ;

 //implemented, not tested
 void showStudentWizard ( const std::string name ) const ;


 void showPotion ( const std::string potionName ) const ;

    // destroyer ekle

 private :

    Student** students;
     
    int capacity;

    //should check whether there are another student name with given name
    bool checkStudentName(const string name, int& index)const;

    void increaseArr(const std::string studentName, const std::string house);

    void decreaseArr(std::string studentName, const int index);

 };
 #endif