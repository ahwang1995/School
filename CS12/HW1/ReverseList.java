import java.io.*;
import java.util.*;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/
public class ReverseList {
	public void ReverseList(String inputFile) throws IOException
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
		List<String> words = new LinkedList<String>();
		int counter = 0;
		while(read.hasNextLine())
		{
			words.add(counter,read.nextLine());
			counter++;
		}
		for (int i = words.size()-1; i>=0; i--)
		{
			if(words.get(i) != null)
			{
				System.out.println(words.get(i));
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
