#pragma once


enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };


static const char* degreeProgramToString(DegreeProgram dp) {
    switch (dp) {
    case SECURITY: return "SECURITY";
    case NETWORK: return "NETWORK";
    case SOFTWARE: return "SOFTWARE";
    default: return "UNKNOWN";
    }
}
