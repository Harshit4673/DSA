🧠 String Tips & Tricks
Use HashMaps/Sets: Useful for frequency/count, anagrams, duplicates.
Sliding Window: For longest substring without repeating, max freq window, etc.
Two Pointers: Palindromes, reverse words in-place.
Prefix Sum/Array: For substring sum or pattern frequency.
Sort the String: Great for detecting anagrams or canonical forms.

🧠 General String Tips & Tricks
Use HashMap or array (int[26]) to track character frequencies.
Apply sliding window for substring problems (like longest unique substring).
Use two pointers for reversing, checking palindrome, or trimming.
Convert between char ↔ int using ASCII tricks ('0' = 48, 'a' = 97)
Strings are immutable in many languages, use mutable objects for edits (e.g., StringBuilder, char[]).
Sort the string for anagram grouping or canonical form.
Use s + s trick to check for rotated strings.
Use stringstream (C++) or split() (Python) to tokenize strings.
Prefer in-place operations when space is constrained.
Watch out for edge cases: empty string, case sensitivity, single character, special characters.

🧰 Useful String STL Functions (C++)
s.append("hello")   
s.length() or s.size() → get length
s.substr(i, len) → substring
s.find("abc") → find substring index
s.erase(pos, len) → remove part of string
s.insert(pos, str) → insert string
sort(s.begin(), s.end()) → sort characters
reverse(s.begin(), s.end()) → reverse string
stringstream ss(s) + getline(ss, word, ' ') → split string
to_string(int) or stoi(string) → convert between string & number
Use char - 'a' or char - '0' for index conversion

🧮 Time & Space Complexity of Common String Operations
Access character: O(1)
Concatenate: O(n) (if not optimized)
Compare strings: O(n)
Substring: O(k), where k is length of substring
Find/IndexOf: O(n)
Sorting: O(n log n)

🔁 1. Reverse a String
Use two-pointer swap from start and end.
Strings are immutable in many languages; use a char array if needed.
Watch out for edge cases like empty or 1-char strings.
Can also use stack to reverse but takes extra space.
Time: O(n), Space: O(1) if done in-place.

👬 2. Check if Two Strings are Anagrams
Sort both strings and compare them.
Or use frequency arrays (int freq[26]).
Case sensitivity may matter—clarify problem statement.
Don't forget to check if lengths are equal first.
Time: O(n log n) using sort, O(n) using counting.

🧩 3. Longest Substring Without Repeating Characters
Use sliding window + HashSet or map.
Keep track of window start and end indexes.
Remove characters from set/map when a repeat is found.
Update max length while sliding window.
Time: O(n), Space: O(n).

📊 4. Longest Palindromic Substring
Use expand-around-center for optimal time/space.
Check both even and odd centers.
DP takes O(n²) space but is easier to implement.
Track start and max length of palindrome.
Time: O(n²), Space: O(1) with expand method.

📥 5. Rabin-Karp / KMP Algorithm
Rabin-Karp uses hash for substring search.
KMP uses prefix table (lps array).
Better than naive for repeated patterns.
Avoids rechecking already matched chars.
Time: O(n + m), Space: O(m) for KMP.

🔁 6. String Compression
Traverse string and count consecutive chars.
Append char and count to result.
If compressed string is not smaller, return original.
Watch out for edge cases like "a".
Time: O(n), Space: O(n) or O(1) if in-place.

✂️ 7. Check if String is Palindrome
Use two-pointer from ends.
Skip non-alphanumeric if needed.
Lowercase both chars before comparison.
Reverse and compare is also valid.
Time: O(n), Space: O(1).

📦 8. Group Anagrams
Sort each string to use as key in map.
Store original strings in map values.
Use unordered_map<string, vector<string>>.
Canonical form trick avoids false negatives.
Time: O(n \* k log k), Space: O(nk).

➕ 9. Multiply Two Large Numbers (as strings)
Simulate manual digit-by-digit multiplication.
Use int array to hold intermediate products.
Reverse strings to simplify logic.
Handle carry and trim leading zeros.
Time: O(n \* m), Space: O(n + m).

🔄 10. Check if One String is Rotation of Another
Concatenate original with itself.
Check if rotated string is a substring.
Lengths must be equal.
Use s1 + s1 and check s2 in it.
Time: O(n), Space: O(n).

🎯 11. Minimum Window Substring
Use sliding window + frequency map.
Count how many chars still needed.
Move end to expand, start to contract.
Update result when all needed chars are in.
Time: O(n), Space: O(1) for fixed charset.

💬 12. Z-Algorithm / Trie / Suffix Array
Z-algo for substring search in linear time.
Trie for prefix lookups and autocomplete.
Suffix arrays for advanced string matching.
Great for genome sequencing or search engines.
Time: Z-algo: O(n), Trie: O(n \* k), Suffix Array: O(n log n).
