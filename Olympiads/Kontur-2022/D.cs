
using System;
using System.Collections.Generic;
using System.Linq;

namespace KonturContests
{
    internal static class Program
    {
        static string s;
        static int[] k = { 0, 9, 4, 9, 4, 1, 4, 9, 4, 9 };
        static int[] ans = { 0, 1, 1, 3, 1, 1, 3, 7, 1, 9 };

        static int Solve()
        {
            int save = 0;
            for (int i = s.Length - 1; i > 0; --i)
            {
                int cur = s[i] - '0' + save;
                int x = cur % 10;
                save = (cur + x * k[x]) / 10;
            }

            int res = ans[s[0] - '0'];
            if (save > 0)
            {
                int cur = s[0] - '0' + save;
                if (cur < 10)
                {
                    res = ans[cur];
                }
                else
                {
                    res = ans[(cur + cur % 10 * k[cur % 10]) / 10];
                }
            }
            return res;
        }

        static void Main()
        {
            int t = int.Parse(Console.ReadLine());
            while (t-- > 0)
            {
                s = Console.ReadLine();
                Console.WriteLine(Solve());
            }
        }
    }
}

