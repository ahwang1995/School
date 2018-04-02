import java.lang.Comparable;
import java.util.List;
import java.util.ArrayList;
public class Merge12 implements Sort12
{
	public  <T extends Comparable<? super T>> void  sort(List<T> list)
	{
		if ( list == null )
			 throw new NullPointerException("Null argument to sort");

		// Create the arrayList to insert into
		ArrayList<T> inputArray = new ArrayList<T>(list.size());
		ArrayList<T> tempArray = new ArrayList<T>(list.size());
		
		for(int i = 0; i<list.size();i++)
		{
			inputArray.add(i,list.get(i));
		}
		for(int a = 0; a<list.size();a++)
		{
			tempArray.add(a,list.get(a));
		}
		
		internalMergeSort(inputArray,tempArray,0,list.size()-1);
		
		for(int j = 0; j<inputArray.size(); j++)
		{
			list.set(j,inputArray.get(j));
		}
	}
	private  <T extends Comparable<? super T>> void 
		internalMergeSort(ArrayList<T> inputArray, ArrayList<T> tempArray,
					int first, int last)
	{
		if(first<last)
		{
			int mid = first + ((last - first) /2);
			internalMergeSort(inputArray,tempArray,first,mid);
			internalMergeSort(inputArray,tempArray,mid+1,last);
			merge(inputArray,tempArray,first,mid,last);
		}
	} // internalMergeSort

	private  <T extends Comparable<? super T>> void 
		merge(ArrayList<T> inputArray, ArrayList<T> tempArray,
					int first, int mid, int last)
	{
		int firstIndex = first;
		int midIndex = mid+1;
		int index = first;
		
		for(int i = first; i<last;i++)
		{
			tempArray.set(i,inputArray.get(i));
		}
		
		while(firstIndex <= mid && midIndex <= last)
		{
			if(tempArray.get(firstIndex).compareTo(inputArray.get(midIndex)) <= 0)
			{
				inputArray.set(index,tempArray.get(firstIndex));
				firstIndex++;
			}
			else
			{
				inputArray.set(index,inputArray.get(midIndex));
				midIndex++;
			}
			index++;
			
		}
		while( firstIndex <= mid)
		{
			inputArray.set(index,tempArray.get(firstIndex));
			firstIndex++;
			index++;
		}
	} // Merge
}
// vim:ts=4:sw=4:sw=78
