
#ifndef CORE_H
#define CORE_H

#include "../Task02/fare_constants.h"

inline bool isPeak(int hour, int minute)
{
    int t = hour * 60 + minute;

    return (t >= PEAK_AM_START && t < PEAK_AM_END) ||
           (t >= PEAK_PM_START && t < PEAK_PM_END);
}

inline long long fare(Zone z, bool peak, bool concession)
{
    long long f = BASE_PAISE[static_cast<int>(z)];

    if (concession)
        f -= (f * CONCESSION_PERCENT + 50) / 100;

    if (peak)
        f += (f * PEAK_SURCHARGE_PERCENT + 50) / 100;

    return f;
}

inline bool canTravel(long long balance, long long f)
{
    return balance - f >= MIN_BALANCE_PAISE;
}

#endif
