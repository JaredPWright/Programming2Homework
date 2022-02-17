//Jared Wright, for CS 130.01
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void SelSort(string stringarray[], int size)
{
    //outermost loop to check each space in the array memory
    for(int k = 1; k < size-2; k++)
    {   
        int mindex;
        for(int i = 0; i < size-1; i++)
        {
            if(stringarray[i] != "skip")
            {
                stringstream issin;
                int iid;
                issin << stringarray[i];
                issin >> iid;
                mindex = i;
                for(int j = i+1; j < size; j++)
                {
                    stringstream jssin;
                    int jid;
                    jssin << stringarray[j];
                    jssin >> jid;

                    if(jid < iid)
                        mindex = j;
                }
                
                string tempstring = stringarray[i];
                stringarray[i] = stringarray[mindex];
                stringarray[mindex] = tempstring;
            }else
                continue;
        }
    }
}

int main()
{
    const int ARRAYSIZE = 1000;
    string nameid[ARRAYSIZE];

    string ifilename;
    string ofilename;

    cout << "Input file: ";
    cin >> ifilename;
    cout << "Output file: ";
    cin >> ofilename;

    ifstream fin;
    ofstream fout;
    fin.open(ifilename.c_str());
    fout.open(ofilename.c_str());
    
    //Read in all the names and ids. Chop up the lines and rebuild them in
    //proper order via concatenation. 
    for(int i = 0; i < ARRAYSIZE; i++)
    {
        int intintake;
        string stringintake;

        for(int j = 0; j < 2; j++)
        {
            fin >> stringintake;
            if(isalpha(stringintake[0]))
            {
                if(j == 0)
                {
                    nameid[i] += (stringintake + " ");
                }else
                    nameid[i] += stringintake;
            }else
                nameid[i] = "skip";
        }
        fin >> intintake;
        
        if(nameid[i] != "skip")
        {
            if(intintake < 10)
            {
                nameid[i] = "0" + to_string(intintake) + " " + nameid[i];    
            }else
                nameid[i] = to_string(intintake) + " " + nameid[i];
        }else
            nameid[i] = "skip";
    }

    //Call selection sort. 
    SelSort(nameid, ARRAYSIZE);

    if(fout.is_open())
    {
        for(int i = 0; i < ARRAYSIZE; i++)
        {
            if(nameid[i] != "skip")
                fout << nameid[i] << "\n";
            else
                continue;
        }
    }

    fout.close();
    fin.close();
    
    return 0;
}