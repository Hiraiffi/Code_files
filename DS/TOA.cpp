#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Define the Moore machine
struct MooreMachine {
    vector<string> states;
    map<string, map<string, string>> transitions;
    map<string, string> outputs;
};

// Define the Mealy machine
struct MealyMachine {
    vector<string> states;
    map<string, map<string, pair<string, string>>> transitions;
};

// Function to get user-defined Moore machine
MooreMachine getUserDefinedMooreMachine() {
    MooreMachine mooreMachine;
    int numStates;

    cout << "Enter the number of states for the Moore machine: ";
    cin >> numStates;

    for (int i = 0; i < numStates; ++i) {
        string stateName;
        cout << "Enter state name: ";
        cin >> stateName;
        mooreMachine.states.push_back(stateName);

        // Allow the user to enter transitions for the current state
        cout << "Enter transitions for state " << stateName << " (Input NextState), enter 'done' to finish: " << endl;
        while (true) {
            string input, nextState;
            cout << "Input: ";
            fflush(stdin);
            cin >> input;
            if (input == "done")
                break;
            cin >> nextState;
            mooreMachine.transitions[stateName][input] = nextState;
        }
    }

    cout << "Enter outputs for each state:" << endl;
    for (const auto& state : mooreMachine.states) {
        string output;
        cin >> output;
        mooreMachine.outputs[state] = output;
    }

    return mooreMachine;
}

// Function to get user-defined Mealy machine
MealyMachine getUserDefinedMealyMachine() {
    MealyMachine mealyMachine;
    int numStates;

    cout << "Enter the number of states for the Mealy machine: ";
    cin >> numStates;

    for (int i = 0; i < numStates; ++i) {
        string stateName;
        cout << "Enter state names:" << endl;
        cin >> stateName;
        mealyMachine.states.push_back(stateName);

        // Allow the user to enter transitions for the current state
        cout << "Enter transitions for state " << stateName << " (Input Output NextState), enter 'done' to finish: " << endl;
        while (true) {
            string input, output, nextState;
            cin >> input;
            if (input == "done")
                break;
            cin >> output >> nextState;
            mealyMachine.transitions[stateName][input] = make_pair(output, nextState);
        }
    }

    return mealyMachine;
}


// Convert Moore machine to Mealy machine
MealyMachine convertMooreToMealy(MooreMachine& mooreMachine) {
    MealyMachine mealyMachine;

    // Copy states
    mealyMachine.states = mooreMachine.states;

    // Convert transitions and outputs to Mealy format
    for (const auto& state : mooreMachine.states) {
        for (const auto& input : mooreMachine.transitions[state]) {
            string nextState = input.second; // Next state in Moore machine
            string output = mooreMachine.outputs[nextState]; // Output associated with the next state
            mealyMachine.transitions[state][input.first] = make_pair(output, nextState);
        }
    }


    return mealyMachine;
}

// Convert Mealy machine to Moore machine
MooreMachine convertMealyToMoore(MealyMachine& mealyMachine) {
    MooreMachine mooreMachine;

    // Copy states
    mooreMachine.states = mealyMachine.states;

    // Convert transitions and outputs to Moore format
    for (const auto& state : mealyMachine.states) {
        for (const auto& input : mealyMachine.transitions[state]) {
            string nextState = input.second.second; // Next state in Mealy machine
            string output = input.second.first; // Output associated with the current transition
            string combinedState = state + "_" + output; // Combine state and output for state splitting

            // Check if combinedState already exists in Moore machine
            if (mooreMachine.transitions.find(combinedState) == mooreMachine.transitions.end()) {
                // If combinedState doesn't exist, create a new state in Moore machine
                mooreMachine.states.push_back(combinedState);
                mooreMachine.transitions[combinedState] = mooreMachine.transitions[state]; // Copy transitions
                mooreMachine.outputs[combinedState] = output; // Set output for the new state
            }

            // Update the transition to point to the combined state
            mooreMachine.transitions[state][input.first] = combinedState;
        }
    }


    return mooreMachine;
}

// Print Moore machine transitions
void printMoore(MooreMachine& mooreMachine) {
    cout << "Moore Machine Transitions:" << endl;
    for (const auto& state : mooreMachine.states) {
        cout << "State: " << state << endl;
        for (const auto& input : mooreMachine.transitions[state]) {
            cout << "Input: " << input.first << ", Next State: " << input.second << ", Output: " << mooreMachine.outputs[input.second] << endl;
        }
    }
}

// Print Mealy machine transitions
void printMealy(MealyMachine& mealyMachine) {
    cout << "Mealy Machine Transitions:" << endl;
    for (const auto& state : mealyMachine.states) {
        for (const auto& input : mealyMachine.transitions[state]) {
            cout << "State: " << state << ", Input: " << input.first << ", Output: " << input.second.first << ", Next State: " << input.second.second << endl;
        }
    }
}

int main() {
    int choice;
    MooreMachine mooreMachine;
    MealyMachine mealyMachine;

    cout << "Select Conversion:" << endl;
    cout << "1. Mealy to Moore" << endl;
    cout << "2. Moore to Mealy" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        // Get user-defined Mealy machine
        mealyMachine = getUserDefinedMealyMachine();

        // Convert Mealy to Moore
        mooreMachine = convertMealyToMoore(mealyMachine);

        // Print Moore machine transitions from Mealy conversion
        printMoore(mooreMachine);

        break;

    case 2:
        // Get user-defined Moore machine
        mooreMachine = getUserDefinedMooreMachine();

        // Convert Moore to Mealy
        mealyMachine = convertMooreToMealy(mooreMachine);

        // Print Mealy machine transitions
        printMealy(mealyMachine);

        break;

    default:
        cout << "Invalid choice!" << endl;
        return 0;
    }
	return 0;
}