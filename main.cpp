#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "RAILWAYS.h" 
using namespace std;



void displayMenu()
{
  cout << "\n*********** Railway Station Management ***********" << endl;
  cout << "1. View available stations" << endl;
  cout << "2. Add a new station" << endl;
  cout << "3. Schedule a train at a station" << endl;
  cout << "4. Exit" << endl;
  cout << "*************************************************" << endl;
  cout << "Enter your choice: ";
}


int main()
{
  R_Manager rm;
  
  int choice;

  while (true)
  {
    displayMenu();
    cin >> choice;

    switch (choice)
    {
    case 1:
      rm.viewStations();
      break;
    case 2:
      rm.addStation();
      break;
    case 3:
      rm.scheduleTrain();
      break;
    case 4:
      cout << "Exiting program." << endl;
      return 0;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}
