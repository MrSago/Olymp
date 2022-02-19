using System;

namespace KonturContests
{
    internal static class Program
    {
        static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            ulong a = ulong.Parse(input[0]);
            ulong b = ulong.Parse(input[1]);
            ulong ans = (ulong)(
                a == b ?
                Math.Sqrt(a + b) :
                Math.Sqrt(Math.Min(a, b) + Math.Min(a, b) + 1)
            );
            Console.WriteLine(ans);
        }
    }
}

