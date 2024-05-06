#include "Util.h"

double Util::timeBegin = 0.00;
double Util::timeEnd = 0.00;

void Util::setTimeBegin(double begin) {
    timeBegin = begin;
}

void Util::setTimeEnd(double end) {
    timeEnd = end;
}

int Util::getTimeDuration() {
    return timeEnd - timeBegin;
}
