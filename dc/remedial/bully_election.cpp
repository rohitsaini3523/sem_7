#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
using namespace std;

class Node
{
public:
	int nodeId;
	bool isOnline;

	Node()
	{
		this->nodeId = rand() % 1000 + 1;
		this->isOnline = true;
	}

	int send(int initiatorId)
	{
		if (this->isOnline && this->nodeId > initiatorId)
		{
			cout << initiatorId << " Sends message to ";
			cout << this->nodeId << ". Recieved: OK" << endl;
			return 1;
		}
		return 0;
	}

	void shutDown()
	{
		Sleep(3);
		cout << this->nodeId << " has gone down" << endl;
		this->isOnline = false;
	}
};

class ElectionCoordinator
{
public:
	vector<Node *> network;
	Node *coordinatorNode;

	ElectionCoordinator(int numNodes)
	{
		for (int i = 0; i < numNodes; i++)
		{
			this->network.push_back(new Node());
		}
		sort(network.begin(), network.end(), [](Node *lhs, Node *rhs)
			 { return lhs->nodeId < rhs->nodeId; });
		coordinatorNode = network[numNodes - 1];
	}

	void printNetwork()
	{
		for (Node *node : network)
		{
			cout << node->nodeId << " ";
		}
		cout << endl;
	}
	void final_msg(int nodeId)
	{
		for (Node *node : network)
		{
			if (node->nodeId < nodeId)
				cout << nodeId << " sends message to " << node->nodeId << endl;
		}
	}
	vector<Node *> conductElection(int initiatorId)
	{
		vector<Node *> responses;
		for (Node *node : network)
		{
			if (node->send(initiatorId) == 1)
			{
				responses.push_back(node);
			}
		}
		return responses;
	}

	void selectCoordinator(int nodeId)
	{
		for (Node *node : network)
		{
			if (node->nodeId == nodeId)
				coordinatorNode = node;
		}
	}
};

int main()
{
	int numNodes;
	cout << "Enter number of nodes: ";
	cin >> numNodes;
	ElectionCoordinator election(numNodes);
	election.printNetwork();
	election.coordinatorNode->shutDown();
	int initiatorId;
	vector<Node *> eligibleNodes;
	cout << "\nWho will conduct election?: ";
	cin >> initiatorId;
	eligibleNodes = election.conductElection(initiatorId);

	while (eligibleNodes.size())
	{
		initiatorId = eligibleNodes[0]->nodeId;
		cout << "\nNode Conducting Election : " << initiatorId << endl;
		eligibleNodes = election.conductElection(initiatorId);
		if (eligibleNodes.size() > 1)
		{
			cout << "Nodes are now eligible to conduct elections: ";
			for (Node *node : eligibleNodes)
			{
				cout << node->nodeId << " ";
			}
		}
	}

	cout << "New coordinator is Node ID: " << initiatorId << endl;
	election.selectCoordinator(initiatorId);
	election.final_msg(initiatorId);
	return 0;
}
