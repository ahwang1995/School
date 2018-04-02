import java.util.ArrayList;
import java.util.AbstractQueue;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/
/** Heap12 class that implements an unbounded array-backed heap structure and is
 * an extension of the Java Collections AbstractQueue class 
 * <p>
 * The elements of the heap are ordered according to their natural 
 * ordering,  Heap12 does not permit null elements. 
 * The top of this heap is the minimal or maximal element (called min/max)  
 * with respect to the specified natural ordering.  
 * If multiple elements are tied for min/max value, the top is one of 
 * those elements -- ties are broken arbitrarily. 
 * The queue retrieval operations poll and  peek 
 * access the element at the top of the heap.
 * <p>
 * A Heap12 is unbounded, but has an internal capacity governing the size of 
 * an array used to store the elements on the queue. It is always at least as 
 * large as the queue size. As elements are added to a Heap12, its capacity 
 * grows automatically. The details of the growth policy are not specified.
 * <p>
 * This class and its iterator implements the optional methods of the 
 * Iterator interface (including remove()). The Iterator provided in method 
 * iterator() is not guaranteed to traverse the elements of the Heap12 in 
 * any particular order. 
 * <p>
 * Note that this implementation is not synchronized. Multiple threads 
 * should not access a Heap12 instance concurrently if any of the 
 * threads modifies the Heap12. 
 */
public class Heap12<E extends Comparable <? super E>> extends 
	AbstractQueue<E> 
{
	protected ArrayList<E> myarray;
	private int capacity, nelems;
	private boolean isMax;
	/** O-argument constructor. Creates and empty Heap12 with unspecified
 	 *  initial capacity, and is a min-heap 
 	 */ 
	public Heap12()
	{
		nelems = 0;
		myarray = new ArrayList<E>(5);
		capacity = 5;
		isMax = false;
		for(int i = 0; i< capacity; i++)
		{
			myarray.add(null);
		}
	}

	/** 
 	 * Constructor to build a min or max heap
 	 * @param isMaxHeap 	if true, this is a max-heap, else a min-heap 
 	 */ 
	public Heap12( boolean isMaxHeap)
	{
		nelems = 0;
		myarray = new ArrayList<E>(5);
		capacity = 5;
		for(int i = 0; i< capacity; i++)
		{
			myarray.add(null);
		}
		if(isMaxHeap)
		{
			isMax = true;
		}
		else
		{
			isMax = false;
		}
	}

	/** 
 	 * Constructor to build a with specified initial capacity 
 	 *  min or max heap
 	 * @param capacity  	initial capacity of the heap.	
 	 * @param isMaxHeap 	if true, this is a max-heap, else a min-heap 
 	 */ 
	public Heap12( int capacity, boolean isMaxHeap)
	{
		nelems = 0;
		this.capacity = capacity;
		myarray = new ArrayList<E>(capacity);
		for(int i = 0; i< capacity; i++)
		{
			myarray.add(null);
		}
		if(isMaxHeap)
		{
			isMax = true;
		}
		else
		{
			isMax = false;
		}
	}
	/** Copy constructor. Creates Heap12 with a deep copy of the argument
 	 * @param toCopy      the heap that should be copied
 	 */
	public Heap12 (Heap12<E> toCopy)
	{
		myarray = new ArrayList<E>(toCopy.capacity);
		for(int i = 0; i< toCopy.capacity; i++)
		{
			myarray.add(toCopy.myarray.get(i));
		}
		nelems = toCopy.nelems;
		capacity = toCopy.capacity;
	}

	/* The following are defined "stub" methods that provide degenerate
	 * implementations of methods defined as abstract in parent classes.
	 * These need to be coded properly for Heap12 to function correctly
	 */

	public boolean isMax()
	{
		return isMax;
	}
	public int capacity()
	{
		return capacity;
	}
	/** Size of the heap
 	 * @return the number of elements stored in the heap
	*/
	public int size()
	{
		return nelems; 
	}

	/** 
 	 * @return an Iterator for the heap 
	*/
	public Iterator<E> iterator()
	{
		return new Heap12Iterator(); 
	}

	/** peek - see AbstractQueue for details 
 	 * 
 	 * @return Element at top of heap. Do not remove 
	*/
	public E peek()
	{
        return (E) myarray.get(0);
	}
	/** poll - see AbstractQueue for details 
 	 * @return Element at top of heap. And remove it from the heap. 
 	 * 	return <tt>null</tt> if the heap is empty
	*/
	public E poll()
	{
		E removedelement = peek();
		if(removedelement == null)
		{
			return removedelement;
		}
		int endelementindex = findendelementindex();
		if(endelementindex == 0)
		{
			myarray.set(0,null);
			nelems--;
			return removedelement;
		}
		myarray.set(0, myarray.get(endelementindex));
		myarray.set(endelementindex, null);
		nelems--;
		if(isMax)
		{
			trickleDownMax(0);
		}
		else
		{
			trickleDownMin(0);
		}
		return removedelement;
	}
	/** offer -- see AbstractQueue for details
	 * insert an element in the heap
	 * @return true
	 * @throws NullPointerException 
	 * 	if the specified element is null	
	 */
	public boolean offer (E e) throws NullPointerException
	{
		if(e == null) throw new NullPointerException("Can't add null element");
		E parent = peek();
		int endelementindex = findendelementindex();
		if(endelementindex == capacity()-1)
		{
			for(int i = 0; i < capacity;i++)
			{
				myarray.add(null);
			}
			capacity = capacity*2;
			myarray.set(endelementindex + 1,e);
			nelems++;
			if(isMax)
			{
				bubbleUpMax(endelementindex + 1);
				return true;
			}
			else
			{
				bubbleUpMin(endelementindex + 1);
				return true;
			}
		}
		if(parent == null)
		{
			myarray.set(0,e);
			nelems++;
			return true;
		}
		if(myarray.get(endelementindex + 1) == null)
		{
			myarray.set(endelementindex + 1, e);
			nelems++;
			if(isMax)
			{
				bubbleUpMax(endelementindex + 1);
				return true;
			}
			else
			{
				bubbleUpMin(endelementindex + 1);
				return true;
			}
		}
		return false;
	}


	/* ------ Private Helper Methods ----
     *  DEFINE YOUR HELPER METHODS HERE
     */
	private void trickleDownMax(int index)
	{
		int newindex = index;
		int child1index = newindex*2 + 1;
		int child2index = newindex*2 + 2;
		int largestchildindex;
		E parent = myarray.get(newindex);
		if(child1index >= size())
		{
			return;
		}
		E child1 = findchild1(newindex);
		E child2 = null;
		E largestchild = null;
		if(child2index >= size())
		{
			child2 = child1;
		}
		if(child2index < size())
		{
			child2 = findchild2(newindex);
		}
		if(child1.compareTo(child2) >= 0)
		{
			largestchild = child1;
			largestchildindex = child1index;
		}
		else
		{
			largestchild = child2;
			largestchildindex = child2index;
		}
		if(parent.compareTo(largestchild) > 0)
		{
			return;
		}
		myarray.set(newindex, largestchild);
		myarray.set(largestchildindex, parent);
		trickleDownMax(largestchildindex);
	}
	private void trickleDownMin(int index)
	{
		int newindex = index;
		int child1index = newindex*2 + 1;
		int child2index = newindex*2 + 2;
		int smallestchildindex;
		E parent = myarray.get(newindex);
		if(child1index >= size())
		{
			return;
		}
		E child1 = findchild1(newindex);
		E child2 = null;
		E smallestchild = null;
		if(child1index >= size())
		{
			return;
		}
		if(child2index >= size())
		{
			child2 = child1;
		}
		if(child2index < size())
		{
			child2 = findchild2(newindex);
		}
		if(child1.compareTo(child2) <= 0)
		{
			smallestchild = child1;
			smallestchildindex = child1index;
		}
		else
		{
			smallestchild = child2;
			smallestchildindex = child2index;
		}
		if(parent.compareTo(smallestchild) < 0)
		{
			return;
		}
		myarray.set(newindex, smallestchild);
		myarray.set(smallestchildindex, parent);
		trickleDownMin(smallestchildindex);
	}
	private void bubbleUpMax(int index)
	{
		int newindex = index;
		int parentindex = (newindex-1)/2;
		E parent = findparent(newindex);
		E child = myarray.get(newindex);
		if(myarray.get(newindex).compareTo(parent) <= 0)
		{
			return;
		}
		myarray.set(newindex, parent);
		myarray.set(parentindex, child);
		bubbleUpMax(parentindex);
	}
	private void bubbleUpMin(int index)
	{
		int newindex = index;
		int parentindex = (newindex-1)/2;
		E parent = findparent(newindex);
		E child = myarray.get(newindex);
		if(myarray.get(newindex).compareTo(parent) >= 0)
		{
			return;
		}
		myarray.set(newindex, parent);
		myarray.set(parentindex, child);
		bubbleUpMin(parentindex);
	}
	private E findparent(int index)
	{
		int parentindex = (index-1)/2;
		E parent = myarray.get(parentindex);
		return parent;
	}
	private E findchild1(int index)
	{
		int child1index = 2*index + 1;
		E child1 = myarray.get(child1index);
		return child1;
	}
	private E findchild2(int index)
	{
		int child2index = 2*index + 2;
		E child2 = myarray.get(child2index);
		return child2;
	}
	private int findendelementindex()
	{
		int lastindex = 0;
		for(int i = capacity-1; i>0;i--)
		{
			if(myarray.get(i) != null)
			{
				lastindex = i;
				break;
			}
		}
		return lastindex;
	}

    /** Inner Class for an Iterator **/
    /* stub routines */

	private class Heap12Iterator implements Iterator<E>
	{
		private int pointer;
		private boolean canRemove;
        private Heap12Iterator()
        {
        	pointer = -1;
        }

        /* hasNext() to implement the Iterator<E> interface */
		public boolean hasNext()
		{
			if(pointer < myarray.size()-1)
			{
				return true;
			}
            return false;
		}

        /* next() to implement the Iterator<E> interface */
		public E next() throws NoSuchElementException
		{
			if(hasNext())
			{
				canRemove = true;
				pointer++;
				return myarray.get(pointer);
			}
			else
			{
				throw new NoSuchElementException("hasNext is false");
			}
            
		}
        /* remove() to implement the Iterator<E> interface */
		public void remove() throws IllegalStateException
		{
			if(!canRemove)
			{
				throw new IllegalStateException("can not remove element");
			}
			int endelementindex = findendelementindex();
			myarray.set(pointer, myarray.get(endelementindex));
			myarray.set(endelementindex, null);
			nelems--;
			if(isMax)
			{
				trickleDownMax(pointer);
			}
			else
			{
				trickleDownMin(pointer);
			}
			canRemove = false;
		}	
    }
} 
// vim:ts=4:sw=4:tw=78:et
