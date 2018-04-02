import java.util.*;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/

/*A double ended queue using a circular array*/
public class Deque12<E> implements BoundedDeque<E> {

	protected ArrayList<E> array;
	private int front, rear, nelems, capacity;
	
	/* Constructor to set pointers and create the arraylist of specified size*/
	public Deque12(int capacity)throws IllegalArgumentException
	{
		if(capacity<0) throw new IllegalArgumentException();
		array = new ArrayList<E>();
		front = 0;
		rear = 0;
		nelems = 0;
		this.capacity = capacity;
		for(int i = 0; i<capacity; i++)
		{
			array.add(null);
		}
	}
	/* Returns the capacity of this BoundedDeque, that is,
	 * the maximum number of elements it can hold.*/
	public int capacity()
	{
		return capacity;
	}
	/*Returns the number of elements in this BoundedDeque.*/
	public int size()
	{
		return nelems;
	}
	/* Adds the specified element to the front of this BoundedDeque.
     * Returns true if the operation succeeded, else false.*/
	public boolean addFront(E e) throws NullPointerException
	{
		if(e == null) throw new NullPointerException();
		if(nelems == capacity)
		{
			return false;
		}
		if(nelems != capacity)
		{
			front = (front - 1 + capacity)%capacity;
			array.set(front,e);
			nelems++;
		}
		return true;
		
	}
	/* Adds the specified element to the tail of this BoundedDeque.
     * Returns true if the operation succeeded, else false.*/
	public boolean addBack(E e) throws NullPointerException
	{
		if(e == null) throw new NullPointerException();
		if(nelems == capacity)
		{
			return false;
		}
		if(nelems != capacity)
		{
			array.set(rear,e);
			rear = (rear + 1)%capacity;
			nelems++;
		}
		return true;
	}
	/* Removes the element at the front of this BoundedDeque.
	 * Returns the element removed, or <tt>null</tt> if there was no such element.*/
	public E removeFront()
	{
		if(nelems>0)
		{
			E e = array.get(front);
			array.set(front,null);
			front = (front + 1)%capacity;
			nelems--;
			return e;
		}
		else
		{
			return null;
		}
	}
	/* Removes the element at the tail of this BoundedDeque.
	 * Returns the element removed, or <tt>null</tt> if there was no such element.*/
	public E removeBack()
	{
		if(nelems>0)
		{
			E e = array.get((rear-1 + capacity)%capacity);
			array.set((rear-1 + capacity)%capacity,null);
			rear = ((rear - 1 + capacity)%capacity);
			nelems--;
			return e;
		}
		else
		{
			return null;
		}
	}
	/* Returns the element at the front of this BoundedDeque,
	 * or <tt>null</tt> if there was no such element.*/
	public E peekFront()
	{
		if(nelems == 0)
		{
			return null;
		}
		else
		{
			E e = array.get(front);
			return e;
		}
	}
	/* Returns the element at the tail of this BoundedDeque,
	 * or <tt>null</tt> if there was no such element.*/
	public E peekBack()
	{
		
		if(nelems == 0)
		{
			return null;
		}
		E e = array.get((rear - 1 + capacity)%capacity);
		return e;
	}
}
