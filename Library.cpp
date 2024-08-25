#include <iostream>
#include <fstream>
#include <sstream>
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

    void Display(){
    cout<<"name: "<<name<<endl;
    cout<<"id: "<<id<<endl;
    cout<<"age: "<<age<<endl;
   
   }
};


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
    string getAuthor(){
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


    void Display(){
    
    ifstream MyReadFile("C:\\Users\\HP 250 G6\\Desktop\\Library\\library.txt");

    if (!MyReadFile.is_open()) {
        cerr << "Unable to open file." << endl;
    }

    string line;
   
    getline(MyReadFile, line, ',');

    while (getline(MyReadFile, line)) {
       
        stringstream ss(line);

        string bookname, author, edition, price;
       
        getline(ss, bookname, '\t');
        getline(ss, author, '\t');
        getline(ss, edition, '\t');
        getline(ss, price, '\t');

        //Output the parsed values
        cout << "Bookname: " << bookname << endl;
        cout << "Author: " << author << endl;
        cout << "Edition: " << edition << endl;
        cout << "Price: " << price << endl;
        cout << endl;
    }

    MyReadFile.close();
    

};




    void addBook(){
        
        cout <<"Enter the name of the book"<<endl;
        getline (cin, name);

        cout <<"Enter the  author name of the book"<<endl;
        getline (cin, author);

        cout <<"Enter the edition of the book"<<endl;
        cin>>edition;

        cout <<"Enter the price of the book"<<endl;
        cin>>price;

    
        string book = "\n"+ name + "\t"+ author + "\t" + to_string(edition) + "\t" + to_string(price); 
        ofstream MyFile;
        MyFile.open("C:\\Users\\HP 250 G6\\Desktop\\Library\\library.txt", std::ios_base::app);

  // Write to the file
       MyFile << book;

  // Close the file
        MyFile.close();
        cout<<" your book has been sucssessfully  added"<<endl;
   }
    

};




class Library{

    public:

     void DisplayBooks(){

    
    ifstream MyReadFile;
     MyReadFile.open("C:\\Users\\HP 250 G6\\Desktop\\Library\\library.txt");

    if (!MyReadFile.is_open()) {
        cerr << "Unable to open file." << endl;
    }

    std::string line;

    while (getline(MyReadFile, line)) {
        std::stringstream ss(line);
        std::string book, author;
        int edition;
        double price;

        // Extract all attributes separated by tabs
        getline(ss, book, '\t');
        getline(ss, author, '\t');
        ss >> edition;
        ss.ignore(); // Ignore the tab or space after edition
        ss >> price;

        // Display all attributes
        std::cout << "Book Name: " << book << "\n"
                  << "Author: " << author << "\n"
                  << "Edition: " << edition << "\n"
                  << "Price: $" << price << "\n\n";
    }

    MyReadFile.close();
   

}


void deleteBook() {
    string deleteBook;
    cout << "Enter the name of the book which you want to delete: ";
    cin.ignore();
    getline(cin, deleteBook);

    ifstream MyReadFile("C:\\Users\\HP 250 G6\\Desktop\\Library\\library.txt");
    ofstream temp("C:\\Users\\HP 250 G6\\Desktop\\Library\\temp.txt");

    if (!MyReadFile || !temp) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(MyReadFile, line)) {
        stringstream ss(line);
        string book, author;
       

        // Check if the current line's book name matches the book to delete
        if (book != deleteBook) {
            temp << line << endl; // Write the line to the temp file if it doesn't match
        } else {
            found = true;
        }
    }

    MyReadFile.close();
    temp.close();

    if (found) {
        // Replace the original file with the temp file
        remove("C:\\Users\\HP 250 G6\\Desktop\\Library\\library.txt");
        rename("C:\\Users\\HP 250 G6\\Desktop\\Library\\temp.txt", "C:\\Users\\HP 250 G6\\Desktop\\Library\\library.txt");
        cout << "Your book has been successfully deleted." << endl;
    } else {
        remove("C:\\Users\\HP 250 G6\\Desktop\\Library\\temp.txt");
        cout << "Book not found in the library." << endl;
    }
}


void editBook(){
    string editBook;
    string newName;
    
   
    cout<<"Enter the name of the book which you want to edit:"<<endl;
    // cin.ignore();
    getline(cin, editBook);

    cout<<"Enter the new name of the book:"<<endl;
    getline(cin, newName);

    ifstream MyReadFile("C:\\Users\\HP 250 G6\\Desktop\\Library\\library.txt");
    ofstream temp("C:\\Users\\HP 250 G6\\Desktop\\Library\\temp.txt");

    if (!MyReadFile || !temp) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(MyReadFile, line)) {
        stringstream ss(line);
        string book, author;
        
        int edition;
        int price;
        getline(ss, book, '\t');
        getline(ss, author, '\t');
        ss >> edition;
        ss.ignore(); 
        ss >> price;

        
        // cout<<editBook +" " + book + +" " + newName<<endl;
      
        // Check if the current line's book name matches the book to delete
        if (book == editBook) {
            found=true;
            temp << newName + "\t"+ author + "\t" + to_string(edition) + "\t" + to_string(price)+ "\n";
           
        } 
        
        else {
            temp << line << endl; // Write the line as is if it doesn't match
        }
    }

  
  
    MyReadFile.close();
    temp.close();

    if (found) {
        // Replace the original file with the temp file
        remove("C:\\Users\\HP 250 G6\\Desktop\\Library\\library.txt");
        rename("C:\\Users\\HP 250 G6\\Desktop\\Library\\temp.txt", "C:\\Users\\HP 250 G6\\Desktop\\Library\\library.txt");
        cout << "Your book has been successfully edited." << endl;
    } else {
        remove("C:\\Users\\HP 250 G6\\Desktop\\Library\\temp.txt");
        cout << "Book not found in the library." << endl;
    }
}

void borrowBook(){
    string userName;
    string bookName;

    cout<<"Enter your Name:"<<endl;
    cin>>userName;

     cout<<"Enter the name of book which you want to borrow:"<<endl;
     cin>>bookName;

     ofstream outputFile("C:\\Users\\HP 250 G6\\Desktop\\Library\\borrow.txt");

    // Check if the file was successfully opened
    if (!outputFile) {
        cout << "Error opening file!" << endl;
        return; // Exit the program with an error code
    }

    // Write data to the file
    outputFile << userName << " " << bookName << endl;

   

    // Close the file after writing
    outputFile.close();



}


   void purchaseBook(){
    string userName;
    string bookName;

    cout<<"Enter your Name:"<<endl;
    cin>>userName;

     cout<<"Enter the name of book which you want to borrow:"<<endl;
     cin>>bookName;

     ofstream outputFile("C:\\Users\\HP 250 G6\\Desktop\\Library\\purchase.txt");

    // Check if the file was successfully opened
    if (!outputFile) {
        cout << "Error opening file!" << endl;
        return; // Exit the program with an error code
    }

    // Write data to the file
    outputFile << userName << " " << bookName << endl;

   

    // Close the file after writing
    outputFile.close();



}     
void displayborrowedBooks(){
    ifstream file("C:\\Users\\HP 250 G6\\Desktop\\Library\\Borrow.txt"); // Replace "example.txt" with your file's name

    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    string line;
    while (std::getline(file, line)) {
        cout << line << std::endl; // Display each line from the file
    }

    file.close();
}

void displaypurchasedBooks(){
    ifstream file("C:\\Users\\HP 250 G6\\Desktop\\Library\\Purchase.txt"); // Replace "example.txt" with your file's name

    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }
    string line;
    while (std::getline(file, line)) {
        cout << line << std::endl; // Display each line from the file
    }

    file.close();
}

};



   



int main(){


    
    
int input;
char adminInput;
char userInput;
Book add;
Library lib;
cout<<"Library Management System"<<endl;

cout<<"Enter 1 if you are a Admin \n 2 if you are a user"<<endl;
cin>>input;

if (input== 1){

    menu:
    cout<<"Hello Admin !! "<<endl;
    cout<<"Enter \n 1 if you want to AddBook \n2 if u want to EditBook \n3 if u want to DeleteBook \n4 if wanna view Books   \n5 if wanna view Borrowed Books  \n6 if wanna view Purchased Books \n press q to quit"<<endl;
    cin>>adminInput;
    while(adminInput!= 'q'){
       if(adminInput=='1'){
        add.addBook();
        goto menu;

    }
    else if(adminInput=='2'){
       lib.editBook();
       goto menu;
    }
     else if(adminInput=='3'){
       lib.deleteBook();
       goto menu;
    }
    else if(adminInput=='4'){
        lib.DisplayBooks();
        goto menu;
    }

     else if(adminInput=='5'){
        lib.displayborrowedBooks();
        goto menu;
    }
    else if(adminInput=='6'){
        lib.displaypurchasedBooks();
        goto menu;
    }
    }
    cout << "Exiting the menu. Goodbye!" << endl;
}
else{
    usermenu:
    cout<<"Welcome User!!"<<endl;
     cout<<"Press 1 if u wanna Borrow book \n2 if u wanna purchase book \n3 if u wanna view books \npress q to quit"<<endl;
    cin>>userInput;
     while(userInput!= 'q'){
     
     if(userInput=='1'){
        lib.borrowBook();
        goto usermenu;
    }
    else if(userInput=='2'){
        lib.purchaseBook();
        goto usermenu;
    }
    else if(userInput=='3'){
        lib.DisplayBooks();
        goto usermenu;
    }
     
  
}
cout << "Exiting the menu. Goodbye!" << endl;
}


 return 0; }
 