#ifndef HEALTHCHECKER_H
#define HEALTHCHECKER_H

#include <iostream>
using namespace std;

// HealthChecker class declaration
class HealthChecker {
  protected:
    string* name;       // Pointer to store the user's name
    int age;            // Variable to store the user's age

    // Helper methods for getting user data
    void getAgeandName();
    void getBloodPressure();
    void getGlucoseLevels();
    void getCholesterolLevels();

     // Variables for storing health info
    int systolicBP, diastolicBP;
    int fastingGlucose;
    float hba1c;
    int ldlCholesterol, hdlCholesterol;

  private:

    // Flags to indicate specific health conditions
    bool diabetesFlag;
    bool bloodPressureFlag;
    bool cholesterolFlag;

    // Helper methods for checking specific health conditions
    void checkDiabetes();
    void checkBloodPressure();
    void checkCholesterol();

  public:
    // Constructor and Destructor
    HealthChecker();
    ~HealthChecker(); // Destructor to free allocated memory

    // Method to get user data
    void getUserData();

    // Method to perform health checks
    void checkHealth();

    // Operator overloading for stream insertion
    friend ostream& operator<<(ostream& os, const HealthChecker& healthChecker);
};
#endif // HEALTHCHECKER_H