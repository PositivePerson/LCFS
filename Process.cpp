//
// Created by Bartek on 20/12/2022.
//

#include "Process.h"
#include <iostream>

using namespace std;

Process::Process(int _id, int _arrivalTime, int _burstTime) : id(_id), arrivalTime(_arrivalTime),
                                                              burstTime(_burstTime) {
    cout << "Running constructor (Process)... \n";
};

Process::Process(int _arrivalTime, int _burstTime) : arrivalTime(_arrivalTime),
                                                     burstTime(_burstTime) {
    cout << "Running constructor (Process)... \n";
//    info();
};

void Process::info() {
    cout << "========================= \n";
    cout << "id = " << id << " \n";
    cout << "arrivalTime = " << arrivalTime << " \n";
    cout << "burstTime = " << burstTime << " \n";
    cout << "completionTime = " << completionTime << " \n";
    cout << "TAT = " << TAT << " \n";
    cout << "WT = " << WT << " \n";
    cout << "RT = " << RT << " \n";
    cout << "========================= \n";
}

void Process::setProgress(int _value) {
    this->progress = _value;
}

int Process::getProgress() {
    return this->progress;
}

void Process::setId(int _id) {
    this->id = _id;
}

int Process::getId() {
    return this->id;
}

int Process::getArrivalTime() {
    return this->arrivalTime;
}

int Process::getBurstTime() {
    return this->burstTime;
}

void Process::setCompletionTime(int _value) {
    cout << "Setting completion time to: " << _value << '\n';
    this->completionTime = _value;
}

int Process::getCompletionTime() {
    return this->completionTime;
}

void Process::setTAT(int _value) {
    this->TAT = _value;
}

int Process::getTAT() {
    return this->TAT;
}

void Process::setWT(int arg1) {
//    std::cout << "Setting WT to: " << arg1 <<std::endl;
    this->WT = arg1;

//    std::cout << "WT after change: " << WT << '\n';
}

int Process::getWT() {
    return WT;
}

void Process::setRT(int arg1) {
    this->RT = arg1;
}

int Process::getRT() {
    return this->RT;
}