import java.lang.Comparable;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/
/** This is a Heap Sort
 *  @author Andrew Hwang 
 *  @date 14 May 2014
 */
public class HeapSort12 implements Sort12
{
	public  <T extends Comparable<? super T>> void sort(List<T> list)
	{
		if(list == null) throw new NullPointerException();
		Heap12<T> newheap = new Heap12<T>();
		for(int i = 0;i<list.size();i++)
		{
			newheap.offer(list.get(i));
		}
		for(int i = 0;i<list.size();i++)
		{
			list.set(i, newheap.poll());
		}
	}
}
// vim:ts=4:sw=4:sw=78
