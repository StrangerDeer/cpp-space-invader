#include "Util.h"

static std::vector<int> timeStamps;
static int duration;

void Util::addTimeStamp(int ticks) {
    timeStamps.push_back(ticks / 1000);
}


int Util::getTimeDuration() {
  calculateDuration();

  return duration;
}

void Util::calculateDuration() {
  int begin, end;
  for (int i = 0; i < timeStamps.size(); i += 2) {
    begin = timeStamps.at(i);
    end = timeStamps.at(i+1);
    duration += end - begin;
  }
}

void Util::clearTimeStamps() {
  timeStamps.clear();
  duration = 0;
}
