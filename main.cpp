/*************************************************
Aufgabe Nr./Task No.: H1
Nachname/Last,Family Name: Abaza
Vorname/First,Given Name: Ahmed
Matrikelnummer/Matriculation number: 3035482
Uni-Email: ahmed.abaza@stud.uni-due.de
Studiengang/Course of Studies: ISE CE
*************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include<iomanip>

using namespace std;

enum numberType {none, home, work, fax, mobile, other};
int n = 0;
int c = 0;
int w;
int z;


struct Contacts {
  string Name;
  string Number;
  numberType type;
};
const int maxlength = 5;
Contacts nContacts[maxlength];




bool newContact()
{
    char x;

    if (n < maxlength)
  {
    cout << "Enter Name:";
    cin.sync();
    getline (cin,nContacts[n].Name);
    cout << "Enter Number:";
    cin.sync();
    getline (cin,nContacts[n].Number);
    cout << "Enter Number Type (f for fax, h for home, m for mobile, w for work, o for other): ";
    cin >> x;
    if (x=='f')
            {
                 nContacts[n].type=fax;
            }
            else
                if (x=='h')
            {

                 nContacts[n].type=home;
            }
            else
                if (x=='m')
            {

                nContacts[n].type=mobile;
            }
            else
                if (x=='w')
            {
                nContacts[n].type=work;
            }
            else
                if (x=='o')
            {
               nContacts[n].type=other;
            }

    if(n > 0)
    {string tempName;
     string tempNum;
     numberType temptype;
     int i;
     int j;

    for(j = 0; j < n; ++j)
        for(i = j + 1; i < n+1; ++i)
        {
            if(nContacts[j].Name > nContacts[i].Name)
            {
                tempName = nContacts[j].Name;
                nContacts[j].Name = nContacts[i].Name;
                nContacts[i].Name = tempName;
                tempNum = nContacts[j].Number;
                nContacts[j].Number = nContacts[i].Number;
                nContacts[i].Number = tempNum;
                temptype = nContacts[j].type;
                nContacts[j].type = nContacts[i].type;
                nContacts[i].type = temptype;
            }
        }
    }
    n++;
    c++;


    return true;

}
        else
        {

            return false;
        }


}


bool DeleteContact()
{
    string key;
    cout << "Please enter name to delete:";
    cin.sync();
    getline (cin,key);
    for(int i=0;i<n;i++)
    {
        if(nContacts[i].Name==key)
        {
                nContacts[n].Name='0';
                  nContacts[n].Number='0';
                nContacts[n].type=none;
                    n--;
                    c--;
                for(int indexx=i;indexx<n;indexx++)
                {
                    nContacts[indexx]=nContacts[indexx+1];
                }

        return true;
        }
    }

}



void printContact ()
{
    for (w=0; w < n; w++)
    {
        if("0"==nContacts[w].Name)
          {
              cout << setw(15) << "";
          }
          else
          {
              cout << setw(15) << nContacts[w].Name;
          }

          if(nContacts[w].Number == "0")
          {
              cout << setw(15) << "";
          }
          else
          {
              cout << setw(15) << nContacts[w].Number;
          }
          //cout << " (" << Contact.type << ")\n";
          if(nContacts[w].type==1)
          {
              cout << setw(15) << "(home)\n";
          }
          else
                        if (nContacts[w].type==2)
                    {

                         cout << setw(15) << "(work)\n";
                    }
                    else
                        if (nContacts[w].type==3)
                    {

                       cout << setw(15) << "(fax)\n";
                    }
                    else
                        if (nContacts[w].type==4)
                    {
                        cout << setw(15) << "(mobile)\n";
                    }
                    else
                        if (nContacts[w].type==5)
                    {
                       cout << setw(15) << "(other)\n";
                    }
                    else
                    {
                        cout << setw(15) << "\n";
                    }
    }
}

void deleteAll()
{
    int u;
    int t = n;
    for(u = 0; u < t ; u++)
    {
        nContacts[u].Name='0';
        nContacts[u].Number='0';
        nContacts[u].type= none;
        n--;
        c--;
    }
    cout << "All Contacts deleted!" << endl;
}


int main ()
{

    int choice;
    do
    {
        cout <<"---------Number of contacts saved:" << c << "--------------------------------------"<< endl;
        cout <<"1 Input a new contact"<< endl;
        cout <<"2 Delete a contact" << endl;
        cout <<"3 Print out all contacts"<< endl;
        cout <<"4 Delete All Contacts"<< endl;
        cout <<"0 End"<< endl;
        cout <<"-------------------------------------------------------------------------"<< endl;
        cin >> choice;
        switch(choice)
        {
        case 1:

            if(newContact()== true)
            {
                cout << "Contact stored successfully!" << endl;
            }
            else
            {
                cerr << "Error, Array is full!" << endl;
            }
            cout << endl;
        break;

        case 2:
            if(DeleteContact()== true)
            {
                cout << "Contact Deleted"<< endl;

            }
            else
            {
                cerr << "Contact not found"<< endl;
            }
            cout << endl;
        break;

        case 3:
            cout << "\nYou have entered these Contacts:\n";
            printContact ();

            cout << endl;
        break;

        case 4:

            deleteAll();
            cout << endl;

        break;
        }
    } while (choice !=0);
}

