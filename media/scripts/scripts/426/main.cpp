#include <fstream>

using namespace std;

int a;

ifstream in("input.txt");
ofstream out("output.txt");

int main(){
    in >> a ;
  if( (a<38) && (a>=0))
    out << a;
  else 
     if (a%5>=3)
     { a=a+(5-a%5);
      out<<a;}
     else out<<a;
  
  
    
    return 0;
}