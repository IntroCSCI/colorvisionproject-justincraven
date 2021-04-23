HOW DIFFICULT IS IT TO READ YOUR SITE FOR COLORBLIND PEOPLE?
 
Inputing a CSS File should result in a grading of how difficult it is to read your site for people with different types of colorblindness.
 
### v0.1 Updates
 
Added ability to input CSS File, Currently searches through file for hex color codes.
Outputs color codes in string list.
Next step is to convert hex codes to integers for analysis.
Also adding implementation for RGBA codes.
 
### v0.2 Updates
streamlined and corrected color code inputs.
Converts hex codes into rgb codes for analysis.
determines the greyscale value of each unique color.
determines the closest color of each color code between greyscale, red, blue, green, yellow, purple, and turquoise. 
counts the number of each color for analysis.
 
in future plan to determine which colors conflict with different types of colorblindness, determine if color combinations of css file conflict.
### v1.0 Updates
 
*Coming soon*
 
 
## Developer
 
Justin Craven
 
## Example
 
To run the program, give the following commands:
 
```
g++ --std=c++11 *.cpp -o cvp
./cvp
```
 
Here is an example of the program running:
 
```
g++ -std=c++11 *.cpp -o cvp; ./cvp
File to open:
test.css
fcf8e3
777777
428bca
3071a9
3c763d
2b542c
31708f
245269
8a6d3b
66512c
a94442
843534
fff
c1e2b3
d9edf7
afd9ee
f7ecb5
f2dede
e4b9b9
eeeeee
dff0d8
(252, 248, 227)
(119, 119, 119)
(66, 139, 202)
(48, 113, 169)
(60, 118, 61)
(43, 84, 44)
(49, 112, 143)
(36, 82, 105)
(138, 109, 59)
(102, 81, 44)
(169, 68, 66)
(132, 53, 52)
(15, 15, 15)
(193, 226, 179)
(217, 237, 247)
(175, 217, 238)
(247, 236, 181)
(242, 222, 222)
(228, 185, 185)
(238, 238, 238)
(223, 240, 216)
246.802
119
124.355
99.949
94.16
67.181
96.697
70.868
111.971
83.061
97.971
76.507
15
210.775
232.16
206.836
233.019
227.98
197.857
238
232.181
greyscale
greyscale
blue
blue
green
green
blue
turquoise
yellow
yellow
red
red
greyscale
green
turquoise
turquoise
yellow
greyscale
red
greyscale
greyscale
reds: 3
greens: 3
blues: 3
yellow: 3
turquoise: 3
purple: 0
GreyScale: 6
Analyze another file (y/n)?
n
```
 
## C++ Guide
 
### Variables and Data Types
 
Takes a string inputs from the file and adds it to a vector for analysis. Uses the int i to iterate through the file looking for hex codes as well as several different vectors. Uses a char choice to determine if the program should prompt for a file to open.
 
use of vectors that use data types string, int, and double. Bool outputs exist from some of the functions.
 
### Console Input and Output
 
Program outputs a prompt for the user to input a file name. Prompts user to input a char to determine if the program should prompt for another file name. Outputs all derived data from the file.
 
### Decisions
 
Uses if statements to determine if the program should prompt for a file input again. Uses if statements to determine if the program finds certain characters that denote a hexcode such as a # followed by a ; several characters later.
if statements also exist in almost every function.
 
### Iteration
 
Iterates and loops through the file inputed looking for certain characters and recording hex codes for analysis.
makes use of several for loops to scan through various arrays.
 
### File Input and Output
 
User inputs a file using fstream reader by entering the file name when prompted. Outputs derived data to output.txt file.
 
### Arrays/Vectors
 
Makes use of several vectors to store color codes of each type.
Examples include  rgbVals, newColor, greyScales, and dominances.
Arrays store a range of data types including strings, doubles, and integers.
### Functions
Makes use of several pass by value functions including:
bool isUnique(vector<string>, string);
vector <double> greyValue(string);
vector <string> dominance(vector <string>);
void displayString(vector<string>);
void displayInt(vector<int>);
void displayDouble(vector<double>);
void displayDominance(vector<string>);
int rgbConvert(string);
int rgbConvertOneDig(string);
vector <int> rgbFormat(vector<int>, string);
vector <string> setColors(vector <string>, string);
void colorSimilarity(vector<string>);
 
also makes use of 3 pass by reference functions.
int getR(string&);
int getG(string&);
int getB(string&);
 
 
### Classes
 
*Coming in version 1.0*
 

