HOW DIFFICULT IS IT TO READ YOUR SITE FOR COLORBLIND PEOPLE?

Inputing a CSS File should reslut in a grading of how difficult it is to read your site for people with different types of colorblindess. 

### v0.1 Updates

Added ability to input CSS File, Curently searches through file for hex color codes. 
Outputs color codes in string list. 
Next step is to convert hex codes to integers for analysis. 
Also adding implimentation for RGBA codes. 

### v0.2 Updates

*Coming soon*

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
g++ --std=c++11 *.cpp -o cvp;
./cvp
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
dff0d8
c1e2b3
d9edf7
afd9ee
f7ecb5
f2dede
e4b9b9
eeeeee
Analyze another file (y/n)?
n
```

## C++ Guide

### Variables and Data Types

Uses a temporary string num to assign individual hex codes before amedning them to a string colors for output. Uses an int i to iterate through the file looking for hex codes. Uses a char choice to determine if the program should prompt for a file to open. 

### Console Input and Output

Program outputs a prompt for the user to input a file name. Prompts user to input a char to determine if the program should prompt for another file name. 

### Decisions

Uses if statements to determine if program should prompt for a file input again. Uses if statements to determine if the program finds certain characters that denote a hexcode such as a # followed by a ; several characters later. 

### Iteration

Iterates and loops through the file inputed looking for certain characters and recording hex codes for analysis. 

### File Input and Output

User inputs a file using fstream reader by entering file name when prompted. Outputs list of hex color codes to output.txt file. 

### Arrays/Vectors

*Coming in version 0.2*

### Functions

*Coming in version 0.2*

### Classes

*Coming in version 1.0*
