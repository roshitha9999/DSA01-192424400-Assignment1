 TASK 11 – RECOMMEND AND DEFEND THE FINAL DESIGN
## 1. Recommended Design

I recommend using the following design for the metro smart-card system:

- **Money:** Use `long long` to store all fares and balances in paise. Convert into rupees only when displaying the fare.
- **Constants:** Use `constexpr` in a single header file to store base fares, surcharge percentages, minimum balance and peak-hour limits.
- **Zones:** Use `enum class Zone` to represent Inner, Middle and Outer zones safely.
- **Peak-hour rule:** Use an `isPeak()` function with minutes since midnight and half-open time intervals.
- **SmartCard class:** Keep the balance private and provide `canTravel()` and `deduct()` functions to prevent negative balances.
- **Fare function:** Calculate fares using integer percentage calculations and half-up rounding.
- **Input handling:** Use input validation with `fail()`, `clear()` and `ignore()`.
- **Compiler:** Use `-std=c++17 -Wall -Wextra` and treat warnings as errors.

These choices are supported by the experiments. Task 3 showed floating-point errors, Task 10 showed integer overflow, Task 2 demonstrated the advantage of `constexpr` and `enum class`, and Task 7 showed that private balance control prevents invalid deductions.

## 2. How a Fare Revision Will Be Carried Out

1. Change the fare values in the single constants header file.
2. Recompile the program using warning flags.
3. Update the expected values in the Task 9 test cases and execute the tests.
4. Deploy the updated executable to all metro gates.

This approach avoids changing fare values in multiple program files.

## 3. Limitations of the Design

- The 50% concession and rounding rule are assumptions and must be confirmed by the metro authority.
- Every fare revision requires recompilation and redeployment.
- The current program displays only whole rupees; a real system should display paise too.
- Simultaneous card updates at different gates require database transaction handling.
- The original design supports only three zones and does not include weekend discounts or monthly passes.

## 4. Is the Design Correct for the Whole Network?

Yes. The design is suitable for the whole network. In Task 10, the total for 3,000,000 journeys was 5,626,462,900 paise. This value fits safely in `long long`, whereas `int` overflowed.

Each fare calculation takes O(1) time. Therefore, processing 3 million journeys is efficient. The `long long` type also provides sufficient range for large fare totals.

## 5. Alternative Concept – Reading Fares from a Configuration File

Instead of storing fares in a compiled constants header, the metro can read fare values from a configuration file when the gate starts.

Example `fares.cfg`:

```text
1000
2000
3000
```

A C++ program can use `ifstream` to read the values and store them in a `vector<long long>`.

**Complexity analysis:**

- Reading `z` fare values takes O(z) time during start-up.
- Storing the fares requires O(z) space.
- Looking up a fare for each journey takes O(1) time.

For four zones, the vector uses approximately 32 bytes.

**Comparison:**

The configuration-file method makes fare revisions easier because the file can be updated without recompiling the program. However, the file must be validated because it may be missing or contain incorrect values.

**Final Recommendation:**

For the current small metro system, I recommend `constexpr` constants because they provide compile-time safety. If the metro network expands and fares change frequently, a validated configuration file is more convenient because it avoids recompiling and redeploying software at every gate.