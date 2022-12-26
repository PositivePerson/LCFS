//
// Created by Bartek on 20/12/2022.
//

#ifndef FCFS_PROCESS_H
#define FCFS_PROCESS_H

#include <string>
#include <vector>

class Process {
    int id;
    int progress = -1;
    int arrivalTime;
    int burstTime;
    int completionTime = -1;
    int TAT = -1;            // Turn Around Time
    int WT = -1;             // Waiting Time
    int RT = -1;             // Response Time === WT in FCFS algorithm
public:
    int counter;

//    Process();
    Process(int _id, int _arrivalTime, int _burstTime);
//    ~Process();

    void info();

    void setProgress(int _value);

    int getProgress();

    int getId();

    int getArrivalTime();

    int getBurstTime();

    void setCompletionTime(int _value);

    int getCompletionTime();

    void setTAT(int _value);

    int getTAT();

    void setWT(int _value);

    int getWT();

    void setRT(int _value);

    int getRT();
};


#endif //FCFS_PROCESS_H
