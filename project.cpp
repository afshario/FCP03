#include <iostream>
#include <vector>
#include <string>
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

int main() {
    
    return 0;
}