#include "colorList.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
using std::string;
using std::vector;


colorList::colorList(){
r = 0;
b = 0;
g = 0;
y = 0;
p = 0;
t = 0;
gs = 0;
colorNums = {};


}
void colorList::getColors(vector<string> doms){
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
  colorNums.push_back(r);
  colorNums.push_back(g);
  colorNums.push_back(b);
  colorNums.push_back(y);
  colorNums.push_back(p);
  colorNums.push_back(t);
  colorNums.push_back(gs);
  cout<< "reds: "<<r<<endl;
  cout<< "greens: "<<g<<endl;
  cout<< "blues: "<<b<<endl;
  cout<< "yellow: "<<y<<endl;
  cout<< "turquoise: "<<t<<endl;
  cout<< "purple: "<<p<<endl;
  cout<< "GreyScale: "<<gs<<endl;
  blue = colorNums[2];
  green = colorNums[1]; 
  red = colorNums[0];
  yellow = colorNums[3];
  purple = colorNums[4];
  turq = colorNums[5];
  grey = colorNums[6];
}

void colorList::colorConflictsRG(){
  

  total = blue+green+red+yellow+purple+turq+grey;
  int red = colorNums[0];
  int green = colorNums[1];
  if ((red>0 && green>0)){
    cout<< "The file uses Red and Green colors which could create conflicts for people with red/green colorblindess (deuteranopia/Deueranomaly/Protanopia/Protanomaly)\n";
    if(red/total >.2&& green/total >.2){
      cout << "A large percentage of the coors are green and red which will most likely cause issues for people with red/green Colorblindess\n"; 
    }
  }
  
  else cout<< "No red green Conflicts\n";
}

void colorList::colorConflictsBY(){
  int issues = 0;
  
  total = blue+green+red+yellow+purple+turq+grey;

  if ((blue>0 && green>0)){
    cout<< "The file uses Blue and Green colors which could create conflicts for people with Tritanomaly/Tritanopia\n";
    issues++;
    if(blue/total >.2&& green/total >.2){
      cout << "A large percentage of the colors are blue and green which will most likely cause issues for people with Tritanomaly/Tritanopia\n"; 
    }
  }
  if(yellow>0 && red>0){
    cout<<"The file uses Red and Yellow colors which could create conflicts for people with  Tritanomaly\n";
    issues++;
    if(yellow/total >.2&& red/total >.2){
      cout << "A large percentage of the colors are yellow and red which will most likely cause issues for people with Tritanomaly\n";
  }
  }
  if(purple>0&&red>0){
    cout<< "The file uses Purple and Red colors which could create conflicts for people with Tritanopia\n";
    issues++;

    if(purple/total >.2&& red/total >.2){
      cout << "A large percentage of the colors are purple and red which will most likely cause issues for people with Tritanopia\n";
    }
  }
  else if (issues ==0){ cout<< "No Blue-Yellow Conflicts\n";}
}


