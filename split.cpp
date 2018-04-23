#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost;

void print( vector <string> & v )
{
  for (size_t n = 0; n < v.size(); n++)
    cout << "\"" << v[ n ] << "\"\n";
  cout << endl;
}

int main()
{
  string s = "a,b, c ,,e,f,";
  vector <string> fields;

  cout << "Original = \"" << s << "\"\n\n";

  cout << "Split on \',\' only\n";
  split( fields, s, is_any_of( "," ) );
  print( fields );

  cout << "Split on \" ,\"\n";
  split( fields, s, is_any_of( " ," ) );
  print( fields );

  cout << "Split on \" ,\" and elide delimiters\n"; 
  split( fields, s, is_any_of( " ," ), token_compress_on );
  print( fields );

  return 0;
}



#include <string.h>
#include <stdio.h>
 
int main(){
    char s[] = "a,b*c,d";
    const char *sep = ",*"; //可按多个字符来分割
    char *p;
    p = strtok(s, sep);
    while(p){
        printf("%s ", p);
        p = strtok(NULL, sep);
    }
    printf("\n");
    return 0;
}