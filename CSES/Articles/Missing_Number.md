# CSES 1083 — Missing Number (Study Guide)

---

## Problem (short quote)

> "You are given all numbers between 1,2,...,n except one. Your task is to find the missing number."

(Above is a short quote from the original problem. The rest below is a clear, beginner-friendly explanation and implementations.)

---

## Quick paraphrased statement

**Input**

* First line: integer `n` (how many numbers 1..n there are in total).
* Second line: `n-1` distinct integers, each between `1` and `n` (one number from 1..n is missing).

**Output**

* Print the missing integer (the value in 1..n that does not appear in the second line).

**Constraints (paraphrased)**

* `2 <= n <= 2 * 10^5` (so `n` can be up to two hundred thousand).

**Example**

```
Input:
5
2 3 1 5

Output:
4
```

---

## Intuition (explain before coding)

Imagine you know the sum of the full sequence `1 + 2 + ... + n`. If you compute that sum and then subtract the sum of the `n-1` numbers you are given, the result is exactly the missing number.

A neat formula gives the sum of the first `n` natural numbers:

$$
1 + 2 + \dots + n = \frac{n(n+1)}{2}
$$

So the plan is:

1. Compute `total = n*(n+1)/2`.
2. Compute `given_sum = sum of the n-1 numbers`.
3. Answer = `total - given_sum`.

**Alternate trick (bitwise):** XOR all numbers from `1..n` and XOR with all given numbers; the remaining value is the missing number. Both approaches are O(n) time and O(1) extra space. The sum approach needs a large integer type to avoid overflow for larger `n` (use 64-bit). The XOR approach avoids overflow issues but works because `x ^ x = 0` and XOR is reversible.

---

## Step-by-step approach

1. Read integer `n`.
2. Compute `total = n*(n+1)//2` (use 64-bit integer when implementing).
3. Read the `n-1` input numbers while accumulating `given_sum`.
4. Print `total - given_sum`.

**Why this is safe and fast**

* You only scan the input once — O(n) time.
* You store just a couple of variables (no big arrays), so O(1) extra memory.
* With `n <= 2e5`, `total` fits easily in 64-bit (`~2e10`). On languages with 32-bit `int`, use `long`/`long long`/`int64` for the sum.

---

## Compact ASCII flow diagram (keeps lines narrow)

```
[ Input n, n-1 numbers ]
             |
             v
[ compute total = n*(n+1)/2 ]
             |
             v
[ sum given numbers -> given_sum ]
             |
             v
[ missing = total - given_sum ]
             |
             v
[ Print missing number ]
```

Each box is a single step. This illustrates the linear data flow: read -> compute total -> accumulate -> subtract -> output.

---

## Edge cases & gotchas (for beginners)

* **Overflow:** If you store `total` in a 32-bit `int` and `n` is large, the multiplication `n*(n+1)` can overflow. Use 64-bit integer types (`long long` / `long`) for sums.
* **Input format:** There are exactly `n-1` numbers on the second line; don't attempt to read `n` numbers.
* **Order doesn't matter:** The given numbers may be in any order — the sum method and XOR method both ignore order.
* **Zero or negative numbers:** Problem guarantees numbers are between `1` and `n`, so you don't need to validate them for negativity.

---

## Complexity

* Time complexity: $O(n)$ — reading `n-1` numbers once.
* Space complexity: $O(1)$ extra memory (a few variables only).

---

## Implementations

Below are straightforward implementations using the sum method. Each program reads from standard input and writes the missing number to standard output.

### C++ (preferred) — sum method

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;            // use 64-bit to be safe for the sum
    cin >> n;

    long long total = n * (n + 1) / 2;  // sum 1..n
    long long given_sum = 0;            // accumulate the n-1 numbers

    for (long long i = 0; i < n - 1; ++i) {
        long long x;
        cin >> x;
        given_sum += x;   // simple accumulation
    }

    cout << (total - given_sum) << '\n';  // the missing number
    return 0;
}
```

**Notes (C++):**

* We used `long long` to avoid overflow for the `total` value.
* `ios::sync_with_stdio(false)` + `cin.tie(nullptr)` speeds up IO for large inputs.

---

### C++ — alternative XOR method

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int xr = 0;
    // XOR all 1..n
    for (int i = 1; i <= n; ++i) xr ^= i;

    // XOR all given numbers; cancels out the present ones
    for (int i = 0; i < n - 1; ++i) {
        int x; cin >> x;
        xr ^= x;
    }

    cout << xr << '\n'; // remaining value is the missing number
    return 0;
}
```

**When to prefer XOR:** if you worry about integer overflow or want a cute bitwise trick. For constraints here, `long long` sum is simpler and fast.

---

### Java — sum method

```java
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        long n = fs.nextLong();
        long total = n * (n + 1) / 2;
        long givenSum = 0;
        for (int i = 0; i < n - 1; ++i) {
            givenSum += fs.nextLong();
        }
        System.out.println(total - givenSum);
    }

    // small fast scanner for competitive programming
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;
        FastScanner(InputStream is) { in = is; }
        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }
        long nextLong() throws IOException {
            int c;
            while ((c = read()) <= ' ') if (c == -1) return -1;
            long sign = 1;
            if (c == '-') { sign = -1; c = read(); }
            long val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }
    }
}
```

**Notes (Java):** use `long` for the sums. I included a compact fast scanner which is useful in contests to avoid slow `Scanner`.

---

### Python 3 — sum method (easy and short)

```python
import sys

data = list(map(int, sys.stdin.read().strip().split()))
# data[0] = n, the rest are the n-1 numbers
n = data[0]
nums = data[1:]

total = n * (n + 1) // 2
print(total - sum(nums))
```

**Notes (Python):**

* This reads the whole input at once which is fine for n up to 2e5.
* Python integers are unbounded, so overflow is not a concern.

---

### JavaScript (Node.js) — sum method

```javascript
// Run with: node solution.js < input.txt
const fs = require('fs');
const data = fs.readFileSync(0, 'utf8').trim().split(/\s+/).map(Number);
const n = data[0];
let total = n * (n + 1) / 2;
let givenSum = 0;
for (let i = 1; i < data.length; ++i) givenSum += data[i];
console.log(total - givenSum);
```

**Notes (JS):** use `Number` (double precision) — for `n <= 2e5` the sums are exact in IEEE-754 integer range (integers up to 2^53 are exact). If you ever have larger bounds, consider BigInt.

---

## Quick practice tips

* Try both the sum and XOR approach on paper with a small example to convince yourself they work.
* Always think about integer sizes when dealing with formulas: temporary multiplications may overflow small integer types.
* For competitive programming, prefer reading input in a buffered way for larger inputs.

---
