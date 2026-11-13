// fare_constants.h : constants and zone type shown in the report
enum class Zone { Inner, Middle, Outer };
constexpr long long BASE_PAISE[] = {1000, 2000, 3000}; // Rs 10, Rs 20, Rs 30
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr int CONCESSION_PERCENT = 50; // assumption A1
constexpr long long MIN_BALANCE_PAISE = 5000; // Rs 50 must remain
constexpr int PEAK_AM_START = 8 * 60, PEAK_AM_END = 10 * 60;
constexpr int PEAK_PM_START = 17 * 60, PEAK_PM_END = 20 * 60;
