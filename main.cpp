#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class ResourceAllocationGraph {
private:
    vector<vector<int> > allocation; // Allocation matrix
    vector<vector<int> > request;    // Request matrix
    vector<bool> available;          // Available resources
    int processCount;
    int resourceCount;

public:
    ResourceAllocationGraph(int p, int r) : processCount(p), resourceCount(r) {
        allocation.resize(p, vector<int>(r, 0));
        request.resize(p, vector<int>(r, 0));
        available.resize(r, true);
    }

    void addRequest(int process, int resource) {
        if (resource < resourceCount && process < processCount) {
            request[process][resource] = 1;
        }
    }

    void allocateResource(int process, int resource) {
        if (resource < resourceCount && process < processCount && available[resource] && request[process][resource]) {
            allocation[process][resource] = 1;
            request[process][resource] = 0;
            available[resource] = false;
        }
    }

    void releaseResource(int process, int resource) {
        if (resource < resourceCount && process < processCount && allocation[process][resource]) {
            allocation[process][resource] = 0;
            available[resource] = true;
        }
    }

    bool detectDeadlock() {
        vector<bool> visited(processCount, false);
        for (int i = 0; i < processCount; i++) {
            if (!visited[i] && isCyclic(i, visited)) {
                return true;
            }
        }
        return false;
    }

    void recoverFromDeadlock() {
        for (int i = 0; i < processCount; i++) {
            for (int j = 0; j < resourceCount; j++) {
                if (allocation[i][j]) {
                    releaseResource(i, j);
                    if (!detectDeadlock()) return;
                }
            }
        }
    }

private:
    bool isCyclic(int process, vector<bool> &visited) {
        vector<bool> recStack(processCount, false);
        return isCyclicUtil(process, visited, recStack);
    }

    bool isCyclicUtil(int process, vector<bool> &visited, vector<bool> &recStack) {
        if (!visited[process]) {
            visited[process] = true;
            recStack[process] = true;
            for (int j = 0; j < resourceCount; j++) {
                if (request[process][j]) {
                    for (int i = 0; i < processCount; i++) {
                        if (allocation[i][j] && (!visited[i] && isCyclicUtil(i, visited, recStack)) || recStack[i]) {
                            return true;
                        }
                    }
                }
            }
        }
        recStack[process] = false;
        return false;
    }
};

void displayMenu() {
    cout << "1. Add Resource Request" << endl;
    cout << "2. Allocate Resource" << endl;
    cout << "3. Release Resource" << endl;
    cout << "4. Detect Deadlock" << endl;
    cout << "5. Recover from Deadlock" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int processCount, resourceCount;
    cout << "Enter the number of processes: ";
    cin >> processCount;
    cout << "Enter the number of resources: ";
    cin >> resourceCount;

    ResourceAllocationGraph rag(processCount, resourceCount);
    int choice, process, resource;

    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter process number and resource number: ";
                cin >> process >> resource;
                rag.addRequest(process, resource);
                break;
            case 2:
                cout << "Enter process number and resource number: ";
                cin >> process >> resource;
                rag.allocateResource(process, resource);
                break;
            case 3:
                cout << "Enter process number and resource number: ";
                cin >> process >> resource;
                rag.releaseResource(process, resource);
                break;
            case 4:
                if (rag.detectDeadlock()) {
                    cout << "Deadlock detected!" << endl;
                } else {
                    cout << "No deadlock detected." << endl;
                }
                break;
            case 5:
                rag.recoverFromDeadlock();
                cout << "Recovery procedure completed." << endl;
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
