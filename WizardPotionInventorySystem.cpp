// Yunus Emre Sayılır Cs201 Section 2 22402272
#include "WizardPotionInventorySystem.h"
using namespace std;


 WizardPotionInventorySystem::WizardPotionInventorySystem (){
    students = nullptr;
    capacity = 0;
    realSize = 0;
 }

WizardPotionInventorySystem& WizardPotionInventorySystem::operator=(WizardPotionInventorySystem& assignment){
    if(this == &assignment){
        return *this;
    }
    Student** stus = nullptr;
    if(assignment.realSize!= 0){
        // yeni bir student** olustur, assignmenti kopyala
        stus = new Student*[assignment.realSize];
        for(int i = 0; i<assignment.realSize; i++){

            stus[i] = new Student(*(assignment.students[i]));

        }
    }
    // deletion of existing data
    for(int i = 0; i < realSize; i++){
        delete students[i];

    }
    delete [] students;

    this->capacity = assignment.capacity;

    this-> students = stus;
    return *this;
}

 WizardPotionInventorySystem::~WizardPotionInventorySystem (){
     for (int i = 0; i < realSize; i++) {
                delete students[i]; // Önce ogrencileri Heap'ten sil
            }

            delete[] students;     // Sonra adres listesini sil
 } 

 WizardPotionInventorySystem::WizardPotionInventorySystem(const WizardPotionInventorySystem& copy){

    

    if(copy.realSize != 0){

        students = new Student*[copy.realSize];
        for(int i = 0; i<copy.realSize; i++){
            
            students[i] = new Student( *(copy.students[i]));

        }


    }
    else{
        students = nullptr;
    }
    capacity = copy.capacity;
    realSize = copy.realSize;

 }


void WizardPotionInventorySystem::brewPotion ( const std::string studentName ,const std::string potionName ,const int strength ){
    int x = 0;
    int& index = x;
    bool keep = checkStudentName(studentName,index);

    if(keep){
        int y = 0;
        int& place = y;
        // if there are not a potion name in that student
        if(!students[index]->checkPotion(potionName,place)){

            students[index]->increaseArr(potionName,strength);
            cout<<"Brewed potion "<<potionName<<" for student wizard "<<studentName<<"."<<endl;
        }
        else{
            // ayni isimde bir potion varsa
            cout<<"Cannot brew potion. Potion already exists in potion inventory of "<<studentName<<"."<<endl;
        }
    }
    else{
    // oyle bir ogrenic yoksa
        cout<<"Cannot brew potion. Student wizard "<<studentName<<" does not exist."<<endl;
    }


}

//should check whether there are another student name with given name
bool WizardPotionInventorySystem::checkStudentName(const string name, int& index)const{
            
            bool found = false;

            for(int i = 0; i<realSize; i++){
                if(students[i]->getName() == name){
                    found = true;
                    index = i;
                }
            }
            return found;

}

void WizardPotionInventorySystem::discardPotion ( const std::string studentName ,const std::string potionName ){
    int x = 0;
    int& index = x;
    bool keep = checkStudentName(studentName,index);
    // ogrenci varsa
    if(keep){
        int y = 0;
        int& place = y;
        // ogrencinin the oyle bir potionu varsa
        if(students[index]->checkPotion(potionName,place)){

          students[index]->decreaseArr(potionName,place);
            cout<<"Discarded potion "<<potionName<<" from student wizard "<<studentName<<"."<<endl;
        }
        else{
            //oyle bir potion yoksa
             cout<<"Cannot discard potion. Potion does not exist in potion inventory of "<<studentName<<"."<<endl;
        }

    }
    else{
        //oyle bir ogrenci yoksa
        cout<<"Cannot discard potion. Student wizard "<<studentName<<" does not exist."<<endl;
    }
}

void WizardPotionInventorySystem::transferPotion ( const std::string potionName ,const std::string fromStudent ,const std::string toStudent ){
    int x = 0;
    int& fromIndex = x;

    int y = 0;
    int& toIndex = y;

    bool keep = checkStudentName(fromStudent,fromIndex) && checkStudentName(toStudent,toIndex);
    // if both students are existing
    if(keep){
        int a = 0;
        int& potin = a;
         // if there exist a potion
        if(students[fromIndex]->checkPotion(potionName,potin)){
           
             // if toStudent NOT have potion
            if(!students[toIndex]->checkPotion(potionName,potin)){
                //////////////////////////////////////////

                int streng = students[fromIndex]->getPotions()[potin]->getStrength(); ////// MUST BE UPDATED, I HARD CODED THE STRENGTH
                students[toIndex]->increaseArr(potionName,streng);
                students[fromIndex]->decreaseArr(potionName, potin);
                ////////////////////////////////////////// MUST BE UPDATED, I HARD CODED THE STRENGTH

                cout<<"Transferred potion "<<potionName<<" from "<<fromStudent<<" to "<<toStudent<<"."<<endl;
            }
            else{
                cout<<"Cannot transfer potion. Potion already exists in potion inventory of "<<toStudent<<"."<<endl;
            }
        }
        else{
            cout<<"Cannot transfer potion. Potion does not exist in potion inventory of "<<fromStudent<<"."<<endl;
        }

    }
    else{
        cout<<"Cannot transfer potion. One or both student wizards do not exist."<<endl;
    }
}



void WizardPotionInventorySystem::addStudentWizard ( const std::string name , const std::string house ){
    //check if name is already given
    int a = 0;
    int& b = a;
    // eger oyle bir ogrenci varsa
    if(checkStudentName(name,b)){

        //eklemeyeceksin, hata mesaji vereceksin
        // cout<<"Cannot add student wizard. Student wizard "<<name<<" already exists."<<endl;
    }
    // eger oyle bir ogrenci yoksa
    else{
        if(realSize == capacity){
             increaseArr(name,house);
        }
        // eger henuz capacitye ulasmadiysak
        else{
            Student* add = new Student(name, house);
            students[realSize] = add;
            realSize++;
        }
      
       
        // cout<<"Added student wizard "<<name<<"."<<endl;
    }

}


 void WizardPotionInventorySystem::removeStudentWizard ( const std::string name ){

    //check whether the student exoist
    int a = 0;
    int& index = a;
    bool keep = checkStudentName(name,index);
    //eger varsa
    if(keep){

        // if(capacity == 1){

        // }

        // yeni array olustur, capacity-1 boyutunda
        //  indexe kadar olan kismi gecir
        // index+1 den baslatip kalani da gecir
        // delete students[index]
        //  delete[] students
        //  capacity--;
        // students = temp;
        decreaseArr(name,index);

        // mesaji yayinla
        cout<<"Removed student wizard "<<name<<"."<<endl;
    }
    else{
        //hata mesajini yayinla
        cout<<"Cannot remove student wizard. Student wizard "<<name<<" does not exist."<<endl;
    }


 }
 
void WizardPotionInventorySystem::increaseArr(const std::string studentName, const std::string house){


    
            
            Student** temp =new Student*[2*capacity];
            Student* added = new Student(studentName,house);
           

            if(students != nullptr){

                for(int i = 0; i<capacity; i++){
                    temp[i] = students[i];
                }

                temp[capacity] = added;
                delete[] students;
                capacity = 2* capacity;
                realSize++;
                
            }
            else{
                
                temp[0] = added;
                capacity = 1;
                realSize = 1;
            }
            students = temp;
           
        
       
 }


 void WizardPotionInventorySystem::decreaseArr(std::string studentName, const int index){


    // if( realSize == 1){
    //     delete students[0];
    //     delete[] students;
    //     students = nullptr;
    //     capacity--;
    // }
    // else{

        // delete the index
        delete students[index];

        // swap it with the last one
        
        
        students[index] = students[realSize-1];
        students[realSize-1] = nullptr;

        // realSize--;
        realSize--;



        // Student** tempt = new Student*[capacity-1];

        
        // // indexe kadar olan yer icin
        // for(int i = 0; i<index; i++){
        //     tempt[i] = students[i];
                
    
        // }   
                
        // // ardindan yeni bir for, bu sefer index+1 den baslayip size e kadar git
                
        // for(int i = index+1; i<capacity; i++){
                    
        //     tempt[i-1] =students[i];
                
        // }
                
        // delete students[index];
                
        // delete[] students;
                
                
        // students = tempt;
            
        // capacity--;
    // }
    

 }


// SHOW FUNCTIONS
 void WizardPotionInventorySystem::showAllStudentWizards()const{
    cout<<"Student wizards in the system:"<<endl;
    if(realSize == 0){
        cout<<"None"<<endl;
    }
    else{
        //burda isimleri alphabetic olarak yazman lazim, ama simdilik normal yazalim calisiyor m
        
        Student** sortedStudents = new Student*[realSize];
        for (int i = 0; i < realSize; i++) {
            sortedStudents[i] = students[i];
        }

        // // 2. Selection Sort Algoritması
        // for (int i = 0; i < capacity - 1; i++) {
        //     int minIdx = i;
        //     for (int j = i + 1; j < capacity; j++) {
        //         // String karşılaştırması: Alfabetik olarak daha önce mi?
        //         if (sortedStudents[j]->getName() < sortedStudents[minIdx]->getName()) {
        //             minIdx = j;
        //         }
        //      }

        //     // Pointer'ların yerini değiştir (Swap)
        //     Student* temp = sortedStudents[i];
        //     sortedStudents[i] = sortedStudents[minIdx];
        //     sortedStudents[minIdx] = temp;
        // }   
        
        mergeSort(0,realSize-1,sortedStudents);
        // Yazdirma

        // ne lazim?
        // Harry , House : Gryffindor , 1 potion (s), 6 total strength .
       
        for(int i =0; i<realSize; i++){
            string name = sortedStudents[i]->getName();
            string house = sortedStudents[i]->getHouse();
            int potionNumb = sortedStudents[i]->getSize();
            int totalStreng =  sortedStudents[i]->countTotalStrength();

            // cout<<name<<", House: "<<house<<", "<<potionNumb<<" potion(s), "<<totalStreng<<" total strength."<<endl;
        }
        delete[] sortedStudents;
    }
 }


/*

Student wizard :
Neville , House : Gryffindor , 2 potion (s), 5 total strength .
Potions :
Polyjuice Potion , strength 1.
Healing Draught , strength 4.

*/
void WizardPotionInventorySystem::showStudentWizard ( const std::string name ) const {
    int a = 0;
    int& index = a;
    //check if student exist
    if(checkStudentName(name,index)){
        //if exist
        string sname = students[index]->getName();
        string house = students[index]->getHouse();
        int potionNumb = students[index]->getSize();
        int totalStreng =  students[index]->countTotalStrength();
        cout<<"Student wizard:"<<endl;
        cout<<sname<<", House: "<<house<<", "<<potionNumb<<" potion(s), "<<totalStreng<<" total strength."<<endl;
        cout<<"Potions:"<<endl;
        //name + strength
        for(int i = 0; i<potionNumb; i++){
            string potionName = students[index]->getPotions()[i]->getName();
            int potionStreng = students[index]->getPotions()[i]->getStrength();
            cout<<potionName<<", strength "<<potionStreng<<"."<<endl;
        }

    }
    else{
        cout<<"Student wizard "<<name<<" does not exist."<<endl;
    }

}


void WizardPotionInventorySystem::showPotion ( const std::string potionName ) const {
    
    // kac tane studentte o potionun oldugunu bul = siz
    int a =0;
    int& b = a;
    int count = 0;
    for(int i = 0; i<realSize; i++){
        if(students[i]->checkPotion(potionName,b)){
            count++;
        }
    }

    // 0 sa bir hata mesaji yayinlanir
    if(count == 0){
        cout<<"Potion "<<potionName<<" does not exist."<<endl;
    }
    else{

        // ardindan new Student*[siz] olustur
        Student** stu = new Student*[count];
        int holder = 0;

        // tekrar kac tane studentin o potionun oldugunu bul, ama bu sefer bu arraye ekle
        for(int i = 0; i<realSize; i++){
            if(students[i]->checkPotion(potionName,b)){
            stu[holder] = students[i];
            holder++;
            }

        }
        // sortla arrayi
        for (int i = 0; i < count - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < count; j++) {
                // String karşılaştırması: Alfabetik olarak daha önce mi?
                if (stu[j]->getName() < stu[minIdx]->getName()) {
                    minIdx = j;
                }
             }

            // Pointer'ların yerini değiştir (Swap)
            Student* temp = stu[i];
            stu[i] = stu[minIdx];
            stu[minIdx] = temp;
        }   

          // goster arrayi
          cout<<"Potion \""<<potionName<<"\" found in "<<count<<" student wizard(s):"<<endl;
          for(int i = 0; i<count; i++){
            int def = 0;
            int& defin = def;
            stu[i]->checkPotion(potionName,defin);
            int streng = stu[i]->getPotions()[defin]->getStrength();
            cout<<i+1<<". "<<stu[i]->getName()<<", strength "<<streng<<"."<<endl;
          }
        /*
        Potion " Healing Draught " found in 3 student wizard (s):
        1. Draco , strength 5.
        2. Harry , strength 4.
        3. Luna , strength 10.
        */

        delete[]stu;
    }
    
    // silmeyi unutma arrayi

}

void WizardPotionInventorySystem::mergeSort(int first, int last,Student** student)const{

    if(first == last ){
        return;
    }
   
    // divide
    int divide = (first +last)/2;
    mergeSort(first,divide,student);
    mergeSort(divide+1,last,student);
    // divide the parts by half

    //conquer

    // sort each half//

    //combine

    // combine the sorted two parts of the array, and return
    merge(first,divide,last,student);
    return;


}
void WizardPotionInventorySystem::merge(int first, int divide, int last, Student** student)const{

    // first array
    int size1 = divide-first+1;//3
    Student** fir = new Student* [size1];
    
    for(int i = 0; i<size1; i++){
        fir[i] = student[i+first];

    }

    // second array
    int size2 = last-divide;
    Student** ls = new Student* [size2];
    for(int i = 0; i<size2; i++){
        ls[i] = student[i+divide+1];
    }

    // combine
    int indx = first;
    int indxFirst = 0;
    int indxSecond = 0;

    while(indxFirst < size1 && indxSecond < size2){
        if(fir[indxFirst]->getName() < ls[indxSecond]->getName()){
            student[indx]  = fir[indxFirst];
            indx++;
            indxFirst++;
        }
       
        else{
            student[indx]  = ls[indxSecond];
            indx++;
            indxSecond++;
        }


    }
    if(indxFirst == size1){
        //first array finished first
        while(indxSecond < size2){
             student[indx]  = ls[indxSecond];
            indx++;
            indxSecond++;
        }
    }
    else{
        while(indxFirst < size1){

            student[indx]  = fir[indxFirst];
            indx++;
            indxFirst++;

        }
       
    }
    
    delete [] fir;
    delete [] ls;






}
