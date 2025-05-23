#include <iostream>
#include "json.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <typeinfo>
#include <cmath>
#include <unordered_set>
using json = nlohmann::json;
using namespace std;
struct lesson
{
      string name;
      float vahed;
      float point;
};
struct Student {
      string name;
      string id;
      string fstud;
      vector<lesson> lessons;
      float gpaCal(){
            float s{0};
            float a{0};
            for (lesson i : lessons){
                  s += (i.point * i.vahed);
                  a += i.vahed;
            }
            return (s/a);
      };
};
std::vector<Student> students;
Student generateStudent();
int showStudent();
int showStudentAll();
int writeStudent();
void bubbleSort();
void karnameh();
void initial();
void deleteStudent();
void editStudent();