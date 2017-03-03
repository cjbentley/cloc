//Cameron Bentley
//cloc - count lines of code

#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {
  if(argc==1) {
    cout << "cloc: count lines of code" << endl << endl;
    cout << "usage: cloc [--scriptfriendly] filename.txt filename2.txt" << endl;
    cout << "Outputs the name of the file (when --scriptfriendly isn't there) and lines of code." << endl;
    cout << "No file limit!" << endl;
    cout << "Created by Cameron Bentley. Code available at github.com/cjbentley/cloc." << endl << endl;
    return 0;
  }

  bool scriptFriendly = false;
  int i = 1;

  if (strcmp(argv[i], "--scriptfriendly")==0) {
    scriptFriendly = true;
    i=i+1;
  }

  for(i=i; i<argc; i++) {
    ifstream file (argv[i]);

    if(file) {
      int loc = 0;
      for(string x = ""; getline(file, x); loc=loc+1) {} //getline reads each line of the file in order and returns 0 when it fails
      file.close();

      if (scriptFriendly == false) {
        cout << "loc " << argv[i] << ": ";
      }
      cout << loc << endl;
    }
    else {
      cout << "Error loading file " << argv[i] << endl;
    }
  }
  return 0;
}
