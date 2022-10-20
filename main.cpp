#include<iostream>
#include<fstream>
using namespace std;

class shopping {
    private:
        int pcode;
        float price;
        float discount;
        string pname;

    public:
        void menu();
        void admin();
        void buyer();
        void add();
        void edit();
        void remove();
        void list();
        void receipt();

    
};