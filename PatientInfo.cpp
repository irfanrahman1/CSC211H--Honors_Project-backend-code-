#include "PatientInfo.h"
using namespace std;

PatientInfo::PatientInfo(const string &fileName)
    : HealthChecker(), fileName(fileName) {}

// PatientInfo::~PatientInfo() {d
// }

void PatientInfo::getUserData() {
  HealthChecker::getAgeandName();
  HealthChecker::getBloodPressure();
  HealthChecker::getGlucoseLevels();
  HealthChecker::getCholesterolLevels();
  saveToFile();
}

void PatientInfo::saveToFile() {
  ofstream outFile(fileName, ios::app);
  if (outFile.is_open()) {
    try {
      outFile << *this; // Utilize the overloaded << operator to print patient
                        // information
      outFile << "-------------------------\n";
    } 
    catch (const exception &e) {
      cerr << "Error writing to file: " << e.what() << "\n";
    }

    outFile.close();
    cout << "Patient information saved to " << fileName << "\n";
  } 
  else {
    cerr << "Error opening the file for saving.\n";
  }
}
