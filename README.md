
# Indian Railways Library Project

## Project Overview
This project implements a library for the Indian Railways that models:
1. **Stations**
2. **Lines**
3. **Platforms**

The library allows for:
- Stations identified by either a string or integer ID.
- Multiple lines at each station.
- A platform that can accommodate train stoppages, with specific timing constraints: once every 30 minutes for regular trains and once every 10 minutes for through trains.
- The program enables users to input train timings and validates this data.

The project demonstrates object-oriented principles such as:
- **Polymorphism**: Different behaviors (train stoppage times) for different types of trains.
- **Data Hiding**: Encapsulating internal data and only exposing necessary interfaces for user interaction.
- **Error Handling**: Rejecting incorrect data inputs and providing meaningful error messages.


## Classes Overview
1. **Station**: Represents a railway station with a unique ID (either integer or string).
2. **Line**: Represents a railway line associated with a station.
3. **Platform**: Represents a platform that can accommodate trains based on their type (stoppage or through).

## Prerequisites
- C++ compiler (e.g., `g++`)
- Make utility for building the project

## Building the Project

### Step 1: Build the Static Library

First, you need to build the static library `libRailways.a` from `Railways.cpp`. Open a terminal and navigate to the project directory, then run the following command:

```bash
make libRailways
```

This will:
- Compile `Railways.cpp` into an object file `Railways.o`.
- Create the static library `libRailways.a`.

### Step 2: Compile and Link the Test Program

Next, you need to build the test program (`main.cpp`) and link it with the static library. To do this, run:

```bash
make main
```

This will:
- Compile `main.cpp` into an object file `main.o`.
- Link `main.o` with the static library `libRailways.a` to create two executables:
  - `main_debug` (compiled with debugging information).
  - `main_optimized` (compiled with optimization).

### Step 3: Running the Program

After the build completes, you will have two executables:
- **main_debug**: The debug version of the program (compiled with `-g`).
- **main_optimized**: The optimized version of the program (compiled with `-O3`).

To run the program in **debug mode**, execute:

```bash
./main_debug
```

To run the program in **optimized mode**, execute:

```bash
./main_optimized
```



This will remove:
- Object files (`*.o`),
- The static library (`libRailways.a`),
- The executables (`main_debug` and `main_optimized`).

## Sample Input & Output

### Sample Input:

```
Enter Train Timing (hh:mm): 12:30
Enter Train Type (1 for stoppage, 2 for through): 1
Enter Station ID: NewDelhi
Enter Platform Number: 1
```

### Sample Output:

```
Train is Successfully Scheduled!!
```

If the data is incorrect (e.g., wrong train timing format or platform capacity exceeded), the program will reject the input and display an error message.

## Makefile Explanation

The `Makefile` consists of three main parts:

1. **libRailways**:
   - This target builds the static library `libRailways.a` from `Railways.cpp`.
   - The object file `Railways.o` is created and then archived into `libRailways.a`.

2. **main**:
   - This target builds the test program from `main.o` and links it with the static library `libRailways.a`.
   - Two executables are created:
     - **main_debug**: Compiled with debugging information (`-g`).
     - **main_optimized**: Compiled with optimizations (`-O3`).


### Example of Makefile Contents

```makefile

libRailways:
    g++ -c Railways.cpp -o Railways.o      
    ar rcs libRailways.a Railways.o        


main:
	g++ -c main.cpp -o main.o
	g++ -g main.o -L. -lRailways -o main_debug
	g++ -O3 main.o -L. -lRailways -o main_optimized

### Target Breakdown:
- `libRailways`: Builds the static library `libRailways.a` from `Railways.cpp`.
- `main`: Builds the test executables using `main.o` and `libRailways.a`.
- `clean`: Removes object files (`*.o`), executables, and the static library.

## Conclusion

This project models a railway system with stations, lines, and platforms, implementing object-oriented principles such as polymorphism and data hiding. It allows the user to input train timings, validates the input, and rejects incorrect data. The project uses a `Makefile` to compile the static library and test program, with options for building both a debug and optimized version of the program.


