//
// Created by Bartek on 20/12/2022.
//

#ifndef LCFS_PROCESS_H
#define LCFS_PROCESS_H

#include <string>
#include <vector>

class Process {
    int id = -1;
    int progress = -1;
    int arrivalTime;
    int burstTime;
    int completionTime = -1;
    int TAT = -1;            // Turn Around Time
    int WT = -1;             // Waiting Time
    int RT = 0;              // Response Time == 0 in LCFS
    //---------------------- // (because we get CPU attention as soon as process arrive)
public:
    int counter;

//    Process();
    Process(int _id, int _arrivalTime, int _burstTime);

    Process(int _arrivalTime, int _burstTime);
//    ~Process();

    void info();

    void setProgress(int _value);

    int getProgress();

    void setId(int _id);

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


#endif //LCFS_PROCESS_H
