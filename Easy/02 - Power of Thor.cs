using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
class Player
{
    static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split(' ');
        int lightX = int.Parse(inputs[0]); // the X position of the light of power
        int lightY = int.Parse(inputs[1]); // the Y position of the light of power
        int initialTX = int.Parse(inputs[2]); // Thor's starting X position
        int initialTY = int.Parse(inputs[3]); // Thor's starting Y position
        
        int newX = initialTX;
        int newY = initialTY;

        // game loop
        while (true)
        {
            int remainingTurns = int.Parse(Console.ReadLine()); // The remaining amount of turns Thor can move. Do not remove this line.

            if(newX < lightX) // light source is to the right
            {
                newX++;
                if(newY < lightY) // light source is above
                {
                    newY++;
                    Console.WriteLine("SE");
                }
                else if(newY > lightY)
                {
                    newY--;
                    Console.WriteLine("NE");
                }
                else
                {
                    Console.WriteLine("E");
                }
            }
            else if(newX > lightX)
            {
                newX++;
                if(newY < lightY)
                {
                    newY++;
                    Console.WriteLine("SW");
                }
                else if(newY > lightY)
                {
                    newY--;
                    Console.WriteLine("NW");
                }
                else
                {
                    Console.WriteLine("W");
                }
            }
            else
            {
                if(newY < lightY)
                {
                    newY++;
                    Console.WriteLine("S");
                }
                if(newY > lightY)
                {
                    newY--;
                    Console.WriteLine("N");
                }
            }

            //Console.WriteLine("SE");
        }
    }
}
