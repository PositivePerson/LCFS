//
// Created by Bartek on 27/12/2022.
//

#ifndef FCFS_GENERATOR_H
#define FCFS_GENERATOR_H

#include "Process.h"
#include "iostream"
#include<cstdlib>

using namespace std;

void sortATs(vector<Process> &processes) {
    std::sort(processes.begin(), processes.end(),
              [](Process &f, Process &s) {
                  return f.getArrivalTime() < s.getArrivalTime();
              });

//    cout << "\n-Sorted- Ids:\n";
//    for (auto proc: processes)
//        cout << "Process id: " << proc.getId() << '\n';
//    cout << '\n';
}

vector<Process> generate(int amount) {
    srand((unsigned) time(NULL));

    vector<Process> processes;
    for (int i = 0; i < amount; i++) {
        int _arrivalTime = rand() % 9; // 0-10
        int _burstTime = 1 + (rand() % 9); // 0-10

        Process temp = Process(_arrivalTime, _burstTime);
        processes.push_back(temp);
    }

    sortATs(processes);
    for (int i = 0; i < amount; i++) {
        processes[i].setId(i);
    }

    cout << "\n-Sorted- Ids:\n";
    for (auto proc: processes)
        cout << "Process id: " << proc.getId() << '\n';
    cout << '\n';

    cout << "Generated Processes" << endl;
    return processes;
}

#endif //FCFS_GENERATOR_H
