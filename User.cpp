#include <iostream>
#include <string>
using namespace std;

class User {
    private:
    string name;
    int id ;
    int age;
    public:

    void setName(string n){
        name =n;
    }
    string getName(){
        return name;
    }
    void setId(int d){
        id =d;
    }
    int getId(){
        return id;
    }
    void setAge(int a){
        age =a;
    }
    int getage(){
        return age;
    }
};
