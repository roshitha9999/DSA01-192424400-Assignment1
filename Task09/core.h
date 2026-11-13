
#ifndef CORE_H
#define CORE_H

enum class Zone { Inner, Middle, Outer };

constexpr long long BASE_PAISE[] = {
    1000, 2000, 3000
};

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr int CONCESSION_PERCENT = 50;
constexpr long long MIN_BALANCE_PAISE = 5000;

inline bool isPeak(int hour, int minute)
{
    int t = hour * 60 + minute;

    return (t >= 480 && t < 600) ||
           (t >= 1020 && t < 1200);
}

inline long long fare(Zone z, bool peak, bool concession = false)
{
    long long base = 0;

    switch (z)
    {
        case Zone::Inner: base = BASE_PAISE[0]; break;
        case Zone::Middle: base = BASE_PAISE[1]; break;
        case Zone::Outer: base = BASE_PAISE[2]; break;
    }

    if (concession)
        base -= (base * CONCESSION_PERCENT + 50) / 100;

    if (peak)
        base += (base * PEAK_SURCHARGE_PERCENT + 50) / 100;

    return base;
}

inline bool canTravel(long long balance, long long f)
{
    return balance - f >= MIN_BALANCE_PAISE;
}

#endif
