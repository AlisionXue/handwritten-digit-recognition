#include <iostream>

void shampooRoutine() {
    std::cout << "Shampoo Routine:\n";
    for (int i = 0; i < 2; ++i) { 
        std::cout << "Lather\n";
        std::cout << "Rinse\n";
    }
    std::cout << "Repeat if necessary\n";
}

void cakeMixRoutine() {
    std::cout << "\nCake Mix Routine:\n";
    int stirCount = 0;
    const int maxStirs = 100;
    bool batterIsSmooth = false;

    while (stirCount < maxStirs && !batterIsSmooth) {
        std::cout << "Stirring... (" << stirCount + 1 << ")\n";
        stirCount++;
        if (stirCount == 50) { 
            batterIsSmooth = true;
        }
    }
    std::cout << "Batter is smooth after " << stirCount << " stirs.\n";
}

void workoutRoutine() {
    std::cout << "\nWorkout Routine:\n";
    for (int set = 1; set <= 3; ++set) { // 
        std::cout << "Start set " << set << ": \n";
        for (int rep = 1; rep <= 10; ++rep) { // 
            std::cout << "Performing repetition " << rep << "\n";
        }
        std::cout << "Set " << set << " complete.\n";
    }
    std::cout << "Workout complete!\n";
}

int main() {
    shampooRoutine();
    cakeMixRoutine();
    workoutRoutine();
    return 0;
}
