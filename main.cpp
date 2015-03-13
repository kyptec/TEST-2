#include <iostream>
#include <fstream>

using namespace std;


int main ()
{
  int arraysize = 1000000;
  char *myArray = new char[arraysize];
  int size = 0;
  int par = 1;
  int i = 0;
  int sent = 0;
  int words = 0;

  ifstream myfile ("read.txt");

     if (myfile.is_open())
        {
          while ( !myfile.eof())
          {
                myArray[i] = myfile.get();
                // omit apostrophy and word "it`s"
                if (((myArray[i-1] == '`') && (myArray[i]=='s')) &&
                    ((myArray[i-3] != 'i') || (myArray[i-2] != 't')) &&
                     ((myArray[i-4] != 'w') || (myArray[i-3] != 'h') || (myArray[i - 1] != 'o')))
                    i-=2;
                // special case "yours = your"
                if ((myArray[i-4] == 'y') && (myArray[i-3] == 'o') && (myArray[i-2] == 'u') && (myArray[i-1] == 'r') && (myArray[i] == 's'))
                    i--;

                // omit apostrophy after plural like "Simpsons`"
                if ((myArray[i-1] == '`') && (isspace(myArray[i])))
                    {
                    i--;
                    myArray[i] = ' ';
                    }
                // Word count
                if (!isspace(myArray[i-1]) && isspace(myArray[i]))
                    words++;
                // Paragraphs count
                if ((myArray[i-2]=='\n')&&(myArray[i-1] == '\n') && !isspace(myArray[i]))
                        par++;
                // Senctences count
                if ((myArray[i-1] == '.' || myArray[i-1] == '!' || myArray[i-1] == '?')&&(isspace(myArray[i])))
                        sent++;
                ++i;
                ++size;
          }
         cout<<endl<<"words: "<<words;
         cout<<endl<<"paragraphs: "<<par;
         cout<<endl<<"sentences: "<<sent;

      system("pause");
    }
}
