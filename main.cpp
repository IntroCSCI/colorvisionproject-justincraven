//Author: Justin Craven
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  string file, input;
  fstream reader;
  char choice='y'; 
  //Prompt User to Enter File Name For Analysis
  while(choice == 'y'||choice =='Y')
  {
    cout << "File to open:\n";
    cin >> file; 
    reader.open(file, ios::in);
    string colors;
    string num="";
    //If Successful Open of File, start analysis  
    if ( reader.is_open() )
    {  
      while(!reader.eof())
      {
        getline(reader, input); 
        //search through file for hex code colors
        for(int i=0; i<input.length(); i++)
        {
          if(input[i]=='#')
          {
            //search for end of hex code and save the digits as a string
            for(int digit=1; digit<7;digit++ )
            {
              if(input[i+digit]== ';')
              {
                digit=7;
              }
              num +=( input[i+digit]);
            }
            //check for repeats
            if(colors.find(num)==-1)
            {
               //add the hex number to a string "colors"
              colors.append(num);   
              colors.append("\n");
            }
            num="";
          }
          }         
        }
        //print the color codes
        cout << colors;
        reader.close();
        ofstream output;
        output.open ("output.txt");
        output << colors;
        output.close();
      }
      //if file does not open
      else
      {  
        cout << "Could not open file." << endl;
      
      }
      //after analysis or failure to open ask if another file is wanted to be analysed. 
        cout << "Analyze another file (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
  }
  
  return 0;
}