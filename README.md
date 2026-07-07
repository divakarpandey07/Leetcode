# LeetCode Daily Auto-Submit Repository 🚀

This repository is set up to automatically solve LeetCode problems in C++ and push them to GitHub daily.

## 📊 Streak Statistics
- **Submissions Auto-Sync:** Enabled (via GitHub Actions)
- **Programming Language:** C++ (Clean code, comments removed)
- **Problem Set:** 500 curated LeetCode questions in C++

## 📁 How It Works
1. Every day at **10:30 AM IST (05:00 UTC)**, GitHub Actions triggers `submit_daily.js`.
2. It fetches the next solution from the hidden `.solutions_pool/` directory.
3. Submits it directly to the LeetCode account.
4. Moves the solution file to the root directory and commits it to this repository.

*(Both your GitHub contribution graph and LeetCode activity streak remain perfectly synchronized!)*
