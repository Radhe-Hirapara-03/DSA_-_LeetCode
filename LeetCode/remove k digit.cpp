class Solution {
public:
    string removeKdigits(string num, int k) {
        int idx = 0; // virtual stack pointer into num itself

        for (char c : num) {
            // pop larger digits from the top of our "stack"
            while (k > 0 && idx > 0 && num[idx - 1] > c) {
                idx--;
                k--;
            }
            // push current character
            num[idx++] = c;
        }

        // if k removals still remain, trim from the tail
        idx -= k;

        // strip leading zeros
        int i = 0;
        while (i < idx && num[i] == '0') i++;

        // erase in-place: trim unused tail, then leading zeros
        num.erase(idx);
        num.erase(0, i);

        return num.empty() ? "0" : num;
    }
};
