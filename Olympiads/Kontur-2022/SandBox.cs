
using System;
using System.Collections.Generic;
using System.Linq;

namespace Sandbox
{
    internal static class Program
    {
        static string s, t;

        class State
        {
            public int len, link;
            public Dictionary<char, int> next;
            public State()
            {
                len = 0;
                link = 0;
                next = new Dictionary<char, int>();
            }
        }

        const int MAXN = 100000;
        static State[] st;
        static int sz, last;

        static void InitState()
        {
            st = new State[2 * MAXN];
            for (int i = 0; i < 2 * MAXN; ++i)
            {
                st[i] = new State();
            }
            sz = last = 0;
            st[0].link = -1;
            ++sz;
        }

        static void ExtendState(char c)
        {
            int cur = sz++;
            st[cur].len = st[last].len + 1;

            int p = last;
            while (p != -1 && !st[p].next.ContainsKey(c))
            {
                st[p].next[c] = cur;
                p = st[p].link;
            }

            if (p == -1)
            {
                st[cur].link = 0;
            }
            else
            {
                int q = st[p].next[c];
                if (st[p].len + 1 == st[q].len)
                {
                    st[cur].link = q;
                }
                else
                {
                    int clone = sz++;
                    st[clone].len = st[p].len + 1;
                    st[clone].next = st[q].next.ToDictionary(entry => entry.Key, entry => entry.Value);
                    st[clone].link = st[q].link;

                    while (p != -1 && st[p].next[c] == q)
                    {
                        st[p].next[c] = clone;
                        p = st[p].link;
                    }

                    st[q].link = st[cur].link = clone;
                }
            }
            last = cur;
        }

        static string Solve()
        {
            InitState();
            for (int i = 0; i < s.Length; ++i)
            {
                ExtendState(s[i]);
            }

            int v = 0, l = 0, best = 0, bestpos = 0;
            for (int i = 0; i < t.Length; ++i)
            {
                while (v != 0 && !st[v].next.ContainsKey(t[i]))
                {
                    v = st[v].link;
                    l = st[v].len;
                }
                if (st[v].next.ContainsKey(t[i]))
                {
                    v = st[v].next[t[i]];
                    ++l;
                }
                if (l > best)
                {
                    best = l;
                    bestpos = i;
                }
            }
            return t.Substring(bestpos - best + 1, best);
        }

        static void Main()
        {
            s = Console.ReadLine();
            t = Console.ReadLine();
            Console.WriteLine(Solve());
        }
    }
}

