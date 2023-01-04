#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

#include "Process.h"
#include "generator.h"
#include "fetchData.h"

void displayAll(vector<Process> processes) {
    cout << "Process id  " << " Arrival time  " << " Burst time  " << " | " << " Completion time  "
         << " Turn around time " << " Waiting time " << " Response Time\n";
    for (Process process: processes) {
        cout << "   " << process.getId()
             << "\t\t" << process.getArrivalTime()
             << "\t\t" << process.getBurstTime()
             << "\t | "
             << "\t    " << process.getCompletionTime()
             << "\t\t    " << process.getTAT()
             << "\t\t    " << process.getWT()
             << "\t\t    " << process.getRT() << endl;
    }
}

int main() {
    int protec = 1000;
//    Process a = Process(0, 0, 2);
//    Process c = Process(2, 5, 3);
//    Process b = Process(1, 1, 2);
//    Process d = Process(3, 6, 4);

//    vector<Process> processes = {a, b, c, d};
// ---------- OR ----------
//    vector<Process> processes = generate(4);
// ---------- OR ----------
    vector<Process> processes;
    getProcessesFromFile(processes);

//    sortATs(processes);

    displayAll(processes);

    int processesDone = 0; //Amount
    int seconds = 0;
//    Process *currentProcess = &processes[0];
    Process *currentProcess = nullptr;
    vector<Process *> stoppedProcesses;
    int nextArrivalIndex = 0;
    do {
        if (currentProcess != nullptr) {
            cout << '\n' << seconds << " sec: Enter while - process "
                 << currentProcess->getId() << '\n';

            currentProcess->setProgress(currentProcess->getProgress() + 1);
        } else {
            cout << '\n' << seconds << " sec: Enter while - nullptr\n";
        }

        if (currentProcess != nullptr) {
            //  If completed
            if (currentProcess->getProgress() == currentProcess->getBurstTime()) {
                currentProcess->setCompletionTime(seconds);
                currentProcess->setTAT(seconds - currentProcess->getArrivalTime());
                currentProcess->setWT(currentProcess->getTAT() - currentProcess->getBurstTime());

                cout << "Process nr " << currentProcess->getId() << ": done.\n";
                processesDone++;

                currentProcess = nullptr;

                if (stoppedProcesses.size() > 0) {
                    currentProcess = stoppedProcesses.back();
                    stoppedProcesses.pop_back();
                }
            }
        }

        // If next process arrived
        if (seconds == processes[nextArrivalIndex].getArrivalTime()) {
            cout << "Process " << nextArrivalIndex << " arrived\n";
            stoppedProcesses.push_back(currentProcess); //Stop current Process
            currentProcess = &processes[nextArrivalIndex];      //Replace 'current'
            currentProcess->setProgress(0);

            nextArrivalIndex = currentProcess->getId() + 1;
        } else {
            cout << "Still running some process\n";
        }

        if ((processesDone < processes.size()) &&
            (processes[nextArrivalIndex].getArrivalTime() != seconds)) {
            seconds++;
        }

    } while (processesDone < processes.size() && (--protec));

    cout << "\nDone all " << processesDone << " processes in "
         << seconds << " seconds\n";

    cout << "Process id 2 completion time: "
         << processes[2].getCompletionTime() << '\n';

    displayAll(processes);
    return 0;
}