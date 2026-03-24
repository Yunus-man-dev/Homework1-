// #include WizardPotionInventorySystem.h
#include <chrono>
#include <iostream>
using namespace std;
#include "WizardPotionInventorySystem.h"
int main(){

    WizardPotionInventorySystem sys;
    string student = "Student";

    int arr[] = {500,1000,3000,5000,7500,10000,25000,50000,75000,100000};

    int testCase = 0;
    while(testCase != 10){
        cout<<"Test case "<<testCase<<" is initializing!";
        cout<<endl;
        cout<<endl;

        for(int i = 0; i<arr[testCase]; i++){

            sys.addStudentWizard("Student"+to_string(i),"house"+to_string(i));

        }

        string test = "Student" + to_string(arr[testCase]/2);


        clock_t startTime = clock();

        sys.addStudentWizard("test","House501");

        clock_t endTime = clock();

        double duration1 = 1000 * double( endTime - startTime ) / CLOCKS_PER_SEC;

        cout << "Adding student took  " << duration1 << " milliseconds." << endl;

        cout<<"///////////////////////////////////////////////////////"<<endl;

        cout<<"///////////////////////////////////////////////////////"<<endl;

        clock_t startStudent = clock();

        sys.showStudentWizard(test);

        clock_t endStudent= clock();

        double duration4 = 1000 * double( endStudent - startStudent ) / CLOCKS_PER_SEC;

        cout << "Show of THE STUDENT took " << duration4 << " milliseconds." << endl;

        cout<<"///////////////////////////////////////////////////////"<<endl;

        cout<<"///////////////////////////////////////////////////////"<<endl;



        clock_t startRemove = clock();

        sys.removeStudentWizard(test);

        clock_t endRemove = clock();

        double duration2 = 1000 * double( endRemove- startRemove ) / CLOCKS_PER_SEC;

        cout << "Removement took " << duration2 << " milliseconds." << endl;

        cout<<"///////////////////////////////////////////////////////"<<endl;

        cout<<"///////////////////////////////////////////////////////"<<endl;


        clock_t startShow = clock();

        sys.showAllStudentWizards();

        clock_t endShow= clock();

        double duration3 = 1000 * double( endShow - startShow ) / CLOCKS_PER_SEC;

        cout << "Show of all students took " << duration3 << " milliseconds." << endl;

        cout<<"///////////////////////////////////////////////////////"<<endl;

        cout<<"///////////////////////////////////////////////////////"<<endl;

        cout<<"Test case "<<testCase<<" is finished!";
        cout<<endl;
        cout<<endl;


        testCase++;

    }


}