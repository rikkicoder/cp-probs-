#include <stdio.h>
#include <iostream>
#include <vector>
int main()
{
    int n, k;
    char s[100001];
    scanf("%d%s%d", &n, s, &k);

    if (!k)
    {
        printf("0");
        return 0;
    }

    int l = 0, zs = 0, os = 0;
    long long ans = 0;

    for (int r = 0; r < n; r++)
    {
        if (s[r] == '0')
            zs++;
        else
            os++;

        while (zs > k || os > k)
        {
            if (s[l++] == '0')
                zs--;
            else
                os--;
        }

        ans += r - l + 1;
    }

    printf("%lld", ans);
    return 0;
}




// We only need iostream for input/output and string for... well, strings!
#include <iostream>
#include <string>

// It's good practice to put the core logic in its own function.
// This makes the main function clean and the code easier to read.
void solve() {
    int n;
    std::cin >> n;

    std::string s; // Using the much safer and more convenient std::string
    std::cin >> s;

    int k;
    std::cin >> k;

    // The special case for k=0 remains the same.
    if (k == 0) {
        std::cout << 0 << std::endl;
        return;
    }
    
    long long ans = 0;
    int left_pointer = 0;
    int zero_count = 0;
    int one_count = 0;

    // The sliding window logic is identical, just with cleaner variable names.
    // The 'right_pointer' expands the window to the right.
    for (int right_pointer = 0; right_pointer < n; ++right_pointer) {
        // Add the new character to our window's count.
        if (s[right_pointer] == '0') {
            zero_count++;
        } else {
            one_count++;
        }

        // If the window is no longer valid (too many 0s or 1s),
        // we shrink it from the left until it becomes valid again.
        while (zero_count > k || one_count > k) {
            // Remove the character at the left end of the window from the count.
            if (s[left_pointer] == '0') {
                zero_count--;
            } else {
                one_count--;
            }
            // Move the left pointer to shrink the window.
            left_pointer++;
        }

        // Now, the window [left_pointer, right_pointer] is valid.
        // This means any substring that ends at 'right_pointer' and starts
        // at or after 'left_pointer' is also valid.
        // The number of such substrings is (right_pointer - left_pointer + 1).
        ans += (right_pointer - left_pointer + 1);
    }

    std::cout << ans << std::endl;
}

int main() {
    // This is a standard trick in competitive C++ to speed up cin and cout.
    // It's like giving your program a speed boost.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
