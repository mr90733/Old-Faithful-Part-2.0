#include <iostream>

#include <fstream>

#include <string>

using namespace std;

int main()

{

    string filePath;

    cout << "Enter the path to the file: ";

    cin >> filePath;

    ifstream file(filePath);

    if (!file)

        {
        cout << "Error opening file!" << endl;

        return 1;
    }

    ofstream newFile("faithful_updated.csv");

    newFile << "eruptions,waiting,Short Wait Time" << endl;


    double totalEruption = 0;

    double totalWaiting = 0;

    int count = 0;


    string line;

    getline(file, line);


    while (getline(file, line))

        {

        int commaPos = line.find(',');

        if (commaPos == -1) continue;

        string eruptionStr = line.substr(0, commaPos);

        string waitingStr = line.substr(commaPos + 1);


        double eruption = stod(eruptionStr);

        double waiting = stod(waitingStr);

        totalEruption = totalEruption + eruption;

        totalWaiting = totalWaiting + waiting;

        count = count + 1;


        if (waiting <= 60)

            newFile << eruption << "," << waiting << ",T" << endl;

        else

            newFile << eruption << "," << waiting << ",F" << endl;
    }

    if (count == 0)

        {
        cout << "No info in file" << endl;
        return 1;
    }


    double avgEruption = totalEruption / count;

    double avgWaiting = totalWaiting / count;

    cout << "The average eruption length is " << avgEruption << " minutes." << endl;

    cout << "The average eruption wait time is " << avgWaiting << " minutes." << endl;

    cout << "Writing a new CSV file called faithful_updated.csv." << endl;

    file.close();

    newFile.close();

    return 0;
}
