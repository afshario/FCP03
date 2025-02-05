#include "headers.h"

int main() {
      initial();
      cout << "=====Creators: Afshari, Fahimi=====" << '\n';
      bool a = true;
      while(a){
            string request;
            cout << "===================================" << '\n';
            cout << "| 1 - Create a student            |" << '\n';
            cout << "| 2 - Show students with limits   |" << '\n';
            cout << "| 3 - Show all students           |" << '\n';
            cout << "| 4 - Print student's report card |" << '\n';
            cout << "| 5 - Delete a student            |" << '\n';
            cout << "| 6 - Edit student                |" << '\n';
            cout << "| 7 - Exit                        |" << '\n';
            cout << "===================================" << '\n';
            cout <<">>> Enter a function you need: ";
            cin >> request;
            system("cls");
            if (request == "1")
                  students.push_back(generateStudent());
            else if (request == "2"){
                  bubbleSort();
                  showStudent();
            }
            else if (request == "3"){
                  bubbleSort();
                  showStudentAll();
            }
            else if (request == "4")
                  karnameh();
            else if (request == "5")
                  deleteStudent();
            else if (request == "6")
                  editStudent();
            else if (request == "7"){
                  writeStudent();
                  a = false;
            }
            else
                  system ("cls");
                      
      }
    return 0;
}

Student generateStudent(){
      vector<lesson> lessons;
      string name , id , fstudy;
      cout << "===================================" << "\n";
      cout << "| Enter student's name :";
      cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
      getline(cin, name);
      i_l:
      cout << "| Enter student's id :" ;
      cin >> id;
      for(char c : id){
            if ((c - '0' < 0) || (c - '0' > 9)){
                  cout << "| ID can only contain numbers!" << '\n';
                  goto i_l;
            }
      }
      for (Student p : students){
            if (p.id == id){
                  cout << "| ID is used!" << '\n';
                  goto i_l;
            }
      }
      cout << "| Enter student's field of study :" ;
      cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
      getline(cin , fstudy);
      int n;
      n_l:
      cout << "| How many lessons you want to add :" ;
      cin >> n;
      if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "| invalid data inputed! " << '\n';
            goto n_l;
      }
      for (int i=1 ; i<= n ; i++){
            cout << "-----------------------------------" << endl;
            string name;
            float point;
            float vahed;
            cout << "| Enter name of lesson :" ;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            getline( cin , name);
            vahed_l:
            cout << "| Enter credit of lesson :" ;
            cin >> vahed ;
            if (cin.fail() || floor(vahed) != vahed || vahed < 0){
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  cout << "| invalid data inputed! " << '\n';
                  goto vahed_l;
            }
            point_l:
            cout << "| Enter student's point :" ;
            cin >> point;
            if (cin.fail()){
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  cout << "| invalid data inputed! " << '\n';
                  goto point_l;
            }
            if (point < 0 || point > 20){
                  cout << "| invalid data inputed! " << '\n';
                  goto point_l;
            }
            lessons.push_back(lesson{name , vahed , point});
      }
      system("cls");
      cout << "| Student generated! " << '\n' ;
      return (Student{name , id , fstudy , lessons });
}
int showStudent(){
      unordered_set <string> fields;
      cout << "===================================" << "\n";
      cout << "| field of studies are exists :" << "\n";
      for (Student i : students){
            fields.insert(i.fstud);
      }
      for (string i : fields){
            cout << "| -" << i << '\n';
      }
      cout << "| Enter field of study :";
      string a;
      int flag{0};
      cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
      getline(cin , a);
      if (students.size() == 0){
            return 1;
      }
      cout << "-------------Students--------------" << endl;
      for (int j = students.size()-1 ; j >= 0 ; j--){
            Student i = students[j];
            if (i.fstud == a){
                  flag = 1;
                  cout << "-----------------------------------" << endl;
                  cout << "| Name :" << i.name << endl;
                  cout << "| ID :" << i.id << endl;
                  cout << "| field of study :" << i.fstud << endl;
                  cout << "| GPA :" << i.gpaCal() << endl;
            }
      }
      cout << "-------------^^^^^^^^--------------" << endl;
      if (flag == 0){
            system("cls");
            cout << "| field of study not found! "<< '\n';
      }
      return 0;
};
int showStudentAll(){
      if (students.size() == 0){
            return 0;
      }
      cout << "------------ Students -------------" << endl;
      for (int j = students.size()-1 ; j >= 0 ; j--){
            Student i = students[j];
                        cout << "-----------------------------------" << endl;
                        cout << "| Name :" << i.name << endl;
                        cout << "| ID :" << i.id << endl;
                        cout << "| field of study :" << i.fstud << endl;
                        cout << "| GPA :" << i.gpaCal() << endl;
      }
      cout << "-------------^^^^^^^^^-------------" << endl;
      return 0;
}
int writeStudent(){
      if(students.size() == 0){
            return 0;
      }
      ofstream file("data.json");
      if (students.size() == 0){
            file.close();
      }
      json jarr = json::array();
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
            jarr.push_back(jsonData);

      }
      file << jarr;
      file.close();
      system("cls");
      cout << "| students are written sucessfully" << '\n';
      return 0;
}
void bubbleSort() {
    for (int i = 0; i < students.size() - 1; i++) {
        for (int j = 0; j < students.size() - i - 1; j++) {
            if ((students[j].gpaCal() > students[j + 1].gpaCal()) && (!isnan(students[j].gpaCal())) && (!isnan(students[j+1].gpaCal()))) {
                swap(students[j], students[j+1]);
            }
        }
    }
}
void karnameh(){
      string id;
      id_l:
      cout << "| Enter student's ID :";
      cin >> id;
      for(char c : id){
            if ((c - '0' < 0) || (c - '0' > 9)){
                  cout << "| ID can only contain numbers!" << '\n';
                  goto id_l;
            }
      }
      bool flag = false;
      cout << "------------Report card------------" << endl;
      for (Student i : students){
            if (i.id == id){
                  flag = true;
                  cout << "-----------------------------------" << endl;
                  cout << "| Name :" << i.name << endl;
                  cout << "| ID :" << i.id << endl;
                  cout << "| Field of study :" << i.fstud << endl;
                  cout << "| GPA :"<< i.gpaCal()<< endl;
                  cout << "------------- Lessons ------------" << '\n';
                  if(i.lessons.size() == 0){
                        cout << "| Student dosen't have lesson!" << '\n';
                  }
                  for(lesson l : i.lessons){
                        cout << "| Name of lesson :" << l.name << endl;
                        cout << "| Credit :" << l.vahed << endl;
                        cout << "| Student's point :" << l.point << endl;
                        cout << "-----------------------------------" << endl;
                  }
                  break;
            }
      }
      if (!flag){
            system("cls");
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
                        float vahed = jsonData[i]["lessons"][j]["vahed"];
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
      a_l:
      cout << "| Enter student's ID: ";
      cin >> a;
      for(char c : a){
            if ((c - '0' < 0) || (c - '0' > 9)){
                  cout << "| ID can only contain numbers!" << '\n';
                  goto a_l;
            }
      }
      bool flag = false;
      for (int i =0 ; i <= students.size() ; i++){
            if(students[i].id == a){
                  flag = true;
                  students.erase(students.begin() + i);
                  system("cls");
                  cout << "| Student deleted sucessfully "<< '\n';
                  break;   
            }
      }
      if(!flag){
            system("cls");
            cout << "| Student dosen't exist! "<< '\n';
      }
}
void editStudent(){
      e_l:
      cout << "| Enter student ID: ";
      bool flag = false;
      bool flag1 = false;
      string a;
      cin >> a;
      for(char c : a){
            if ((c - '0' < 0) || (c - '0' > 9)){
                  cout << "| ID can only contain numbers!" << '\n';
                  goto e_l;
            }
      }
      for(Student &i : students){
            if(i.id == a){
                  cout << "| Enter student edit (name , id , fstudy , lessons ,add (for add new lessons)): ";
                  string b;
                  cin >> b;
                  if(b == "name"){
                        cout << "| Enter student new name: ";
                        string c;
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                        getline( cin , c);
                        i.name = c;
                        system("cls");
                        cout <<"| student name changed! "<< '\n';
                  }
                  else if(b == "id"){
                        k_l:
                        cout << "| Enter student new ID: ";
                        string c;
                        cin >> c;
                        for(char l : c){
                              if ((l - '0' < 0) || (l - '0' > 9)){
                                    cout << "| ID can only contain numbers!" << '\n';
                                    goto k_l;
                              }
                        }
                        for (Student p : students){
                              if (p.id == c){
                                    cout << "| ID is used!" << '\n';
                                    goto k_l;
                              }
                        }
                        i.id = c;
                        system("cls");
                        cout <<"| student ID changed! "<< '\n';
                  }
                  else if(b == "fstudy"){
                        cout << "| Enter student new field of study: ";
                        string c;
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                        getline( cin , c);
                        i.fstud = c;
                        system("cls");
                        cout <<"| student field of study changed! "<< '\n';
                  }
                  else if(b == "lessons"){
                        cout << "| student's lessons :" << '\n';
                        for (lesson &j : i.lessons){
                              cout <<"| - " <<j.name << '\n';
                        }
                        string ac;
                        cout << "| Enter lesson's name :";
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                        getline(cin , ac);
                        int n{0};
                        for (lesson &j : i.lessons){
                              if(j.name == ac){
                                    flag1 = true;
                                    cout <<"| Enter lesson edit (name , point , vahed , delete): ";
                                    string b;
                                    cin >> b;
                                    if(b == "name"){
                                          cout << "| Enter lesson new name: ";
                                          string c;
                                          cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                          getline( cin , c);
                                          j.name = c;
                                          system("cls");
                                          cout <<'\n' <<"| lesson name changed! " << '\n';
                                    }
                                    else if(b == "vahed"){
                                          vah_l:
                                          cout << "| Enter student new vahed: ";
                                          float c;
                                          cin >> c;
                                          if (cin.fail() || floor(c) != c || c < 0){
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                cout << "| invalid data inputed! " << '\n';
                                                goto vah_l;
                                          }
                                          j.vahed = c;
                                          system("cls");
                                          cout <<"| lesson vahed changed! "<< '\n';
                                    }
                                    else if(b == "point"){
                                          p_l:
                                          cout << "| Enter student new point: ";
                                          int c;
                                          cin >> c;
                                          if (cin.fail()){
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                cout << "| invalid data inputed! " << '\n';
                                                goto p_l;
                                          }
                                          if (c < 0 || c > 20){
                                                cout << "| invalid data inputed! " << '\n';
                                                goto p_l;
                                          }
                                          j.point = c;
                                          system("cls");
                                          cout <<"| student point changed! "<< '\n';
                                    }
                                    else if(b == "delete"){
                                          system("cls");
                                          i.lessons.erase(i.lessons.begin() + n);
                                          cout << "| Lesson deleted!"<< '\n';
                                    }
                                    else {
                                          system("cls");
                                          cout << "| Function not found!"<< '\n';
                                    }
                                    break;
                              }
                              n++;
                        } 
                        if(!flag1){
                              system("cls");
                              cout << "| Lesson not found!"<< '\n';
                        }
                  }
                  else if(b == "add"){
                        string name;
                        float vahed;
                        float point;
                        cout << "| Enter lesson name:";
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                        getline( cin , name);
                        v_l:
                        cout << "| Enter lesson credit:";
                        cin >> vahed;
                        if (cin.fail() || floor(vahed) != vahed){
                              cin.clear();
                              cin.ignore(numeric_limits<streamsize>::max(), '\n');
                              cout << "| invalid data inputed! " << '\n';
                              goto v_l;
                        }
                        po_l:
                        cout << "| Enter student point:";
                        cin >> point;
                        if (cin.fail()){
                              cin.clear();
                              cin.ignore(numeric_limits<streamsize>::max(), '\n');
                              cout << "| invalid data inputed! " << '\n';
                              goto po_l;
                        }
                        if (point < 0 || point > 20){
                              goto po_l;
                              cout << "| invalid data inputed! " << '\n';
                        }
                        i.lessons.push_back(lesson{name , vahed , point});
                        system("cls");
                        cout << "| lesson added! " << '\n';
                  } else {
                        system("cls");
                        cout << "| Function not found!"<< '\n';
                  }
                  flag = true;
            }
      }
      if(!flag){
            system("cls");
            cout << "| Student not found!"<< '\n';
      }
}