#include "ItemType.h"

ItemType::ItemType() : value(0) {}

ItemType::ItemType(int value) : value(value) {}

RelationType ItemType::ComparedTo(ItemType other) const {
    if (value < other.value) return LESS;
    else if (value > other.value) return GREATER;
    else return EQUAL;
}

void ItemType::Print(std::ostream& out) const {
    out << value;
}

void ItemType::Initialize(int number) {
    value = number;
}
