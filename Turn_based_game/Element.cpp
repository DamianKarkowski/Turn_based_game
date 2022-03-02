#include "Element.h"

Element::Element() {};

double Element::elementalEffect(std::string attackElement, std::string defendElement) const {

    return elements[idElement(attackElement)][idElement(defendElement)];
};
int Element::idElement(std::string name) const {
    int variable;
    for (int i = 0; i < 6; i++) {
        if (name == names[i]) variable = i;
    }
    return variable;
}