# deadlock
# Samina BSIT51F22SO14
# Aqsa Mehreen BSIT51F22S015
# Anzla Nazar BSIT51F22S032
### README: Resource Allocation Graph (RAG) System

## Overview

This program simulates a Resource Allocation Graph (RAG) system for managing resource allocation among multiple processes. It allows users to add resource requests, allocate resources, release resources, detect deadlocks, and recover from deadlocks using a command-line interface.

## Features

- **Add Resource Request**: A process can request a specific resource.
- **Allocate Resource**: Allocate a requested resource to a process if available.
- **Release Resource**: Release a resource currently held by a process.
- **Detect Deadlock**: Detect if a deadlock exists in the system.
- **Recover from Deadlock**: Recover from a detected deadlock by releasing resources.

## Class Structure

### `ResourceAllocationGraph`

This class manages the resource allocation graph with the following member variables:

- `vector<vector<int>> allocation`: Allocation matrix indicating which resources are allocated to which processes.
- `vector<vector<int>> request`: Request matrix indicating which resources are requested by which processes.
- `vector<bool> available`: Boolean vector indicating the availability of resources.
- `int processCount`: Number of processes.
- `int resourceCount`: Number of resources.

#### Public Methods

- `ResourceAllocationGraph(int p, int r)`: Constructor to initialize the RAG with `p` processes and `r` resources.
- `void addRequest(int process, int resource)`: Adds a request for a resource by a process.
- `void allocateResource(int process, int resource)`: Allocates a requested resource to a process if available.
- `void releaseResource(int process, int resource)`: Releases a resource held by a process.
- `bool detectDeadlock()`: Detects if a deadlock exists in the system.
- `void recoverFromDeadlock()`: Attempts to recover from a deadlock by releasing resources.

#### Private Methods

- `bool isCyclic(int process, vector<bool> &visited)`: Helper function to detect cycles in the graph.
- `bool isCyclicUtil(int process, vector<bool> &visited, vector<bool> &recStack)`: Utility function used by `isCyclic` to detect cycles.

## Usage

1. **Compile the Program**:
   ```sh
   g++ -o rag_system rag_system.cpp
   ```

2. **Run the Program**:
   ```sh
   ./rag_system
   ```

3. **Follow the Menu Prompts**:
   - Enter the number of processes and resources.
   - Choose from the menu options to add requests, allocate resources, release resources, detect deadlocks, or recover from deadlocks.

### Menu Options

1. **Add Resource Request**:
   - Input the process number and resource number to request a resource for a specific process.
2. **Allocate Resource**:
   - Input the process number and resource number to allocate a resource to a process if available.
3. **Release Resource**:
   - Input the process number and resource number to release a resource held by a process.
4. **Detect Deadlock**:
   - Check if there is any deadlock in the system. The program will inform you if a deadlock is detected.
5. **Recover from Deadlock**:
   - Attempt to recover from a deadlock by releasing resources.
6. **Exit**:
   - Exit the program.

## Example

```sh
Enter the number of processes: 3
Enter the number of resources: 2
1. Add Resource Request
2. Allocate Resource
3. Release Resource
4. Detect Deadlock
5. Recover from Deadlock
6. Exit
Enter your choice: 1
Enter process number and resource number: 0 1
1. Add Resource Request
2. Allocate Resource
3. Release Resource
4. Detect Deadlock
5. Recover from Deadlock
6. Exit
Enter your choice: 2
Enter process number and resource number: 0 1
...
```

## Notes

- Ensure that process and resource numbers are within the valid range (0 to `processCount-1` for processes and 0 to `resourceCount-1` for resources).
- Deadlock detection and recovery mechanisms are basic and may need improvements for more complex scenarios.
- The current availability of resources is represented as a boolean vector, assuming each resource type has only one instance.

## License

This project is open-source and available under the MIT License. Feel free to modify and distribute as needed.
