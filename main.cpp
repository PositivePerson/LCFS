#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

#include "Process.h"

void findTAT(vector<Process> &processes) {
    for (auto &process: processes) {
        int temp = process.getCompletionTime() - process.getArrivalTime();
        process.setTAT(temp);
    }
}

void findCTandWT(vector<Process> &processes) {
    int nextStartAt = 0;
    for (auto &process: processes) {
//        cout << "Running findCTandWT loop, lastEndAt: " << nextStartAt
//        << " | arrivalTime: " << process.getArrivalTime() << endl;

        int difference = nextStartAt - process.getArrivalTime();

        if (difference >= 0) { // Continuous running CPU
            process.setWT(nextStartAt - process.getArrivalTime());
            nextStartAt += process.getBurstTime();
        } else { // Interval between processes occured
            process.setWT(0);
            nextStartAt += (process.getBurstTime() + -difference);
        }

        process.setCompletionTime(nextStartAt);
    }
}

void displayAll(vector<Process> processes) {
    cout << "Process id  " << " Arrival time  " << " Burst time  " << " | " << " Completion time  "
         << " Turn around time " << " Waiting time\n";
    for (Process process: processes) {
        cout << "   " << process.getId()
             << "\t\t" << process.getArrivalTime()
             << "\t\t" << process.getBurstTime()
             << "\t | "
             << "\t    " << process.getCompletionTime()
             << "\t\t    " << process.getTAT()
             << "\t\t    " << process.getWT() << endl;
    }
}

int main() {
    Process a = Process(0, 0, 2);
    Process c = Process(2, 5, 3);
    Process b = Process(1, 1, 2);
    Process d = Process(3, 6, 4);

    vector<Process> processes = {a, b, c, d};
    std::sort(processes.begin(), processes.end(),
              [](Process &f, Process &s) {
                  return f.getArrivalTime() < s.getArrivalTime();
              });

    cout << "\n-Sorted- Ids:\n";
    for (auto proc: processes)
        cout << "Process id: " << proc.getId() << '\n';
    cout << '\n';


    int processesDone = 0;
    int seconds = 0;
    Process *currentProcess = &processes[0];
    vector<Process *> stoppedProcesses;
    int nextArrivalIndex = 1;
    do {
        cout << '\n' << seconds << " sec: Enter while - process "
             << currentProcess->getId() << '\n';

        currentProcess->setProgress(currentProcess->getProgress() + 1);

        // If next process arrived
        if (seconds == processes[nextArrivalIndex].getArrivalTime()) {//Next Process
            cout << "Process " << nextArrivalIndex << " arrived\n";
            stoppedProcesses.push_back(currentProcess); //Stop current Process
            currentProcess = &processes[nextArrivalIndex];      //Replace 'current'
            currentProcess->setProgress(0);

            nextArrivalIndex = currentProcess->getId() + 1;
        } else {
            cout << "Still process " << currentProcess->getId() << " running\n";
        }

        //  If completed
        if (currentProcess->getProgress() == currentProcess->getBurstTime()) {
            currentProcess->setCompletionTime(seconds);

            cout << "Process nr " << currentProcess->getId() << ": done.\n";
            processesDone++;

            if (stoppedProcesses.size() > 0) {
                currentProcess = stoppedProcesses.back();
                stoppedProcesses.pop_back();
            }
        }


//        // If all done
//        if (processesDone >= processes.size()) {
//            cout << "Done all " << processesDone << " processes in "
//                 << seconds << " seconds\n";
//            break;
//        }

        seconds++;
    } while (processesDone < processes.size());

    cout << "\nDone all " << processesDone << " processes in "
         << seconds << " seconds\n";

    cout << "Process id 2 completion time: "
         << processes[2].getCompletionTime() << '\n';

//    findCTandWT(processes);
//    findTAT(processes);

    displayAll(processes);
    return 0;
}