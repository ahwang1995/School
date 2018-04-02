import java.util.*;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/
public class Queue12<E> implements BoundedQueue<E> {

	private Deque12<E> queue;
	/* Constructor to create queue12 with specified capacity using Deque12*/
	public Queue12(int capacity)
	{
		queue = new Deque12<E>(capacity);
	}
	/* Returns the capacity of this BoundedQueue, that is,
	 * the maximum number of elements it can hold.*/
	public int capacity()
	{
		return queue.capacity();
	}
	/*Returns the number of elements in this BoundedQueue.*/
	public int size()
	{
		return queue.size();
	}
	/* Adds the specified element to the tail of this BoundedQueue.
     * Returns true if the operation succeeded, else false.*/
	public boolean enqueue(E e)
	{
		return queue.addBack(e);
	}
	/* Removes the element at the front of this BoundedQueue.
	 * Returns the element removed, or <tt>null</tt> if there was no such element.*/
	public E dequeue()
	{
		return queue.removeFront();
	}
	/* Returns the element at the front of this BoundedQueue,
	 * or <tt>null</tt> if there was no such element.*/
	public E peek()
	{
		return queue.peekFront();
	}
}
