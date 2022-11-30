// all libraries and type standard
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

// constant values
const int VEHICLE_WIEGHT = 5000;
const int NORMAL_VEHICLE_SPEED_LIMIT = 45;
const int HEAVY_VEHICLE_SPEED_LIMIT = 30;
const int ARRAY_SIZE = 2000;

// the main body
int main()
{

    // declared values, arrays, files, and counts
    ifstream ifile;
    ofstream ofile;
    string fileName = " ";
    string licencePlates[ARRAY_SIZE], licencePlatesOfViolations[ARRAY_SIZE];
    string dates[ARRAY_SIZE], datesOfViolations[ARRAY_SIZE];
    string times[ARRAY_SIZE], timesOfViolations[ARRAY_SIZE];
    string weights[ARRAY_SIZE];
    string speeds[ARRAY_SIZE];
    int speedViolation = 0, count = 0;

    int int1 = 0;
    int int2 = 0;
    // declare second set of variables
    string licencePlate = " ";
    string date = " ", previousDate = " ";
    string time = " ";
    string weight = " ";
    string speed = " ";
    string fileTextDate = " ";

    // open and check file input from user
    do
    {
        cout << "Open File: ";
        getline(cin, fileName);
        ifile.open(fileName);

        // repeat if file name error
        if (!ifile.is_open())
        {
            ifile.clear();
            ifile.ignore(10000, '\n');
            cout << "Could not open " << fileName << endl;
        }

    } while (!ifile.is_open());

    bool violation = false;
    // read files contents to licene plate, date, time, weight, and speed
    while (!ifile.eof())
    {
        violation = false;

        // reading files into strings
        getline(ifile, licencePlate, ',');
        // licencePlates[count] = licencePlate;
        getline(ifile, date, ',');
        // dates[count] = date;
        getline(ifile, time, ',');
        // times[count] = "[" + time + "]";
        getline(ifile, weight, ',');
        // weights[count] = weight;
        getline(ifile, speed, '\n');
        // speeds[count] = speed;

        cout << date << " " << time << " " << licencePlate << endl;

        int1 = stoi(weight);
        int2 = stoi(speed);

        if (int1 < VEHICLE_WIEGHT && int2 > NORMAL_VEHICLE_SPEED_LIMIT)
        {
            violation = true;
            // speedViolation++;
        }
        else if (int1 > VEHICLE_WIEGHT && int2 > HEAVY_VEHICLE_SPEED_LIMIT)
        {
            violation = true;
            // speedViolation++;
        }

        if (violation == true)
        {
            if (count == 0)
            {
                previousDate = date;
                fileTextDate = "[" + date + "]" + " Report.txt";
                ofile.open(fileTextDate);
            }

            count++;

            if (date == previousDate)
            {
                ofile << "[" << time << "]"
                      << " " << licencePlate << endl;
            }
            else
            {
                ofile.close();
                fileTextDate = "[" + date + "]" + " Report.txt";
                ofile.open(fileTextDate);
                ofile << time << " " << licencePlate << endl;
                previousDate = date;
            }
        }

        // count++;
    }
    // output file or files total tallied speed violations
    cout << count << " Violations logged.\n";

    // close files
    ifile.close();
    ofile.close();

    // close program
    return 0;
}