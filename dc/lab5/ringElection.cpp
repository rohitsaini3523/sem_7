#include <iostream>
#include <windows.h>
using namespace std;

class Process
{
public:
    int pid;
    int MAC;
    Process *next;
    bool isUp;
    Process()
    {
        this->pid = rand() % 1000;
        this->MAC = rand() % 10000;
        this->next = NULL;
        this->isUp = true;
    }
    void kill()
    {
        Sleep(3);
        cout << "Unfortunately pid:" << pid << " Has died" << endl;
        this->isUp = false;
    }
    void details()
    {
        if (isUp)
            cout << "Pid:" << pid << ", MAC:" << MAC << endl;
    }
};

class Election
{
public:
    int n;
    Process *head;
    Election()
    {
        head = NULL;
        n = 0;
    }
    void printRing()
    {
        Process *temp = head;
        int cnt = 0;
        while (cnt < n)
        {
            cout << temp->pid << " -> ";
            temp = temp->next;
            cnt++;
        }
        cout << head->pid << endl;
    }
    void createRing(int n)
    {
        this->n = n;
        head = new Process();
        Process *temp = head;
        while (n--)
        {
            temp->next = new Process();
            temp = temp->next;
        }
        temp->next = head;
        cout << "Ring created" << endl;
        this->printRing();
    }
    void makeCoordinator(int coordinatorId)
    {
        Process *temp = head;
        int cnt = 0;
        while (cnt <= n)
        {
            if (temp->pid == coordinatorId)
            {
                head = temp;
                cout << coordinatorId << " is now the coordinator" << endl;
                return;
            }
            temp = temp->next;
            cnt++;
        }
        cout << "Invalid Coordinator Id" << endl;
    }
    void announceWinner(int winnerId)
    {
        Process *temp = head;
        do
        {
            temp = temp->next;
            if (temp != head)
                cout << "pid:" << temp->pid << " recieved message from " << winnerId << endl;
        } while (temp != head);
    }
    void conductElection(int initiatorId)
    {
        Process *initiator = head;
        int cnt = 0;
        while (initiator->pid != initiatorId && cnt <= n)
        {
            initiator = initiator->next;
            cnt++;
        }
        if (cnt > n || !initiator->isUp)
        {
            cout << "Election cannot be conducted by " << initiatorId << endl;
            return;
        }
        Process *temp = initiator;
        int winner = initiator->pid;
        do
        {
            cout << "Current pid: " << temp->pid;
            if (!temp->isUp)
                cout << " is down";
            else if (temp->pid > winner)
            {
                cout << " winner updated";
                winner = temp->pid;
            }
            else
            {
                cout << " no update";
            }
            cout << endl;
            temp = temp->next;
        } while (temp != initiator);
        cout << "Winner is " << winner << endl;
        makeCoordinator(winner);
        announceWinner(winner);
    }
};

int main()
{
    Election election = Election();
    int n;
    cout << "Enter number of processes : ";
    cin >> n;
    election.createRing(n);

    int cid;
    cout << "Enter coordinator id : ";
    cin >> cid;
    election.makeCoordinator(cid);
    election.head->kill();
    int init;
    cout << "Enter election initiator id : ";
    cin >> init;
    election.conductElection(init);
    return 0;
}