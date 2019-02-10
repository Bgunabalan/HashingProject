#include<iostream>
#include<stack>
#include<string>
#include<fstream>
#include<cctype>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;



string hashTableL[100] = {"empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty",};
string hashTableQ[100] = {"empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty","empty",};


int linearHash(string str, int colls)
{
   return (int) (str[0] + str[str.length()-1] + (char)colls) % 100;

}
int quadHash(string str, int colls)
{
   return (int) (str[0] + str[str.length()-1] + (((char)colls)*(char)colls)) % 100;

}
int addItemL(string str)
{
    int colls  = 0;
    int index;
    index = linearHash(str,colls);
    while(hashTableL[index] != "empty")
    {
        colls++;
        index = linearHash(str, colls);
    }
    hashTableL[index] = str;
    return colls;
}
int addItemQ(string str)
{
    int colls  = 0;
    int index;
    index = linearHash(str,colls);
    while(hashTableQ[index] != "empty")
    {
        colls++;
        index = quadHash(str, colls);
    }
    hashTableQ[index] = str;
    return colls;
}


int main()
{
    cout << "Linear Hash" << endl;
    ifstream inFile;
    inFile.open("a3.txt");
    int i, j, linecount, colls, collscountL, collscountQ;
    linecount = 0;
    collscountL = 0;
    collscountQ = 0;

    for(i=0; i<13; i++)
    {

      linecount++;
      cout << linecount << "   ";

        for (j=0; j<4; j++)
        {
            string name;
            getline(inFile, name);
            if (name.empty()) name = "_______________";
            if (inFile.eof()) goto endloop;
            colls = addItemL(name);
            name.resize (15, ' ');
            cout << name << colls << "  ";
            collscountL = collscountL + colls;
        };

      cout << "\n";
    };
    endloop:
    cout << "\n";


    inFile.clear();
    inFile.seekg(0, ios::beg);
    cout << endl << "Quadratic Hash" << endl;
    linecount = 0;
    for(i=0; i<13; i++)
    {

      linecount++;
      cout << linecount << "   ";


      for (j=0; j<4; j++)
        {
            string name;
            getline(inFile, name);
            if (name.empty()) name = "_______________";
            if (inFile.eof()) goto endloop2;
            colls = addItemQ(name);
            name.resize (15, ' ');
            cout << name << colls << "  ";
            collscountQ = collscountQ + colls;
        };

      cout << "\n";
    };
    endloop2:
    cout << "\n";

    cout << endl << "Comparison";
    cout << endl << "Total Number of Linear Collisions: " << collscountL;
    cout << endl << "Total Number of Quadratic Collisions: " << collscountQ << endl << endl;

    char input;
    cout << "Enter 'L' to print out the Linear Hash Table in order, Enter 'Q' to print out the Quadratic Hash Table in order" << endl;
    cin >> input;
    if (input == 'L') for (i=0;i<100;i++) cout << i << "  " << hashTableL[i] << endl;
    if (input == 'Q') for (i=0;i<100;i++) cout << i << "  " << hashTableQ[i] << endl;
}

