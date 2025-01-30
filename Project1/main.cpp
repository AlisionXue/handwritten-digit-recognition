#include <iostream>
#include "FractionType.h"

using namespace std;

int main() {
    FractionType fraction1, fraction2, result;

    // ≥ı ºªØ∑÷ ˝
    fraction1.Initialize(3, 5);  // 3/5
    fraction2.Initialize(5, 6);  // 5/6

    // ≤‚ ‘ +
    result = fraction1 + fraction2;
    cout << "3/5 + 5/6 = ";
    result.print();

    // ≤‚ ‘ -
    result = fraction1 - fraction2;
    cout << "3/5 - 5/6 = ";
    result.print();

    // ≤‚ ‘ *
    result = fraction1 * fraction2;
    cout << "3/5 * 5/6 = ";
    result.print();

    // ≤‚ ‘ /
    result = fraction1 / fraction2;
    cout << "3/5 / 5/6 = ";
    result.print();

    return 0;
}
