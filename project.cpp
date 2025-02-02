#include "headers.h"

int main() {
      initial();
      bool a = true;
      while(a){
            int request;
            cout << "---------------------------------" << '\n';
            cout << "| 1 - Create a student" << "\n";
            cout << "| 2 - Show students with limits" << "\n";
            cout << "| 3 - Show all students" << "\n";
            cout << "| 4 - Write students in database" << "\n";
            cout << "| 5 - Print student's report card" << "\n";
            cout << "| 6 - Exit" << "\n" << "---------------------------------" << "\n";
            cout <<">>> " <<"Enter your function you need: ";
            cin >> request;
            switch (request){

            case 1:
                  students.push_back(generateStudent());
                  break;
            
            case 2:
                  bubbleSort();
                  showStudent();
                  break;
            case 3:
                  bubbleSort();
                  showStudentAll();
                  break;
            case 4:
                  writeStudent();
                  break;
            case 5:
                  karnameh();
                  break;
            case 6:
                  a = false;
            default:
                  system ("cls");
            }            
      }
    return 0;
}

Student generateStudent(){
      vector<lesson> lessons;
      string name , id , fstudy;
      cout << "---------------------------------" << "\n"<< "| ";
      cout << "| Enter student's name :" << '\n'<< "| ";
      cin >> name ;
      cout << "| Enter student's id :" << '\n'<< "| ";
      cin >> id ;
      cout << "| Enter student's field of study :" << '\n'<< "| ";
      cin >> fstudy;
      int n;
      cout << "| How many lessons you want to add :" << '\n'<< "| ";
      cin >> n;
      for (int i=1 ; i<= n ; i++){
            string name;
            float point;
            int vahed;
            cout << "| Enter name of lesson :" << '\n' << "| ";
            cin >> name ;
            cout << "| Enter vahed of lesson :" << '\n'<< "| ";
            cin>> vahed ;
            cout << "| Enter student's point :" << '\n'<< "| ";
            cin >> point;
            lessons.push_back(lesson{name , vahed , point});
      }
      return (Student{name , id , fstudy , lessons });
}
void showStudent(){
      vector<string> b;
      int n;
      cout << "| How many limits :" << '\n'<< "| ";
      cin >> n;
      for (int i = 0 ; i < n ; i++){
            cout << "| Enter reshteh :";
            string a;
            cin >> a;
            b.push_back(a);
      }
      for(int k =0 ; k<=n ;k++){
            for (int j = students.size()-1 ; j >= 0 ; j--){
                  Student i = students[j];
                  if (i.fstud == b[k]){
                        cout << "----------------------------------" << endl;
                        cout << "| Name :" << i.name << endl<< "| ";
                        cout << "| ID :" << i.id << endl<< "| ";
                        cout << "| field of study :" << i.fstud << endl<< "| ";
                        cout <<"| GPA :" << i.gpaCal() << endl<< "| ";
                        cout << "----------------------------------" << endl;
                  }
      }
      }
};
void showStudentAll(){
      for (int j = students.size()-1 ; j >= 0 ; j--){
            Student i = students[j];
                        cout << "----------------------------------" << endl;
                        cout << "| Name :" << i.name << endl<< "| ";
                        cout << "| ID :" << i.id << endl<< "| ";
                        cout << "| field of study :" << i.fstud << endl<< "| ";
                        cout <<"| GPA :" << i.gpaCal() << endl<< "| ";
                        cout << "----------------------------------" << endl;
            }
}
int writeStudent(){
      if(students.size() == 0){
            return 0;
      }
      ofstream file("data.json");
      if (students.size() == 0){
            file.close();
      }
      json newj = json::array();
      for (int j = 0 ; j < students.size() ; j++){
            json jsonData;
            Student a = students[j];
            jsonData["name"] = a.name;
            jsonData["id"] = a.id;
            jsonData["fstudy"] = a.fstud;
            for (int i=0 ; i < a.lessons.size() ; i++){
                  lesson x = a.lessons[i];
                  jsonData["lessons"][i]["name"] = x.name;
                  jsonData["lessons"][i]["vahed"] = x.vahed;
                  jsonData["lessons"][i]["point"] = x.point;
            }
            newj.push_back(jsonData);

      }
      file << newj;
      file.close();
                  
      return 0;
}
void bubbleSort() {
    for (int i = 0; i < students.size() - 1; i++) {
        for (int j = 0; j < students.size() - i - 1; j++) {
            if (students[j].gpaCal() > students[j + 1].gpaCal()) {
                swap(students[j], students[j+1]);
            }
        }
    }
}
void karnameh(){
      string name , id;
      cout << "| Enter student's name :";
      cin >> name;
      cout << "| Enter student's ID :";
      cin >> id;
      for (Student i : students){
            if ((i.name == name) && (i.id == id)){
                  cout << "| Name :" << i.name << endl<< "| ";
                  cout << "| ID :" << i.id << endl<< "| ";
                  cout << "| Field of study :" << i.fstud << endl<< "| ";
                  cout << "| GPA :"<< i.gpaCal()<< endl<< "| ";
                  for(lesson l : i.lessons){
                        cout << "| Name of lesson :" << l.name << endl<< "| ";
                        cout << "| Vahed :" << l.vahed << endl<< "| ";
                        cout << "| Student's point :" << l.point << endl<< "| ";
                  }
                  break;
            }
      }

}
void initial(){
      system("cls");
      ifstream file("data.json");
      json jsonData;
      file >> jsonData;
      if (jsonData.size() != 0){
            for (int i=0 ; i < jsonData.size() ; i++){
                  vector<lesson> lessons;
                  for (int j=0 ; j < jsonData[i]["lessons"].size(); j++){
                        string name = jsonData[i]["lessons"][j]["name"];
                        int vahed = jsonData[i]["lessons"][j]["vahed"];
                        int point = jsonData[i]["lessons"][j]["point"];
                        lesson a{name ,vahed, point};
                        lessons.push_back(a);
                  }
                  string name = jsonData[i]["name"];
                  string id = jsonData[i]["id"];
                  string fstudy = jsonData[i]["fstudy"];
                  Student m{name ,id,fstudy,lessons};
                  students.push_back(m);
            }
      }
      file.close();
}