#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct lesson
{
      std::string name;
      int vahed;
      int point;
};

struct Student {
      std::string name;
      std::string id;
      std::string fstud;
      std::vector<lesson> lessons;
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
Student genstu(){
      vector<lesson> lessons;
      string name , id , fstudy;
      cout << "enter name,id,fstudy: ";
      cin >> name >> id >> fstudy;
      int n;
      cout << "enter ur lessons do you want: ";
      cin >> n;
      for (int i=1 ; i<= n ; i++){
            string name;
            int vahed,point;
            cout << "enter name , vahed , point : ";
            cin >> name >> vahed >> point;
            lessons.push_back(lesson{name , vahed , point});
      }
      return (Student{name , id , fstudy , lessons });
}
void showStudent(){
      for (Student i : students){
            cout << "----------------------------------" << endl;
            cout << i.name << endl;
            cout << i.id << endl;
            cout << i.fstud << endl;
            cout <<i.gpaCal();
            cout << "----------------------------------" << endl;
      }
};
int main() {
      system("cls");
      while(true){
            
            int req;
            std::cout << "enter ur num: ";
            std::cin >> req;
            switch (req)
            {
            case 1:
                  students.push_back(genstu());
                  break;
            
            case 2:
                  showStudent();
                  break;
            }
            
                  
      }
    
    return 0;
}