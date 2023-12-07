#ifndef PATIENTINFO_H
#define PATIENTINFO_H

#include <iostream>
#include <fstream>
#include "HealthChecker.h"
using namespace std;

class PatientInfo : public HealthChecker {
  private:
    string fileName;
    void saveToFile();

  public:
    PatientInfo(const string& fileName);
    // ~PatientInfo(); // Destructor to free allocated memory
    void getUserData();
};

#endif // PATIENTINFO_H
