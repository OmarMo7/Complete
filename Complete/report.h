#include <string>
using namespace std;
string GetInput(string additional = "  "){
  string input;

  if (additional != "  ") cout << additional << ": ";

  getline(cin, input);

	return input;
}

void askingForReport(){
        string answer = GetInput("Do you wish to play again? \n");
        char index = answer[0];

        if(index =='y') menu();
        else if(index =='n')return;
        else cout<<"please, focus and enter a valid char /n"; break;
    return askingForReport();


}
