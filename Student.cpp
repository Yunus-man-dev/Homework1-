// Yunus Emre Sayılır Cs201 Section 2 22402272
#include "Student.h"
using namespace std;




        Student::Student(const std::string sname, const std::string shouse){
            name = sname;
            house = shouse;
            potions = nullptr;
            size = 0;

        }


        Student& Student::operator= (const Student& copy){

            if (this == &copy) {
                return *this;
            }
            this->name = copy.name;
            this->house = copy.house;
            

            Potion** pot = nullptr;

            if(copy.size != 0){

                pot = new Potion*[copy.size];

                for(int i = 0; i<copy.size; i++){

                   
                    pot[i] =  new Potion(*(copy.potions[i]));

                }

            }
            
            for(int i = 0; i<size; i++){
               delete this->potions[i];
            }
            delete[] this->potions;

            this->size= copy.size;
            this->potions = pot;

            return *this;

        }


        Student::Student(const Student& copy){

            name = copy.name;

            size = copy.size;

            house = copy.house;

            if(size != 0){

                potions = new Potion* [size];

                for(int i = 0; i<size; i++){
                    

                    potions[i] = new Potion( *(copy.potions[i]));

                }

            }
            else{
                potions = nullptr;
            }
            


        }

        
        Student::Student(){

            potions = nullptr;
            size = 0;
        }

        Student::~Student() {
            for (int i = 0; i < size; i++) {
                delete potions[i]; // Önce iksirleri Heap'ten sil
            }

            delete[] potions;     // Sonra adres listesini sil
        }

        std::string Student::getName(){
            return name;
        }

        int Student::getSize(){

            return size;
        }

        Potion** Student::getPotions() const { return potions; }

        std::string Student::getHouse(){ return house;}

        int Student::countTotalStrength(){

            int count = 0;
            for(int i = 0 ; i<size; i++){
                count += potions[i]->getStrength();
            }
            return count;
        }

        bool Student::checkPotion(std::string potionName, int& index){

            //returns true if there is a potion named as given string
            bool found = false;

            for(int i = 0; i<size; i++){
                if(potions[i]->getName() == potionName){
                    found = true;
                    index = i;
                }
            }
            return found;

        }


        // we need to call it after we call checkforpotion method, to ensure there are no 
        // same name with given potionName
        void Student::increaseArr(const std::string potionName, const int strength){
            
            Potion** temp =new Potion*[size+1];
            Potion* added = new Potion(potionName,strength);
           

            if(potions != nullptr){

                for(int i = 0; i<size; i++){
                    temp[i] = potions[i];
                }

                temp[size] = added;
                delete[] potions;
                
            }
            else{
                
                temp[0] = added;

            }
            potions = temp;
            size++;
        
        }



         // we need to call it after we call checkforpotion method, to ensure there is a 
        // same name with given potionName
        void Student::decreaseArr(std::string potionName, const int index){
            // Nasil size kucultturulecek?
            // size -1 olan yeni bir array olustur (Potion** tempt = new Potion*[size-1])

            if(size == 1){
                delete potions[0];
                delete[] potions;
                potions = nullptr;
            }
            else{

                Potion** tempt = new Potion*[size-1];
                // indexe kadar olan yer icin
                for(int i = 0; i<index; i++){
                    tempt[i] = potions[i];
                }   
                // ardindan yeni bir for, bu sefer index+1 den baslayip size e kadar git
                for(int i = index+1; i<size; i++){
                    tempt[i-1] = potions[i];
                }
                delete potions[index];
                delete[] potions;
                
                potions = tempt;
            }
            size--;
        }



        








        // bazi metodlarda arrayin boyutunu degistirmemiz gerektiginde kullanmamiz gereken metodlar
        // yeni array olustur, yeni size ile
        // eski arraydekileri buraya at.
        // eski arrayi destructor veya delete[] kullanarak sil.
        // en son pointeri yeni arraya goster






        /*

        addStudent 

            students arrayindeki tum studentleri gez
                name ile uyusan varsa bool u false yap
                donguden cik
            
            if bool 
                 
                size+1 olan yeni bir array olustur
                eski arrayin tum elemanlarini yenisine aktar
                en son da da yeni bir student olustur
                son yere bu studenti ekle
                eski arrayi sil (delete[])
                asil arrayi gosteren pointeri bu yeni arraye bagla





            else 

                Display the error message
            

        
        
        
        
        
        */



        /*
        
            removeStudent / discardPotion

            arrayi gez ve o seyi bul
                buldum
                    bool = true
                    index = ...

                if bool (buldusan)

                    yeni bir array olustur, size-1 olan
                    o yere gelinceye kadar olan elemanlari yeni arraya gecir

                    o yere gelince onu atla
                    kalanini yeni arraya gecir

                    indexteki studenti uygun sekilde sil
                    eski arrayi delete[]
                    size i guncelle
                    pointeri yeni arraye bagla

        
                bulamadim
                    error message yayinla

        
        
        */



