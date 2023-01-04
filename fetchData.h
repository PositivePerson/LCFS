//
// Created by Bartek on 04/01/2023.
//

#ifndef LCFS_FETCHDATA_H
#define LCFS_FETCHDATA_H

#include "iostream"
#include "Process.h"
#include <bits/stdc++.h>

using namespace std;

void getProcessesFromFile(vector<Process> &processes) {
    string data;
    ifstream sourcefile("../source_data_LCFS.txt");

    int counter = 0;
    if (sourcefile.is_open()) {
        int id = -1;
        int arrivalTime = -1;
        int burstTime = -1;

        cout << "Retrieving data from file: \n";
        while (sourcefile >> data) {
            if (counter % 3 == 0) {
                cout << data << ' ';
                id = stoi(data);
            } else if (counter % 3 == 1) {
                cout << data << ' ';
                arrivalTime = stoi(data);
            } else if (counter % 3 == 2) {
                cout << data << '\n';
                burstTime = stoi(data);

                Process temp = Process(id, arrivalTime, burstTime);
                processes.push_back(temp);
            }

            counter++;
        }
        sourcefile.close();
    } else cout << "Error: Unable to open data source file!\n";
}

#endif //LCFS_FETCHDATA_H
