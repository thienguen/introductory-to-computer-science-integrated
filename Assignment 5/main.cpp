#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifile;
    ofstream ofile;
    string   file_name = "", license = "", date = "", time = "", weight = "", speed = "", prev_date = "";
    int      violation_count = 0, int_weight = 0, int_speed = 0;
    bool     violation = false;

    // loop until file successfully opens
    do
    {
        // ask user for file name
        cout << "Open File: ";
        cin >> file_name;
        // try to open file
        ifile.open(file_name);
        // check if file opened
        if (!ifile.is_open())
        {
            // output errror message
            cout << "Could not open nonexistant\n";
        }
    } while (!ifile.is_open());

    while (!ifile.eof())
    {
        violation = false;

        // read file values into variables
        getline(ifile, license, ',');
        getline(ifile, date, ',');
        getline(ifile, time, ',');
        getline(ifile, weight, ',');
        getline(ifile, speed, '\n');

        // convert to int
        int_weight = stoi(weight);
        int_speed = stoi(speed);

        // check for violations
        if (int_weight < 5000)
        {
            if (int_speed > 45)
            {
                violation = true;
            }
        }
        else if (int_weight > 5000)
        {
            if (int_speed > 30)
            {
                violation = true;
            }
        }

        if (violation)
        {
            // set prev date for first violation & open file
            if (violation_count == 0)
            {
                prev_date = date;
                ofile.open("[" + date + "] Report.txt");
            }

            // update violation count
            violation_count += 1;

            // check if date is the same as prev
            if (date == prev_date)
            {
                // print violation to the file
                ofile << "[" << time << "] " << license << endl;
            }
            else
            {
                // close prev file
                ofile.close();
                // open new violation file
                ofile.open("[" + date + "] Report.txt");
                // print violation to the file
                ofile << "[" << time << "] " << license << endl;
                // set prev_date to date
                prev_date = date;
            }
        }
    }
    // close files
    ofile.close();
    ifile.close();

    // print num of violations
    cout << violation_count << " violations logged.";

    return EXIT_SUCCESS;
}