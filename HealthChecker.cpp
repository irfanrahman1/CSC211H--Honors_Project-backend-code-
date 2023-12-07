// HealthChecker.cpp

#include "HealthChecker.h"
#include <limits> // this line for numeric_limits
using namespace std;

// HealthChecker class implementation

HealthChecker::HealthChecker() {
  name = new string; // Allocate memory for the name
  diabetesFlag = false;
  bloodPressureFlag = false;
  cholesterolFlag = false;
}

HealthChecker::~HealthChecker() {
  delete name; // Free the allocated memory
}

// Method to get user data
void HealthChecker::getUserData() {
  getAgeandName();
  getBloodPressure();
  getGlucoseLevels();
  getCholesterolLevels();
}

// Method to perform health checks
void HealthChecker::checkHealth() {
  checkDiabetes();
  checkBloodPressure();
  checkCholesterol();
  if (diabetesFlag || bloodPressureFlag || cholesterolFlag) {
    cout << "Your overall health condition is not optimal. ";
    if (diabetesFlag && bloodPressureFlag && cholesterolFlag) {
      cout << "You have multiple health issues. ";
    }
    cout << "Schedule an appointment with your doctor.\n";
  } 
  else {
    cout << "Your health condition seems manageable. Consider taking some rest "
            "and rechecking later.\n";
  }
}

void HealthChecker::getAgeandName() {
  cout << "Enter your full name: ";
  getline(cin, *name);
  while (true) {
    cout << "Enter your age: ";
    try {
      cin >> age;

       // Handle invalid age input
      if (cin.fail()) {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n'); // discard invalid input
        throw runtime_error("Invalid age input. Please enter a valid integer.");
      }

      if (age <= 0 || age > 150) {
        throw out_of_range(
            "Invalid age. Please enter an age between 0 and 150.");
      }
      break;
    } 
    catch (const exception &e) {
      cerr << "Error: " << e.what() << "\n";
    }
  }
}

void HealthChecker::getBloodPressure() {
  while (true) {
    cout << "Enter your systolic blood pressure (mmHg): ";
    cin >> systolicBP;
    if (systolicBP >= 60 && systolicBP <= 220) {
      break;
    } 
    else {
      cout << "Invalid systolic blood pressure. Please enter a valid value.\n";
    }
  }

  while (true) {
    cout << "Enter your diastolic blood pressure (mmHg): ";
    cin >> diastolicBP;
    if (diastolicBP >= 40 && diastolicBP <= 160) {
      break;
    } 
    else {
      cout << "Invalid diastolic blood pressure. Please enter a valid value.\n";
    }
  }
}

void HealthChecker::getGlucoseLevels() {
  while (true) {
    cout << "Enter your fasting glucose level (mg/dL): ";
    cin >> fastingGlucose;
    if (fastingGlucose > 40 && fastingGlucose <= 300) {
      break;
    } 
    else {
      cout << "Invalid fasting glucose level. Please enter a valid value.\n";
    }
  }

  while (true) {
    cout << "Enter your HbA1c level (%): ";
    cin >> hba1c;
    if (hba1c >= 4 && hba1c <= 15) {
      break;
    } 
    else {
      cout << "Invalid HbA1c level. Please enter a valid value.\n";
    }
  }
}

void HealthChecker::getCholesterolLevels() {
  while (true) {
    cout << "Enter your LDL cholesterol level (mg/dL): ";
    cin >> ldlCholesterol;
    if (ldlCholesterol > 50 && ldlCholesterol <= 250) {
      break;
    } 
    else {
      cout << "Invalid LDL cholesterol level. Please enter a valid value.\n";
    }
  }

  while (true) {
    cout << "Enter your HDL cholesterol level (mg/dL): ";
    cin >> hdlCholesterol;
    if (hdlCholesterol > 20 && hdlCholesterol <= 100) {
      break;
    }
    else {
      cout << "Invalid HDL cholesterol level. Please enter a valid value.\n";
    }
  }
}

void HealthChecker::checkDiabetes() {
  if (fastingGlucose >= 126 || hba1c >= 6.5) {
    cout << "You might have diabetes. Immediate medication: Insulin or oral "
            "antidiabetic medication.\n";
    diabetesFlag = true;
  }
}

void HealthChecker::checkBloodPressure() {
  if (systolicBP >= 140 || diastolicBP >= 90) {
    cout << "You might have high blood pressure. Immediate medication: "
            "Antihypertensive medication.\n";
    bloodPressureFlag = true;
  } 
  else if (systolicBP < 90 || diastolicBP < 60) {
    cout << "You might have low blood pressure. Consider increasing your salt "
            "intake and staying hydrated.\n";
    bloodPressureFlag = true;
  } 
  else {
    cout << "Your blood pressure is within the normal range.\n";
  }
}

void HealthChecker::checkCholesterol() {
  if (ldlCholesterol >= 130) {
    cout << "You might have high LDL cholesterol. Immediate medication: "
            "Statins or other cholesterol-lowering medications.\n";
    cholesterolFlag = true;
  }

  if (hdlCholesterol < 40) {
    cout << "You might have low HDL cholesterol. Consider lifestyle changes "
            "and consult a healthcare professional.\n";
    cholesterolFlag = true;
  }
}

ostream &operator<<(ostream &os, const HealthChecker &healthChecker) {
  os << "Patient Information:\n";
  os << "Name: " << *healthChecker.name << "\n";
  os << "Age: " << healthChecker.age << "\n";
  os << "Blood Pressure: " << healthChecker.systolicBP << "/"
     << healthChecker.diastolicBP << " mmHg\n";
  os << "Fasting Glucose: " << healthChecker.fastingGlucose << " mg/dL\n";
  os << "HbA1c: " << healthChecker.hba1c << "%\n";
  os << "LDL Cholesterol: " << healthChecker.ldlCholesterol << " mg/dL\n";
  os << "HDL Cholesterol: " << healthChecker.hdlCholesterol << " mg/dL\n";

  return os;
}
