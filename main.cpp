//Author: Justin Craven
//Versin: 1.0
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "colorList.h"
using namespace std;

//Prototypes
bool isUnique(vector<string>, string);
vector <double> greyValue(string);
vector <string> dominance(vector <string>);
void displayString(vector<string>);
void displayInt(vector<int>);
void displayDouble(vector<double>);
void displayDominance(vector<string>);
int rgbConvert(string);
int rgbConvertOneDig(string);
int getR(string&);
int getG(string&);
int getB(string&);
vector <int> rgbFormat(vector<int>, string);
vector <string> setColors(vector <string>, string);
void colorSimilarity(vector<string>);


//declaring global variables

vector<int> rgbVals;
vector<string> newColor;
vector<double> greyScales;
vector<string> dominances;

//converts hex string input to decimal format (2 digit) if viable digits
int rgbConvert(string h){
  int val1=-1;
  int val2=-1;
  int valtot;
  if (h[0] == 'a'||h[0]=='A') {val1= 10; }
  if (h[0] == 'b'||h[0]=='B') {val1= 11; }
  if (h[0] == 'c'||h[0]=='C') {val1= 12; }
  if (h[0] == 'd'||h[0]=='D') {val1= 13; }
  if (h[0] == 'e'||h[0]=='E') {val1= 14; }
  if (h[0] == 'f'||h[0]=='F') {val1= 15; }
  if (h[0]=='0'){ val1 = 0;}
  if (h[0]=='1'){ val1 = 1;}
  if (h[0]=='2'){ val1 = 2;}
  if (h[0]=='3'){ val1 = 3;}
  if (h[0]=='4'){ val1 = 4;}
  if (h[0]=='5'){ val1 = 5;}
  if (h[0]=='6'){ val1 = 6;}
  if (h[0]=='7'){ val1 = 7;}
  if (h[0]=='8'){ val1 = 8;}
  if (h[0]=='9'){ val1 = 9;}
  if (h[1] == 'a'||h[1]=='A') {val2= 10; }
  if (h[1] == 'b'||h[1]=='B') {val2= 11; }
  if (h[1] == 'c'||h[1]=='C') {val2= 12; }
  if (h[1] == 'd'||h[1]=='D') {val2= 13; }
  if (h[1] == 'e'||h[1]=='E') {val2= 14; }
  if (h[1] == 'f'||h[1]=='F') {val2= 15; }
  if (h[1]=='0'){ val2 = 0;}
  if (h[1]=='1'){ val2 = 1;}
  if (h[1]=='2'){ val2 = 2;}
  if (h[1]=='3'){ val2 = 3;}
  if (h[1]=='4'){ val2 = 4;}
  if (h[1]=='5'){ val2 = 5;}
  if (h[1]=='6'){ val2 = 6;}
  if (h[1]=='7'){ val2 = 7;}
  if (h[1]=='8'){ val2 = 8;}
  if (h[1]=='9'){ val2 = 9;}
  valtot= (16*val1);
  valtot += val2;
  if (val1<0||val2<0){
    return -1;
  }
  else return valtot;
}
//converts hex string input to decimal format (1 digit) if viable digit
int rgbConvertOneDig(string h){
  int val=-1;
  if (h[0] == 'a'||h[0]=='A') {val= 10; }
  if (h[0] == 'b'||h[0]=='B') {val= 11; }
  if (h[0] == 'c'||h[0]=='C') {val= 12; }
  if (h[0] == 'd'||h[0]=='D') {val= 13; }
  if (h[0] == 'e'||h[0]=='E') {val= 14; }
  if (h[0] == 'f'||h[0]=='F') {val= 15; }
  if (h[0]=='0'){ val = 0;}
  if (h[0]=='1'){ val = 1;}
  if (h[0]=='2'){ val = 2;}
  if (h[0]=='3'){ val = 3;}
  if (h[0]=='4'){ val = 4;}
  if (h[0]=='5'){ val = 5;}
  if (h[0]=='6'){ val = 6;}
  if (h[0]=='7'){ val = 7;}
  if (h[0]=='8'){ val = 8;}
  if (h[0]=='9'){ val = 9;}
  return val;
}
//aranges decimal rgb values into rgb format and returns vector of all rgb values
vector < int > rgbFormat(vector < int > list, string hex) {

  if ((getR(hex) > 0) && (getR(hex) < 256) && (getB(hex) > 0) && (getB(hex) < 256) && (getG(hex) > 0) && (getG(hex) < 256)) {

    list.push_back(getR(hex));
    list.push_back(getG(hex));
    list.push_back(getB(hex));
  }
  return list;
}
//function to display a vector full of integrers
void displayInt(vector < int > nums) {
  for (int i = 0; i < nums.size(); i += 3)
    cout << "(" << nums[i] << ", " << nums[i + 1] << ", " << nums[i + 2] << ")\n";
}
//function to display a vector of doubles
void displayDouble(vector < double > num) {
  //cout << "GreyValues:\n";
  for (int i = 0; i < num.size(); i++) {
    cout << num[i] << endl;
  }
}


//function to create a vector full of hex color codes found to be viable in the rgbConvert function- removes any strings mistaken for hex color codes
vector < string > setColors(vector < string > colors, string hex) {

  if ((getR(hex) > 0) && (getR(hex) < 256) && (getB(hex) > 0) && (getB(hex) < 256) && (getG(hex) > 0) && (getG(hex) < 256)) {
    colors.push_back(hex);

  }
  return colors;
}
//function to display a vector full of strings
void displayString(vector < string > elements) {
  for (int i = 0; i < elements.size(); i++) {
    cout << elements[i] << endl;
  }
}
//function to determine closest color to the color code between greyscale, red, green, blue, purple, yellow, and turquoise. Greyscale is any color that is very washed out and hard to determine without being colorblind, not strictly black and white tones. 
vector < string > dominance(vector < string > hex) {
  vector < string > dominance;

  for (int i = 0; i < hex.size(); i++) {
    int r = getR(hex[i]);
    int g = getG(hex[i]);
    int b = getB(hex[i]);

    if ((r == g && r == b)||((r-g)>-30 && (r-g) <30 && (r-b) >-30 && (r-b) <30 && (b-g)<30 && (b-g) >-30)) {
      dominance.push_back("greyscale");
    }

    else if ((r > b + 30) && (r > g + 30)) {
      dominance.push_back("red");
    }
    else if (g > r + 30 && g > b + 30) {
      dominance.push_back("green");
    }
    else if (b > r + 30 && b > g + 30) {
      dominance.push_back("blue");
    }
    else if(abs(b-r) < abs(b-g)&&(b>g&&r>g)){
      dominance.push_back("purple");
    }
    else if(abs(b-g) < abs(b-r)&& (b>r)&&(g>r)){
      dominance.push_back("turquoise");
    }
    else if(abs(r-g) < abs(r-b)&&(g>b)&&(r>b)){
      dominance.push_back("yellow");
    
    }
     else {
      dominance.push_back("blended");
    }
  }
  return dominance;
}
//finds the Grey scale value of a hex color
vector < double > greyValue(vector < string > hex) {
  vector < double > greyScale;
  for (int i = 0; i < hex.size(); i++) {

    greyScale.push_back((.299 * getR(hex[i])) + (.587 * getG(hex[i])) + (.114 * getB(hex[i])));
  }

  return greyScale;
}
//getX functions: retrieve the r, g, or b values from a hex color code. 
int getR(string & hex) {

  string r;
  if (hex.length() == 6) {
    r = hex.substr(0, 2);
    return rgbConvert(r);

  } else if (hex.length() < 6) {
    hex = hex.substr(0, 3);
    r = hex.substr(0, 1);
    return rgbConvertOneDig(r);
  }
  return -1;
}
int getG(string & hex) {

  string g;
  if (hex.length() == 6) {
    g = hex.substr(2, 3);
    return rgbConvert(g);

  } else if (hex.length() < 6) {
    hex = hex.substr(0, 3);
    g = hex.substr(1, 2);
    return rgbConvertOneDig(g);

  }
  return -1;
}
int getB(string & hex) {

  string b;
  if (hex.length() == 6) {
    b = hex.substr(4, 5);
    return rgbConvert(b);
  } else if (hex.length() < 6) {
    hex = hex.substr(0, 3);
    b = hex.substr(2, 3);
    return rgbConvertOneDig(b);
  }
  return -1;

}
//checks to see if color entry from file is unique or a duplicate
bool isUnique(vector < string > list, string color) {
  for (int i = 0; i < list.size(); i++) {
    if (list[i] == color) {
      return false;
    }

  }
  return true;
}
//counts and displays # of each color for analysis
void colorSimilarity(vector<string> doms){
  int r=0;
  int g=0;
  int b=0;
  int y=0;
  int p=0;
  int t=0;
  int gs=0;
  

  for(int i=0; i<doms.size();i++){
    if(doms[i]=="red"){
      r+=1;
    }  
    else if(doms[i]=="green"){
      g+=1;
    }  
    else if(doms[i]=="blue"){
      b+=1;
    } 
    else if(doms[i]=="yellow"){
      y+=1;
    } 
    else if(doms[i]=="purple"){
      p+=1;
    } 
    else if(doms[i]=="turquoise"){
      t+=1;}
    else if(doms[i]== "greyscale"){
      gs+=1;
    }
  }
  
  
  cout<< "reds: "<<r<<endl;
  cout<< "greens: "<<g<<endl;
  cout<< "blues: "<<b<<endl;
  cout<< "yellow: "<<y<<endl;
  cout<< "turquoise: "<<t<<endl;
  cout<< "purple: "<<p<<endl;
  cout<< "GreyScale: "<<gs<<endl;


}
int main() {
  string file, input;
  fstream reader;
  colorList cList;
  char choice = 'y';
  //Prompt User to Enter File Name For Analysis
  while (choice == 'y' || choice == 'Y') {
    cout << "File to open:\n";
    cin >> file;
    reader.open(file, ios:: in );
    vector < string > colors;
    string num = "";
    //If Successful Open of File, start analysis  
    if (reader.is_open()) {
      while (!reader.eof()) {
        getline(reader, input);
        //search through file for hex code colors
        for (int i = 0; i < input.length(); i++) {
          if (input[i] == '#') {
            //search for end of hex code and save the digits as a string
            for (int digit = 1; digit < 7; digit++) {
              if (input[i + digit] == ';') {
                break;
              }
              num += (input[i + digit]);

            }

            {
              //add the hex number to a string "colors" if unique
              if (isUnique(colors, num)) {
                colors.push_back(num);
              }
            }
            num = "";
          }
        }
      }

      //assigns vectors to outputs of previous major functions and prints the color codes in hex and rgb form, greyscale values, and dominance
      for (int i = 0; i < colors.size(); i++) {
        newColor = setColors(newColor, colors[i]);

        rgbVals = rgbFormat(rgbVals, colors[i]);

        greyScales = greyValue(newColor);

        dominances = dominance(newColor);
      }
      displayString(newColor);
      displayInt(rgbVals);
      displayDouble(greyScales);
      displayString(dominances);
      cList.getColors(dominances);
      cList.colorConflictsRG();
      cList.colorConflictsBY();
      
      reader.close();
      ofstream output;
      output.open("output.txt");
      for (int i = 0; i < newColor.size(); i++) {
        output << newColor[i] + "\n";
        //numerical outputs must be converted to strings before outputing to file
        // output << rgbVals[i]+"\n";
        //output << greyScales[i]+"\n";
        output << dominances[i] + "\n";

      }
      output.close();
    }

    //if file does not open
    else {
      cout << "Could not open file." << endl;

    }
    //after analysis or failure to open ask if another file is wanted to be analysed. 
    cout << "Analyze another file (y/n)?" << endl;
    cin >> choice;
    cin.ignore();
  }

  return 0;
}






