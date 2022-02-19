
using System;

namespace KonturContests
{
    internal static class Program
    {
        static void Main()
        {
            int L = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            string t = Console.ReadLine();

            int[] cnt_t = new int[26];
            foreach (char c in t)
            {
                ++cnt_t[c - 'a'];
            }

            int[] cnt_s = new int[26];
            int res = 0, ix = 0;
            bool start = true;
            for (int i = 0; i < s.Length; ++i)
            {
                if (cnt_t[s[i] - 'a'] > 0)
                {
                    --cnt_t[s[i] - 'a'];
                    ++cnt_s[s[i] - 'a'];
                    ++res;
                    if (start) 
                    {
                        ix = i;
                        start = false;
                    }
                }
                else
                {
                    for (int j = 0; j < 26; ++j)
                    {
                        cnt_t[j] += cnt_s[j];
                        cnt_s[j] = 0;
                    }
                    res = 0;
                    start = true;
                }
                if (res == L)
                {
                    Console.WriteLine("YES");
                    Console.WriteLine(s.Substring(ix, res));
                    return;
                }
            }
            Console.WriteLine("NO");
        }
    }
}

