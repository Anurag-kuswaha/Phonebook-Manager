//   _______credit-Anurag_kushwaha_______ 
#include <iostream> 
#include <vector>
#include <string>
#include<list>

using namespace std;
class PhoneBook {
    int n;
    static const int m = 1000;
    int a, b, p;
    vector<string> query;
    list < pair<int, string>> table[m]; //this is list not assosiative container hence we hav to create pair to act as one.


    int hashfunction(int num) {
        // we need a ,b and p(prime number which is slightly greater than our max size of mobile number)
        // finding a and b  using rand function;
        return ((long long)((long long)(a * num) + b) % p) % m; //this will gives hash key with least collision A/C video of courseERA

    }
    void add(int num, string name) {
        int hashkey = hashfunction(num); //passsing mobile number for finding  hash value;
        // i will go to that cell of the list of that hashkey & iterate this cell only
        auto& cell = table[hashkey];
        bool is_exist = false;
        auto it = cell.begin(); //starts iterate from the begining of the of the list of that index;
        for (; it != cell.end(); it++) {
            if (it->first == num)//mobile number exist now i will update the name of the mobile number;
            {
                is_exist = true;
                it->second = name;
                break;
            }
        }
        if (!is_exist) {//mobile number not present and we need to add;
            cell.emplace_back(num, name);  //adding number && adding name;
        }

    }
    void del(int num) {
        int hashkey = hashfunction(num);
        auto& cell = table[hashkey];
        bool key_exist = false;
        auto it = begin(cell);
        for (; it != cell.end(); it++) {
            if (it->first == num)//if num found;
            {  //here deleteing the iterator it and we need to collect the iterator so it will point to the nex element;
                key_exist = true;
                it = cell.erase(it); //it will delete the number and the name
                break;
            }
        }
        if (!key_exist) {}
        //if not found do nothing;
    }
    string fnd(int num) {
        string name = "not found"; //if not found then this will return else upadted value of name will goes;
        int hashkey = hashfunction(num);
        auto& cell = table[hashkey];
        auto it = begin(cell);
        for (; it != cell.end(); it++) {
            if (it->first == num) {
                name = it->second;
                break;
            }
        }
        return name;
    }
    void Query() {
        cin >> n;
        query.resize(n);

        int num; string name;
        for (int q = 0;q < n;q++) {
            cin >> query[q];
            if (query[q] == "add") {

                //call add function
                cin >> num >> name;
                add(num, name);
            }
            if (query[q] == "del") {
                //call delete function
                cin >> num;
                del(num);
            }
            if (query[q] == "find") {
                //call find function
                cin >> num;
                string res = fnd(num);
                cout << res << endl;
            }
        }
    }
public:
    void solution() {
        Query();
    }
    PhoneBook() { //constructor

        p = 10000019; // as size of mobile number is goes upto 7
        a = 2; //a = rand() % (p - 2) + 1;  //it goes upto 1 to p-1
        b = 34;//b = rand() % (p - 1);  //it goes from 0 to p-1
    }
};

int main() {
    PhoneBook S;
    S.solution();
    return 0;
}
