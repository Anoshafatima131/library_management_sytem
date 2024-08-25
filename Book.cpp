#include <iostream>
#include <string>


using namespace std;
class Book {
    private:

    string name;
    int price;
    string author;
    int edition;
    public:
    void setName(string n){
        name =n;
    }
    string getName(){
        return name;
    }
     void setAuthor(string n){
        author =n;
    }
    string getName(){
        return author;
    }
    void setEdition(int e){
        edition =e;
    }
    int getId(){
        return edition;
    }
    void setPrice(int p){
        price =p;
    }
    int getPrice(){
        return edition;
    }


};