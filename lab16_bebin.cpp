#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Student {
private:
    string lastName;
    string firstName;
    string patronymic;
    string birthDate;
    string address;
    string phone;
    string faculty;
    int course;

public:
    void setLastName(const string& ln) { lastName = ln; }
    void setFirstName(const string& fn) { firstName = fn; }
    void setPatronymic(const string& p) { patronymic = p; }
    void setBirthDate(const string& bd) { birthDate = bd; }
    void setAddress(const string& ad) { address = ad; }
    void setPhone(const string& ph) { phone = ph; }
    void setFaculty(const string& fac) { faculty = fac; }
    void setCourse(int c) { course = c; }

    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getPatronymic() const { return patronymic; }
    string getBirthDate() const { return birthDate; }
    string getAddress() const { return address; }
    string getPhone() const { return phone; }
    string getFaculty() const { return faculty; }
    int getCourse() const { return course; }

    void show() const {
        cout << "Студент: " << lastName << " " << firstName << " " << patronymic << "\n"
            << "Дата народження: " << birthDate << "\n"
            << "Адреса: " << address << "\n"
            << "Телефон: " << phone << "\n"
            << "Факультет: " << faculty << "\n"
            << "Курс: " << course << "\n\n";
    }
};

void listStudentsByFaculty(const vector<Student>& students, const string& faculty) {
    for (const auto& student : students) {
        if (student.getFaculty() == faculty) {
            student.show();
        }
    }
}

void listStudentsByFacultyAndCourse(const vector<Student>& students) {
    map<string, map<int, vector<Student>>> facultyCourseMap;

    for (const auto& student : students) {
        facultyCourseMap[student.getFaculty()][student.getCourse()].push_back(student);
    }

    for (const auto& faculty : facultyCourseMap) {
        cout << "Факультет: " << faculty.first << "\n";
        for (const auto& course : faculty.second) {
            cout << "  Курс: " << course.first << "\n";
            for (const auto& student : course.second) {
                student.show();
            }
        }
    }
}

void listStudentsBornAfterYear(const vector<Student>& students, int year) {
    for (const auto& student : students) {
        int birthYear = stoi(student.getBirthDate().substr(6, 4));
        if (birthYear > year) {
            student.show();
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    vector<Student> students;

    Student s1;
    s1.setLastName("Iванов");
    s1.setFirstName("Iван");
    s1.setPatronymic("Iванович");
    s1.setBirthDate("15.03.2001");
    s1.setAddress("Київ");
    s1.setPhone("123456789");
    s1.setFaculty("Комп'ютернi науки");
    s1.setCourse(2);

    students.push_back(s1);

    Student s2;
    s2.setLastName("Петров");
    s2.setFirstName("Петро");
    s2.setPatronymic("Петрович");
    s2.setBirthDate("22.07.1999");
    s2.setAddress("Львiв");
    s2.setPhone("987654321");
    s2.setFaculty("Математика");
    s2.setCourse(3);

    students.push_back(s2);

    cout << "Студенти факультету Комп'ютернi науки:\n";
    listStudentsByFaculty(students, "Комп'ютернi науки");

    cout << "\nСтуденти за факультетами та курсами:\n";
    listStudentsByFacultyAndCourse(students);

    cout << "\nСтуденти, якi народилися пiсля 2000 року:\n";
    listStudentsBornAfterYear(students, 2000);

    return 0;
}
