#include <fstream> 
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

//Part 1
int main() {

  stringstream stream ("52500467-52574194,655624494-655688785,551225-576932,8418349387-8418411293,678-1464,33-79,74691-118637,8787869169-8787890635,9898977468-9899009083,548472423-548598890,337245835-337375280,482823-543075,926266-991539,1642682920-1642753675,3834997-3940764,1519-2653,39697698-39890329,3-21,3251796-3429874,3467-9298,26220798-26290827,80-124,200638-280634,666386-710754,21329-64315,250-528,9202893-9264498,819775-903385,292490-356024,22-32,2663033-2791382,133-239,56514707-56704320,432810-458773,4949427889-4949576808");
  string parsedString;
  int counter = 0;
  char commaDelimeter = ',';
  long long invalidIDs = 0;
  while (getline(stream, parsedString, commaDelimeter))
  {
        int rangeDivider = parsedString.find("-");
        long long firstID = stoll(parsedString.substr(0, rangeDivider));
        long long lastID = stoll(parsedString.substr(rangeDivider + 1));
        cout << "firstID:" << firstID << endl;
        cout << "lastID:" << lastID << endl;
        cout << sizeof(firstID) << endl;
        
       for (long long id = firstID; id <= lastID; id++){
        
          string strID = to_string(id);
          if (strID.length() % 2 != 0) continue;
          int half = strID.length() / 2;

          long long firstSection = stoll(strID.substr(0,half));
          long long secondSection = stoll(strID.substr(half));
          
           if(firstSection == secondSection ){
             invalidIDs += id;
           }
          
        }
  }
  cout << "invalidIDs:" << invalidIDs;
}
