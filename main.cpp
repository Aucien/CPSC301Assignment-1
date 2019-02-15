#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct PERSON{
    char Name[22];
    float Balance;
};

void FindRichest(vector<PERSON> list, int size){
    string Richest = list[0].Name;
    int price = list[0].Balance;
    for(int x = 1; x < size; x++){
        if(price < list[x].Balance){
            Richest = list[x].Name;
            price = list[x].Balance;
        }
    }
    cout << "The customer with maximum balance is " << Richest << endl;
}

void NewCopy(vector<PERSON> list, int size){
    string text = "data.txt";
    ofstream file;
    file.open(text);
    cout << "Press any number then enter" << endl;
    for (int x = 0; x < size; x++){
        file << list[x].Name << " " << list[x].Balance << endl;
        cin >> ws;
    }
    cout << "Everything is updated!!" << endl;
    file.close();
}

void Deposit(string customer, vector<PERSON> list, int size){
    float amount = 0;
    for(int x = 0; x < size; x++){
        if (list[x].Name == customer){
            cout << customer << ", how much wold you like to deposit? ";
            cin >> amount;
            list[x].Balance += amount;
            cout << "Now your new balance is " << list[x].Balance << endl;
            NewCopy(list, size);
            return;
        }
        else if(x == size){
            cout << "Could not find name closing program" << endl;
        }
    }
    return;
}

int main() {
    vector<PERSON> list;
    ifstream file;
    file.open("data.txt");
    if(!file){
        cout << "File failed" << endl;
        cout << "Closing Program" << endl;
        return 0;
    }
    string firstname;
    string lastname;
    string fullname;
    string ws;
    PERSON people;
    double price;
    if(file){
        while(file >> firstname >> lastname >> price){
       
        //cout << firstname << " " << lastname << " " << price << endl;
        fullname = firstname + " " + lastname;
        strcpy(people.Name, fullname.c_str());
        people.Balance = price;
        list.push_back(people);
        }
    }
    file.close();
    for (int x = 0; x < list.size(); x++){
        cout << list[x].Name << " " << list[x].Balance << endl;
    }
    FindRichest(list,list.size());
    string CustomerName;
    cout << "Enter your full name to deposit money: ";
    getline(cin, CustomerName);
    Deposit(CustomerName, list,list.size());
    return 0;
}