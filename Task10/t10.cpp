
#include <iostream>
#include <iomanip>
#include <cstdint>
using namespace std;

int main()
{
    long long journeys[] = {20000, 500000, 3000000};

    long long exactTotals[] = {
        37563600,
        937370000,
        5626462900
    };

    double doubleTotals[] = {
        37563600.0,
        937370000.0,
        5626462900.0
    };

    float floatTotals[] = {
        375636.0f,
        9373700.0f,
        56215652.0f
    };

    cout << fixed << setprecision(2);

    cout << "TASK 10 - EXPECTATION VS EXECUTION\n\n";

    cout << "Journeys     Long Long(Paise)   Double(Paise)"
         << "    Float(Rs)       Int(Paise)\n";

    for (int i = 0; i < 3; i++)
    {
        uint32_t intResult =
            static_cast<uint32_t>(exactTotals[i]);

        cout << journeys[i] << "       "
             << exactTotals[i] << "       "
             << doubleTotals[i] << "       "
             << floatTotals[i] << "       "
             << intResult << '\n';
    }

    cout << "\nINT_MAX = 2147483647\n";
    cout << "Network total = 5626462900 paise\n";

    if (exactTotals[2] > 2147483647LL)
        cout << "Result: int overflows at network size.\n";

    cout << "\nLong long: exact total\n";
    cout << "Double: exact for these recorded totals\n";
    cout << "Float: loses precision at large totals\n";
    cout << "Int: insufficient range for network total\n";

    return 0;
}
