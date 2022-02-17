#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    const int ARRAYSIZE = 26;
    string morsetable[ARRAYSIZE] =
    {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
    string translationtable[ARRAYSIZE] =
    {
        "A", "B", "C", "D", "E", "F", "G", "H", "I",
        "J", "K", "L", "M", "N", "O", "P", "Q", "R",
        "S", "T", "U", "V", "W", "X", "Y", "Z"
    };

    string message = "";
    string readin;

    cout << "Enter Morse words, one per line:\n";
    getline(cin, readin);
    while( readin != "Quit" )
    {
        if(readin == "Quit")
            break;
        else
        {
            stringstream ssin;
            ssin << readin;
            string tempstring;
            
            while(ssin >> tempstring)
            {
                for(int i = 0; i < ARRAYSIZE; i++)
                {
                    if(tempstring == morsetable[i])
                    {
                        message += translationtable[i];
                        break;
                    }
                }
            }
        }
        message += " ";
        getline(cin, readin);
    }
    cout << message << endl;

    return 0;
}