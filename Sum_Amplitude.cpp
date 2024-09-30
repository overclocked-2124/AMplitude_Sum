#include <iostream>
#include <cmath> 
#include <iomanip>  // For controlling output formatting
#include <fstream>
using namespace std;

int main() {
    float t, a1, a2, x, y, sum, freq1, freq2, w1, w2, tmax, m;
    
    // Open file for writing (CSV format)
    ofstream fout("Amplitude-Sum.csv");
    
    // Check if the file was opened successfully
    if (!fout.is_open()) {
        cerr << "Error: Could not open file 'Amplitude-Sum.csv' for writing!" << endl;
        return 1;  // Exit with an error code
    }

    // Get input from the user
    cout << "Please enter the interval at which to increase time: ";
    cin >> m;
    cout << "Please enter until what time to calculate: ";
    cin >> tmax;
    cout << "Please enter maximum amplitude of wave 1: ";
    cin >> a1;
    cout << "Please enter maximum amplitude of wave 2: ";
    cin >> a2;
    cout << "Please enter frequency of wave 1: ";
    cin >> freq1;
    cout << "Please enter frequency of wave 2: ";
    cin >> freq2;

    const float pi = 3.14159265;
    
    // Calculate angular frequencies
    w1 = 2 * pi * freq1;
    w2 = 2 * pi * freq2;
    
    // Initialize time to 0
    t = 0.0;
    
    // Write CSV headers (for Excel)
    fout << "Time (s),Resultant Amplitude" << endl;
    
    // Loop to iterate through time
    while (t <= tmax) {
        // Calculate wave amplitudes at time t
        x = a1 * sin(w1 * t);
        y = a2 * sin(w2 * t);
        sum = x + y;
        
        // Display the resultant amplitude on the console (optional)
        cout << "At time t = " << t << " : Resultant amplitude = " << sum << endl;
        
        // Write formatted output to the CSV file
        fout << fixed << setprecision(3) << t << "," << sum << endl;
        
        // Increment time by step size m
        t += m;
    }
    
    // Close file after writing
    fout.close();
    
    // Confirmation message
    cout << "File 'Amplitude-Sum.csv' has been successfully created!" << endl;

    return 0;
}
