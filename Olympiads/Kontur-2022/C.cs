using System;
using System.Collections.Generic;
using System.Linq;

namespace KonturContests
{
    internal static class Program
    {
        class Meduzka : IComparable<Meduzka>
        {
            public long id, x, y, z, r;
            public bool state;

            public Meduzka(long _id, long _x, long _y, long _z, long _r)
            {
                id = _id;
                x = _x;
                y = _y;
                z = _z;
                r = _r;
                state = false;
            }

            public int CompareTo(Meduzka meduzka)
            {
                return (int)(z - meduzka.z);
            }
        }

        static Meduzka[] more;

        static void Main()
        {
            long N = long.Parse(Console.ReadLine());
            more = new Meduzka[N];
            for (long i = 0; i < N; ++i)
            {
                string[] input = Console.ReadLine().Split(' ');

                more[i] = new Meduzka(
                    i, long.Parse(input[0]), long.Parse(input[1]), long.Parse(input[2]), long.Parse(input[3])
                );

                if (i > 0 && more[i].z <= more[0].z)
                {
                    more[i].id = -1;
                }
            }
            more[0].state = true;

            Array.Sort(more);

            long ans = 1;
            for (long i = 0; i < N - 1; ++i)
            {
                if (!more[i].state || more[i].id == -1) continue;
                for (long j = i + 1; j < N; ++j)
                {
                    if (more[j].state || more[j].id == -1) continue;

                    long x1 = more[i].x,
                         x2 = more[j].x,
                         y1 = more[i].y,
                         y2 = more[j].y,
                         r1 = more[i].r,
                         r2 = more[j].r;

                    double d = Math.Sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                    if (d <= r1 + r2)
                    {
                        more[j].state = true;
                        ++ans;
                    }
                }
            }

            Console.WriteLine(ans);

            long[] poryadok = new long[ans];
            long s = 0;
            foreach (Meduzka meduzka in more)
            {
                if (meduzka.state && meduzka.id != -1)
                {
                    poryadok[s++] = meduzka.id + 1;
                }
            }
            Array.Sort(poryadok);
            foreach (long p in poryadok)
            {
                Console.Write($"{p} ");
            }
            Console.Write('\n');
        }
    }
}

