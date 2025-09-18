# Weird Algorithm (CSES 1068)

> **Problem (from CSES)**

Consider an algorithm that takes as input a positive integer `n`. If `n` is even, the algorithm divides it by two, and if `n` is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until `n` is one. For example, the sequence for `n = 3` is as follows:

```
3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
```

Your task is to simulate the execution of the algorithm for a given value of `n`.

**Input**

The only input line contains an integer `n`.

**Output**

Print a line that contains all values of `n` during the algorithm.

**Constraints**

* `1 <= n <= 10^6`

**Example**

Input:

```
3
```

Output:

```
3 10 5 16 8 4 2 1
```

---

## Intuition

This is the classic *Collatz-style* simulation (called "Weird Algorithm" here). We simply follow the rule repeatedly and print each value until we reach `1`.

Key observations:

* The process always terminates at `1` for the input bounds given by the problem (CSES guarantees test cases here are small enough).
* Multiplying by 3 and adding 1 can grow the number, so use a 64-bit integer type to be safe.
* The number of terms printed is not bounded by a tiny constant, but for `n <= 10^6` it fits easily within time/memory limits.

---

## Approach (step-by-step)

1. Read `n` as a 64-bit integer.
2. Validate `n` is within the allowed range (sanity check).
3. While `n != 1`:

   * Print `n` followed by a space.
   * If `n` is even: `n = n / 2`.
   * Else (odd): `n = 3*n + 1`.
4. After the loop, print the final `1` and a newline.

This is a direct simulation — O(k) time where `k` is the number of terms produced, and O(1) extra memory.

---

## Compact ASCII flow (keeps width small)

```
+---------------------------+
| start: read n             |
+------------+--------------+
             |
         n==1? --yes--> print 1, end
             |
            no
             |
    +--------v---------+
    | print n          |
    | if even: n/=2    |
    | else:   n=3*n+1   |
    +--------+---------+
             |
           loop back
```

---

## Complexity

* **Time:** $O(k)$ where `k` is the number of values printed (sequence length). For inputs up to `10^6` this is well within limits.
* **Space:** $O(1)$ extra memory.

---

## Implementations

All implementations print the sequence on a single line separated by spaces. Per request, the approach is explained above *before* the code.

### C++ (preferred)

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long; // handy alias for 64-bit

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    if(!(cin >> n)) return 0; // no input -> exit gracefully

    // input validation / sanity check
    if (n < 1 || n > 1000000) {
        // CSES guarantees the constraints, but we assert for safety
        cerr << "Input out of bounds: " << n << "\n";
        // still attempt to proceed, or exit. Here we exit with failure.
        return 1;
    }

    // simulate and print as we go
    while (n != 1) {
        cout << n << ' ';
        if (n % 2 == 0) {
            n = n / 2; // even case
        } else {
            n = 3 * n + 1; // odd case (use ll to avoid overflow)
        }
    }
    cout << 1 << '\n'; // final value
    return 0;
}
```

**Notes (C++):**

* We used `long long` to avoid overflow when computing `3*n + 1`.
* We included a simple input validation to detect obviously invalid inputs.
* The program writes values as it computes them — no extra storage required.

### Java

```java
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        if (s == null || s.trim().isEmpty()) return;
        long n = Long.parseLong(s.trim());

        if (n < 1 || n > 1000000) {
            System.err.println("Input out of bounds: " + n);
            System.exit(1);
        }

        StringBuilder sb = new StringBuilder();
        while (n != 1) {
            sb.append(n).append(' ');
            if (n % 2 == 0) n = n / 2;
            else n = 3 * n + 1;
        }
        sb.append(1);
        System.out.println(sb.toString());
    }
}
```

**Notes (Java):**

* `long` is used for safety.
* We build the output in a `StringBuilder` to avoid many small prints (though printing incrementally is also fine here).

### Python 3

```python
import sys

data = sys.stdin.read().strip().split()
if not data:
    sys.exit(0)

n = int(data[0])
if n < 1 or n > 10**6:
    print(f"Input out of bounds: {n}", file=sys.stderr)
    sys.exit(1)

out = []
while n != 1:
    out.append(str(n))
    if n % 2 == 0:
        n //= 2
    else:
        n = 3*n + 1
out.append('1')
print(' '.join(out))
```

**Notes (Python):**

* Uses a list to collect terms then prints at once. For memory-constrained scenarios you could stream print.

### JavaScript (Node.js)

```javascript
const fs = require('fs');
const data = fs.readFileSync(0, 'utf8').trim();
if (!data) process.exit(0);
let n = Number(data.split(/\s+/)[0]);
if (n < 1 || n > 1_000_000) {
  console.error('Input out of bounds: ' + n);
  process.exit(1);
}

const out = [];
while (n !== 1) {
  out.push(String(n));
  if (n % 2 === 0) n = n / 2;
  else n = 3 * n + 1;
}
out.push('1');
console.log(out.join(' '));
```

---

## Extra tips & pitfalls

* Use a 64-bit integer type in C++/Java because `3*n + 1` can exceed 32-bit signed range for some intermediate values.
* Streaming prints (printing as you compute) is fine here; building a large string is also fine for these constraints.
* The Collatz sequence is famous: termination for all positive integers is unproven in general, but for the problem constraints you'll be fine.

---

If you want, I can also:

* Provide a version that prints incrementally without storing the whole sequence (for extremely large sequences).
* Add unit tests or a short custom test runner.
* Minify the C++ solution into a competitive-programming one-liner style.
