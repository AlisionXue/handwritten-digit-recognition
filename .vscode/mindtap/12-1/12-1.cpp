#include <stdio.h>

int main() {
    // Step 1: Create an integer variable called avar and initialize it with the value 52
    int avar = 52;

    // Step 2: Create a double variable called amt and initialize it with the value 13.14
    double amt = 13.14;

    // Step 3: Display the location (address) of avar in memory
    printf("Address of avar: %p\n", (void*)&avar);

    // Step 4: Display the location (address) of amt in memory
    printf("Address of amt: %p\n", (void*)&amt);

    // Step 5: Create an integer pointer called iptr that points to avar
    int* iptr = &avar;

    // Step 6: Create an integer pointer called dptr that points to amt (Note: The prompt suggests an incorrect step here)
    // Since amt is of type double, we need a double pointer for it.
    double* dptr = &amt;

    // Step 7: Print the value in avar using its pointer
    printf("Value of avar using pointer: %d\n", *iptr);

    // Step 8: Store the value 10.10 in the location for amt without using the variable name amt
    *dptr = 10.10;

    // Display the new value of amt
    printf("New value of amt: %.2f\n", amt);

    return 0;
}