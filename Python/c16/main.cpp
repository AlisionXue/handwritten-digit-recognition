#include "extPersonType.h"
#include "dateType.h"
#include "addressType.h"

int main() {
    extPersonType person("Chang", "Xue", "Friend", "123-456-7890");
    person.printInfo();
    return 0;
}
