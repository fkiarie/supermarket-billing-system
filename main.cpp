#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class shopping {
    private:
        int pcode;
        float price;
        float discount;
        string pname;
        int col_width{20};

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
void shopping :: menu()
{
    m:
    int choice;
    string email, password;

    cout << "\t------------------------------" << endl;
    cout << endl;
    cout << "\t-------SUPERMARKET MENU---------" << endl;
    cout << endl;
    cout << "\t------------------------------" << endl;
    cout << endl;
    cout << "\t 1) Administrator" <<endl;
    cout << endl;
    cout << "\t 2) Buyer" <<endl;
    cout <<endl;
    cout << "\t 3) Exit" <<endl;
    cout << endl;
    cout << "\t Select one option above: ";
    cin >> choice;

    switch(choice)
    {
        case 1: 
            cout << "\t login to your account" << endl;
            cout << "\t Email: ";
            cin >> email;
            cout << "\t Password: ";
            cin >> password;

            if (email=="kazungu@email.com" && password=="1234")
            {
                admin();
            }
            else
            {
                cout <<"\t Invalid login details" << endl;
            }
            break;
        case 2:
            buyer();
        break;

        case 3:
            cout << "Exiting.." << endl;
            exit(0);
        break;

        default:
        cout << "\t Invalid choice" << endl;
            
    }

goto m;
}
void shopping :: admin()
{
    m:
    int choice;

    cout << "\t ----- Administrator Menu -----" << endl;
    cout << "\t 1) --- Add product      |" << endl;
    cout << endl;
    cout << "\t 2) --- Edit product     |" << endl;
    cout << endl;
    cout << "\t 3) --- Delete product   |" << endl;
    cout << endl;
    cout << "\t 4) --- Main Menu       |" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        remove();
        break;
    case 4:
        cout << "Exiting..." << endl;
        menu();
        break;
    
    default:
        cout << "Enter only the given choices: " << endl;
        break;
    }
goto m;
}
void shopping:: buyer()
{
    m:
    int choice;
    cout << "\t --- WELCOME ---" << endl;
    cout << "\t ---------------" << endl;
    cout << "\t 1) Buy products" << endl;
    cout << endl;
    cout << "\t 2) Exit Menu" << endl;
    cout << endl;
    cout << "Enter choice: ";
    cin >>choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        cout << "Back to menu..." << endl;
        menu();
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
goto m;
}
void shopping ::add(){
    m:
    fstream data;
    int c;
    int token{0};
    float p;
    float d;
    string n;
    cout << endl;
    cout << "Add new product: " << endl;
    cout << endl;
    cout << "\t Product code: ";
    cin >> pcode;
    cout << "\t Product name: ";
    cin >> pname;
    cout << "\t Product price: ";
    cin >> price;
    cout << "\t Discount on the product: ";
    cin >> discount;

    data.open("database.txt", ios::in);
    if(!data)
    {
        data.open("database.txt" ,ios::app | ios::out);
        data << left;
        data<<setw(col_width)<<pcode<<setw(col_width)<<pname<<setw(col_width)<<price<<setw(col_width)<<discount<<endl;
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
            while(!data.eof()){
                if(c == pcode)
                {
                    token++;
                }
                data>>c>>n>>p>>d;
            }
            data.close();

        if(token == 1)
        {
            goto m;

        }else
        {
            data.open("database.txt" ,ios::app | ios::out);
            data << left;
            data<<setw(col_width)<<pcode<<setw(col_width)<<pname<<setw(col_width)<<price<<setw(col_width)<<discount<<endl;
            data.close();
        }

    }
    cout << endl;
    cout << "\t Record inserted" << endl;
    cout << endl;

}
void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int token{0};
    int c;
    float p;
    float d;
    string n;

    cout << "\t Modify product \n";
    cout << "\t Enter product key: ";
    cin >> pkey;

    data.open("database.txt" , ios::in);
    if(!data)
    {
        cout << "\t\tFile does not exist" << endl;
    }else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pkey == pcode)
            {
                cout<<"\t Product new code: ";
                cin>>c;
                cout<<"\t Product new name: ";
                cin>>n;
                cout<<"\t Product new price: ";
                cin>>p;
                cout<<"\t product new discount: ";
                cin>>d;
                data1<<setw(col_width)<<c<<setw(col_width)<<n<<setw(col_width)<<p<<setw(col_width)<<d<<endl;
                cout << "\tRecord updated" << endl;
                token++;

            }else
            {
                data<<setw(col_width)<<pcode<<setw(col_width)<<pname<<setw(col_width)<<price<<setw(col_width)<<discount<<endl;
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        //remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0)
        {
            cout << "\t Record not found!" << endl;
        }
    }
}
void shopping :: remove()
{
    fstream data, data1;
    int pkey;
    int token{0};

    cout << "\t\t Delete product---";
    cout << "\t Enter key: ";
    cin >> pkey;
    data.open("database.txt" , ios::in);
    if(!data)
    {
        cout << "File not found" << endl;
    }else
    {
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\t product deleted successfully"<<endl;
                token++;
            }else
            {
                data << left;
                data<<setw(col_width)<<pcode<<setw(col_width)<<pname<<setw(col_width)<<price<<setw(col_width)<<discount<<endl;
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        //remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0)
        {
            cout << "\t Record not found" << endl;
        }
    }
}
void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\t--------------------\n";
    cout << left;
    cout<<setw(col_width)<<"Product code"<<setw(col_width)<<"Product Name"<<setw(col_width)<<"Price"<<setw(col_width)<<"discount"<<endl;
    data>>pcode>>pname>>price>>discount;
    while(!data.eof())
    {
        cout<<setw(col_width)<<pcode<<setw(col_width)<<pname<<setw(col_width)<<price<<setw(col_width)<<discount<<endl;
        data>>pcode>>pname>>price>>discount;
    }
    data.close();

    
}
void shopping::receipt()
{
    
    fstream data;
    int arrc[100];
    int arrq[100];
    string choice;
    int c{0};
    float amount{0};
    float dis{0};
    float total{0};

    cout << "\t\t --- Receipt ---" << endl;
    data.open("database.txt", ios::in);
    if(!data){
        cout << "\t\tNo Data" << endl;
    }else
    {
        data.close();
        list();
        cout << "\t\t----------------------------------\n";
        cout << "\t\t --- Place your order: ---\n";
        cout << "\t\t----------------------------------\n\n";
        do
        {
            m:
            cout << "\t\t Enter product code: ";
            cin>>arrc[c];
            cout << "\t\t Enter quantity: ";
            cin>>arrq[c];

            for(int i=0;i<c;i++)
            {
                if(arrc[c] == arrc[i])
                {
                    cout << "\t\t Duplicate code!" << endl;
                    goto m;
                }
                c++;
                cout << "\t\t Add more products? y OR n: ";
                cin >> choice;
            } 
            
        }while (choice == "y");

        cout << "\t\t\t -------- RECEIPT ------\n" << endl;
        cout << left;
        cout<<setw(col_width)<<"Product code"<<setw(col_width)<<"Quantity"<<setw(col_width)<<"Price"<<setw(col_width)<<"Amount"<<setw(col_width)<<"Amount with disc"<<endl;

        for(int i=0; i<c; i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;
            while(data.eof())
            {
                if(pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount -(amount *dis/100);
                    total = total +dis;
                    cout<<setw(col_width)<<pcode<<setw(col_width)<<pname<<setw(col_width)<<arrq[i]<<setw(col_width)<<price<<setw(col_width)<<amount<<setw(col_width)<<dis<<endl;

                }
                data>>pcode>>pname>>price>>discount;
            }
        }
        data.close();
        

    }
    cout << "\t\t\t --- The total amount is: " << total<< endl;


}

int main()
{
    shopping s;
    s.menu();
}