import java.util.*;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/
public class Stack12<E> implements BoundedStack<E> {

	private Deque12<E> stack;
	/* Constructor to create stack12 with specified capacity using Deque12*/
	public Stack12(int capacity)
	{
		stack = new Deque12<E>(capacity);
	}
	/* Returns the capacity of this BoundedStack, that is,
	 * the maximum number of elements it can hold.*/
	public int capacity()
	{
		return stack.capacity();
	}
	/*Returns the number of elements in this BoundedStack.*/
	public int size()
	{
		return stack.size();
	}
	/* Adds the specified element to the front of this BoundedStack.
     * Returns true if the operation succeeded, else false.*/
	public boolean push(E e)
	{
		return stack.addFront(e);
	}
	/* Removes the element at the front of this BoundedStack.
	 * Returns the element removed, or <tt>null</tt> if there was no such element.*/
	public E pop()
	{
		return stack.removeFront();
	}
	/* Returns the element at the front of this BoundedStack,
	 * or <tt>null</tt> if there was no such element.*/
	public E peek()
	{
		return stack.peekFront();
	}
}
