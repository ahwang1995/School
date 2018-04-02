import junit.framework.* ; 
import java.util.*;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/
public class BoundedDequeTester extends TestCase{
	private BoundedDeque<Integer> empty;
	private BoundedDeque<Integer> one;
	private BoundedDeque<Integer> several;
	private BoundedDeque<Integer> full;
	private BoundedDeque<String> slist;
	
	public BoundedDequeTester()
	{
		super();
	}
	/**
	 * Creates lists that are empty, have one element, several elements,
	 * and carries Strings as the setup
	 */
	public void setUp()
	{
		empty = new Deque12<Integer>(12);
		one = new Deque12<Integer>(12);
		one.addFront(1);
		several = new Deque12<Integer>(12);
		for(int i = 0; i<5; i++)
		{
			several.addFront(i);
		}
		full = new Deque12<Integer>(12);
		for(int i = 0; i<13; i++)
		{
			full.addFront(i);
		}
		slist = new Deque12<String>(12);
		slist.addFront("a");
		slist.addFront("b");
	}

	/**
	 * Tests the capacity method
	 */
	public void testCapacity()
	{
		assertEquals(12, empty.capacity());
		assertEquals(12,one.capacity());
	}
	/**
	 * Tests for the correct size/nelems
	 */
	public void testSize()
	{
		assertEquals(0,empty.size());
		assertEquals(1,one.size());
	}
	/**
	 * Tests if the addFront method works
	 */
	public void testAddFront()
	{
		one.addFront(5);
		assertEquals(new Integer(5), one.peekFront());
		assertEquals(new Integer (1),one.peekBack());
	}
	/**
	 * Tests for NullPointerExcepetion when trying add to a full list
	 * from the front
	 */
	public void testFullAddFront()
	{
		try
		{
			full.addFront(10);
		}
		catch(NullPointerException e)
		{
			
		}
	}
	/**
	 * Tests for NullPointerException when adding a null to the front
	 */
	public void testNullAddFront()
	{
		try
		{
			one.addFront(null);
		}
		catch(NullPointerException e)
		{
			
		}
	}
	/**
	 * Tests the addBack method
	 */
	public void testAddBack()
	{
		empty.addBack(1);
		one.addBack(2);
		assertEquals(new Integer(1), empty.peekBack());
		assertEquals(new Integer(2), one.peekBack());
	}
	/**
	 * Tests for NullPointerExcepetion when trying add to a full list
	 * from the back
	 */
	public void testFullAddBack()
	{
		try
		{
			full.addBack(10);
		}
		catch(NullPointerException e)
		{
			
		}
	}
	/**
	 * Tests for NullPointerException when adding a null to the back
	 */
	public void testNullAddBack()
	{
		try
		{
			one.addBack(null);
		}
		catch(NullPointerException e)
		{
			
		}
	}
	/**
	 * Tests the peekFront method
	 */
	public void testPeekFront()
	{
		assertEquals(null, empty.peekFront());
		assertEquals(new Integer(1), one.peekFront());
		assertEquals(new Integer(4), several.peekFront());
	}
	/**
	 * Tests the PeekBack method
	 */
	public void testPeekBack()
	{
		assertEquals(null, empty.peekBack());
		assertEquals(new Integer(1), one.peekBack());
		assertEquals(new Integer(0), several.peekBack());
	}
	/**
	 * Tests if the stringlist works
	 */
	public void testStringList()
	{
		assertEquals("b", slist.peekFront());
		assertEquals("a", slist.peekBack());
	}
	/**
	 * Tests the removeFront method
	 */
	public void testRemoveFront()
	{
		one.removeFront();
		assertEquals(null, one.peekFront());
		several.removeFront();
		assertEquals(new Integer(3), several.peekFront());
	}
	/**
	 * Tests the removeBack method
	 */
	public void testRemoveBack()
	{
		one.removeBack();
		assertEquals(null, one.peekBack());
		several.removeBack();
		assertEquals(new Integer(1), several.peekBack());
	}
}