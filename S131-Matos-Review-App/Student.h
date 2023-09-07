#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

class Student
{
private:
    //Data members
    string name;
    string id;
    vector<string> courses;

public:
    //Mutators
    void setName(string nameValue) {
        // TODO - make a titlecap function 
        // name = titleCap(nameValue);

        name = nameValue;
    }
    void setId(string idValue) {
        // TODO - validate id format
        id = idValue;
    }

    void setCourses(vector<string> courseCollectionValue) {
        //TODO - make sure individual courses are legit.
        courses = courseCollectionValue;
    }

    //Accessors
    string getName() { return name; }
    string getId()   { return id; }
    vector<string> getVector() { return courses; }

    //Constructors
    Student(string idValue = "2023-0000", 
            string nameValue = "na", 
           vector<string> courseCollectionValue = {})
    {
        setId(idValue);
        setName(nameValue);
        setCourses(courseCollectionValue);

    }

    //User-defined methods
    string toString() {
        stringstream sout;
        sout << this << " Student[ID: " << getId() << "  Name: " << getName()
            << "  Courses: {";
        for (string c : courses)
        {
            sout << c << ", ";
        }
        sout << "} ]";
        return sout.str();
    }


};

