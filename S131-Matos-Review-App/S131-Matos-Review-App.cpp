// S131-Matos-Review-App.cpp 


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Student.h"

using namespace std;

//Prototypes --------------------------------------------------------
void experiment01();
void experiment02();
void experiment03();

int main()
{
    //experiment01();
    //experiment02();
    experiment03();

    std::cout << "\nAll done!\n";
}

//User-defined methods -----------------------------------------------
void experiment01()
{
    int num = 123;
    cout << "num:  " << num  << endl;
    cout << "&num: " << &num << endl;

    int copy = num;
    cout << "copy: " << copy << endl;

    int* pnum = &num;
    cout << "pnum: " << pnum << endl;

    cout << "*pnum " << *pnum << endl;

    *pnum = 200;
    cout << "num: " << num << endl;

    int* ptr2 = new int(777);
    cout << "ptr2:   " << ptr2 << endl;
    cout << "*ptr2:  " << *ptr2 << endl;
    cout << "&ptr2:  " << &ptr2 << endl;
    
    delete ptr2;
}

//---------------------------------------------------------------------
void experiment02()
{

    //Testing - Reading disk data 
    //each record consists of: ID, Name, {courses}*, #

    ifstream infile("c:/users/vmatos/temp/StudentCourses.txt");

    if (!infile) {
        cout << "File not found\n";
        exit(101);
    }

    string id, name, course;
    while (infile >> id)
    {
        getline(infile, name);
        cout << id << " " << name << " ";

        do {
            getline(infile, course);
            if (course == "#") break;
            cout << course << ", ";
        } while (true);

        cout << endl;      
    }
    infile.close();
}

//-------------------------------------------------------
void experiment03()
{
    vector<string> v{ "CS1", "CS2" };
    Student s1("2023-1001", "Homer Simpson", v);
    cout << s1.toString() << endl;
}