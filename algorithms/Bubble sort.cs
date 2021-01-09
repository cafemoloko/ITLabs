using System;
using System.Collections.Generic;

namespace SandBox
{
    class Program
    {
        static void Main()
        {

            //Bubble sort - an array
            int[] nums = { 3, 7, 0, 19, 4 };

            int temp;
            for (int j = 0; j <= nums.Length - 2; j++)
            {
                for (int i = 0; i <= nums.Length - 2; i++)
                {
                    if (nums[i] > nums[i + 1])
                    {
                        temp = nums[i + 1];
                        nums[i + 1] = nums[i];
                        nums[i] = temp;
                    }


                }
            }
            foreach (int n in nums)
            {
                Console.WriteLine(n);
            }

            //Bubble sort - a list
            List<int> list = new List<int>() { 2, 78, 4, 19 };

            int size = list.Capacity;
            for (int i = 1; i < size; i++)
            {
                for (int j = 0; j < (size - i); j++)
                {
                    if (list[j] > list[j + 1])
                    {
                        int tem = list[j];
                        list[j] = list[j + 1];
                        list[j + 1] = tem;
                    }
                }
            }

            foreach (int l in list)
            {
                Console.WriteLine(l);
            }



            Console.ReadKey();
        }
    }
}
