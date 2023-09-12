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
void experiment04();
void experiment05();

void makeDatabase(vector<Student>& db);
void showDatabase(vector<Student>& db);



int main()
{
    //experiment01();
    //experiment02();
    //experiment03();
    //experiment04(); //read disk data, make memory database
    experiment05();

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
//--------------------------------------------------------

void experiment04()
{
    //Make vector<Students> database
    vector<Student> db;
    makeDatabase(db);
    showDatabase(db);

}

void makeDatabase(vector<Student>& db)
{
    //Assemble individual Student records and add to solution 
    //each record consists of: ID, Name, {courses}*, #

    

    ifstream infile("c:/users/vmatos/temp/StudentCourses.txt");

    if (!infile) {
        cout << "File not found\n";
        exit(101);
    }

    string id, name, course;
    while (getline(infile, id))
    {
        getline(infile, name);
        
        vector<string> vcourse;

        do {
            getline(infile, course);
            if (course == "#") break;
            //cout << course << ", ";
            vcourse.push_back(course);
        } while (true);

        //cout << endl;
        db.push_back(Student(id, name, vcourse));
    }
    infile.close();

    
}

//-----------------------------------------------------------------------
void showDatabase(vector<Student>& db)
{
    cout << "\nStudent Database  (size:" << db.size() << ")\n";
    for (Student s : db) {
        cout << s.toString() << endl;
    }
}
//----------------------------------------------------------------------

void experiment05()
{
    vector<string> vcourse{ "CS1", "CS2", "CS3" };
    //Student s1("2023-1111", "Carmen San Diego", vcourse);    //STACK 
    Student* s1 = new Student("2023-1111", "Carmen San Diego", vcourse);  //HEAP

    //cout << s1->toString() << endl;
    Student* s2 = new Student("2023-2222", "Jon Snow", vcourse);        //HEAP;

    //vector<Student> v1{ *s1, *s2 };
    //cout << v1[0].toString() << endl;
    //v1.clear();
    //delete s1;
    //delete s2;
    //cout << s1->toString() << endl;
    
    vector<Student*> v2{ s1, s2 };
    cout << v2[0]->toString() << endl;
    cout << v2[1]->toString() << endl;

    cout << v2[0] << endl;
    cout << v2[1] << endl;

    v2.clear();
    cout << s1->toString() << endl;
    delete s1;
    delete s2;
    cout << s1->toString() << endl;         //ERROR!!! 
}