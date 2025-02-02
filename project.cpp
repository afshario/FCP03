#include "headers.h"

int main() {
      initial();
      bool a = true;
      while(a){
            string request;
            cout << "---------------------------------" << '\n';
            cout << "| 1 - Create a student" << "\n";
            cout << "| 2 - Show students with limits" << "\n";
            cout << "| 3 - Show all students" << "\n";
            cout << "| 4 - Write students in database" << "\n";
            cout << "| 5 - Print student's report card" << "\n";
            cout << "| 6 - Delete a student" << "\n" ;
            cout << "| 7 - Exit" << '\n' << "---------------------------------" << "\n";
            cout <<">>> " <<"Enter a function you need: ";
            cin >> request;

            if(request == "1")
                  students.push_back(generateStudent());
            else if(request == "2"){
                  bubbleSort();
                  showStudent();
            }
            else if(request == "3"){
                  bubbleSort();
                  showStudentAll();
            }
            else if(request == "4")
                  writeStudent();
            else if(request == "5")
                  karnameh();
            else if(request == "6")
                  deleteStudent();
            else if(request == "7")
                  editStudent();
            else if(request == "8")
                  a = false;
            else
                  system ("cls");
                      
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
      
      cout << "| Enter reshteh :";
      string a;
      int flag{0};
      cin >> a;
      for (int j = students.size()-1 ; j >= 0 ; j--){
            Student i = students[j];
            if (i.fstud == a){
                  flag = 1;
                  cout << "----------------------------------" << endl;
                  cout << "| Name :" << i.name << endl<< "| ";
                  cout << " ID :" << i.id << endl<< "| ";
                  cout << " field of study :" << i.fstud << endl<< "| ";
                  cout <<" GPA :" << i.gpaCal() << endl<< "| ";
            } else {
                  flag = false;
            }
      }
      
};
void showStudentAll(){
      for (int j = students.size()-1 ; j >= 0 ; j--){
            Student i = students[j];
                        cout << "----------------------------------" << endl;
                        cout << "| Name :" << i.name << endl<< "| ";
                        cout << " ID :" << i.id << endl<< "| ";
                        cout << " field of study :" << i.fstud << endl<< "| ";
                        cout <<" GPA :" << i.gpaCal() << endl<< "| ";
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
      cout << "| students are written sucessfully" << '\n';
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
      bool flag = false;
      for (Student i : students){
            if ((i.name == name) && (i.id == id)){
                  flag = true;
                  cout << "| Name :" << i.name << endl<< "| ";
                  cout << "| ID :" << i.id << endl<< "| ";
                  cout << "| Field of study :" << i.fstud << endl<< "| ";
                  cout << "| GPA :"<< i.gpaCal()<< endl<< "| ";
                  for(lesson l : i.lessons){
                        cout << "------ Lessons of " << i.name << "------:" << '\n';
                        cout << "| Name of lesson :" << l.name << endl<< "| ";
                        cout << "| Vahed :" << l.vahed << endl<< "| ";
                        cout << "| Student's point :" << l.point << endl<< "| ";
                        cout << "------------------------------" << '\n';
                  }
                  break;
            }
      }
      if (!flag){
            cout << "| Student dosen't exists!" << '\n';
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
                        float point = jsonData[i]["lessons"][j]["point"];
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
void deleteStudent(){
      string a;
      cout << "| Enter student's ID: ";
      cin >> a;
      bool flag = false;
      for (int i =0 ; i <= students.size() ; i++){
            if(students[i].id == a){
                  flag = true;
                  students.erase(students.begin() + i);
                  cout << "| Student deleted sucessfully "<< '\n';
                  break;   
            }
      }
      if(!flag){
            cout << "| Student dosen't exist! "<< '\n';
      }
}
void editStudent(){
      cout << "| Enter student ID: ";
      bool flag = false;
      string a;
      cin >> a;
      for(Student &i : students){
            if(i.id == a){
                  cout << "| Enter student edit: ";
                  string b;
                  cin >> b;
                  if(b == "name"){
                        cout << "| Enter student new name: ";
                        string c;
                        cin >> c;
                        i.name = c;
                  }
                  else if(b == "id"){
                        cout << "| Enter student new ID: ";
                        string c;
                        cin >> c;
                        i.id = c;
                  }
                  else if(b == "fstudy"){
                        cout << "| Enter student new field of study: ";
                        string c;
                        cin >> c;
                        i.fstud = c;
                  }
                  else if(b == "lessons"){
                        for (lesson &j : i.lessons){
                              cout << j.name << '\n';
                        }
                        string ac;
                        cout << "| Enter lesson's name :" << '\n';
                        cin >> ac;
                        int n{0};
                        for (lesson &j : i.lessons){
                              if(j.name == ac){
                                    cout << "| Enter lesson edit: ";
                                    string b;
                                    cin >> b;
                                    if(b == "name"){
                                          cout << "| Enter lesson new name: ";
                                          string c;
                                          cin >> c;
                                          j.name = c;
                                    }
                                    else if(b == "vahed"){
                                          cout << "| Enter student new vahed: ";
                                          int c;
                                          cin >> c;
                                          j.vahed = c;
                                    }
                                    else if(b == "point"){
                                          cout << "| Enter student new point: ";
                                          int c;
                                          cin >> c;
                                          j.point = c;
                                    }
                                    else if(b == "delete"){
                                          i.lessons.erase(i.lessons.begin() + n);
                                    }
                                    break;
                              }
                              n++;
                        }
                  }
                  flag = true;
            }
      }
      if(!flag){
            cout << "| Student not found!";
      }
}