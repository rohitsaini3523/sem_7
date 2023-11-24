#include <iostream>
#include <vector>
using namespace std;

class Process
{
private:
    vector<int> logicalClock;
    int id, clockRate;

public:
    int time;

    Process(int id, int time, int clockRate)
    {
        this->id = id;
        this->time = time;
        this->clockRate = clockRate;
        for (int i = 0; i <= time; i++)
        {
            logicalClock.push_back(i * clockRate);
        }
    }

    void print()
    {
        cout << "Process " << this->id << " :  ";
        for (int i = 0; i <= this->time; i++)
        {
            cout << logicalClock[i] << "  ";
        }
    }

    int getTime(int timeStamp) { return this->logicalClock[timeStamp]; }

    void updateLogicalClock(int senderTime, int receiverTime)
    {
        if (receiverTime > senderTime)
        {
            cout << "No time synchronization needed" << endl;
            return;
        }
        int timeStamp = this->searchTime(receiverTime);
        int start = senderTime + 1;
        for (int i = timeStamp; i <= time; i++)
        {
            logicalClock[i] = start + ((i - timeStamp) * clockRate);
        }
        cout << "Process " << this->id << " has synchronized its clock" << endl;
    }

    int searchTime(int clockTime)
    {
        for (int i = 0; i <= this->time; i++)
        {
            if (logicalClock[i] == clockTime)
                return i;
        }
        return -1;
    }
};

void printAllProcesses(vector<Process *> processes)
{
    for (Process *p : processes)
    {
        p->print();
        cout << endl;
    }
}

int main()
{
    int n, time = 10;
    cout << "Enter number of processes : ";
    cin >> n;
    vector<Process *> processes;
    for (int i = 0; i < n; i++)
    {
        int clockRate;
        cout << "Enter clock rate of Process " << i + 1 << " : ";
        cin >> clockRate;
        processes.push_back(new Process(i + 1, time, clockRate));
    }
    printAllProcesses(processes);

    // Let's see messages now
    char choice = 'Y';
    while (choice == 'Y')
    {
        int senderTime, receiverTime, sender, receiver, timeStamp;
        cout << "Enter sender id : ";
        cin >> sender;
        cout << "Enter sender time : ";
        cin >> senderTime;
        cout << "Enter receiver id : ";
        cin >> receiver;
        cout << "Enter receiver time : ";
        cin >> receiverTime;
        processes[receiver - 1]->updateLogicalClock(senderTime, receiverTime);
        printAllProcesses(processes);
        cout << "Do you want to send more messages (Y/N): ";
        cin >> choice;
    }
    return 0;
}
