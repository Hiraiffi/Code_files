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

// Convert Moore machine to Mealy machine
MealyMachine convertMooreToMealy(MooreMachine& mooreMachine) {
    MealyMachine mealyMachine;

    // Copy states
    mealyMachine.states = mooreMachine.states;

    // Convert transitions and outputs to Mealy format
    for (const auto& state : mooreMachine.states) {
        for (const auto& input : mooreMachine.transitions[state]) {
            mealyMachine.transitions[state][input.first] = make_pair(mooreMachine.outputs[state], input.second);
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
            string nextState = input.second.second;
            mooreMachine.transitions[state][input.first] = nextState;
            mooreMachine.outputs[nextState] = input.second.first;
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
        case 1: {
            // Define Mealy machine
            mealyMachine = {
                {"A", "B"},
                {
                    {"A", {{"0", make_pair("0", "A")}, {"1", make_pair("1", "B")}}},
                    {"B", {{"0", make_pair("0", "A")}, {"1", make_pair("1", "B")}}}
                }
            };

            // Convert Mealy to Moore
            mooreMachine = convertMealyToMoore(mealyMachine);

            // Print Moore machine transitions from Mealy conversion
            printMoore(mooreMachine);

            break;
        }
        case 2: {
            // Define Moore machine
            mooreMachine = {
                {"A", "B"},
                {
                    {"A", {{"0", "A"}, {"1", "B"}}},
                    {"B", {{"0", "A"}, {"1", "B"}}}
                },
                {{"A", "0"}, {"B", "1"}}
            };

            // Convert Moore to Mealy
            mealyMachine = convertMooreToMealy(mooreMachine);

            // Print Mealy machine transitions
            printMealy(mealyMachine);

            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}
