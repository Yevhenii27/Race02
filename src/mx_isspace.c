#include "way_home.h"

bool mx_isspace(char c) {
    if (c == ' '
        || c == '\t'
        || c == '\v'
        || c == '\n'
        || c == '\r'
        || c == '\f') {
        return true;
    }
    else {
        return false;
    }
}
