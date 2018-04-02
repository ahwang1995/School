import java.io.*;
import java.util.*;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/
public class ReverseArray {
	public void ReverseArray(String inputFile)
	{
		File inFile = null;
		Scanner read = null;
		try
		{
		  inFile = new File(inputFile);
		  read = new Scanner(inFile);
		}
		catch(FileNotFoundException e)
		{
			System.out.println("File not found");
			System.exit(-1);
		}
		int arrayLength = 100;
		String[] words = new String[arrayLength];
		int counter = 0;
		while(read.hasNextLine())
		{
			try
			{
				words[counter] = read.nextLine();
				counter++;
			}
			catch (ArrayIndexOutOfBoundsException e)
			{
				arrayLength = arrayLength*2;
				String [] tempArray = new String[arrayLength];
				for(int i = 0; i<words.length; i++)
				{
					tempArray[i] = words[i];
				}
				words = tempArray;
			}
		}
		for (int i = words.length-1; i>=0; i--)
		{
			if(words[i] != null)
			{
				System.out.println(words[i]);
			}
		}
	}
	public static void main(String[] args)
	{
		if(args.length == 0)
		{
			System.out.println("usage: ReverseArray <filename>");
			return;
		}
		ReverseArray a = new ReverseArray();
		a.ReverseArray(args[0]);
	}
}