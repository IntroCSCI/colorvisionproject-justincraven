#ifndef COLORLIST_H
#define COLORLIST_H
#include <string>
#include <vector>


using std::string;
using std::vector;

class colorList
{
  private: // Only can be used directly INSIDE this class
      int r;
      int g;
      int b;
      int y;
      int p;
      int t;
      int gs;
      vector <int> colorNums;
      double total;
    int blue;
    int green;
    int red;
    int yellow;
    int purple;
    int turq;
    int grey;
  public: // Can be used directly INSIDE and OUTSIDE this class
    void getColors(vector<string>);
    void colorConflictsRG();
    void colorConflictsBY();
    colorList();
     

};

#endif