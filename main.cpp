#include "PatientInfo.h"
#include <iostream>
using namespace std;

int main() {
  try {
    string patientFileName = "patient_info.txt";

    // Create a PatientInfo object with the specified patient file name
    PatientInfo patientInfo(patientFileName);

    // Call the getUserData method to gather user information and save it to the file
    patientInfo.getUserData();

    // Call the checkHealth method to perform health checks based on the collected information
    patientInfo.checkHealth();
  } 
  catch (const exception &e) {
    // Catch and handle exceptions if any occur during the execution
    cerr << "An exception occurred: " << e.what() << "\n";
  }

  return 0;
}