import junit.framework.* ; 

import java.util.*;

/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/
public class Heap12Tester extends TestCase {
	private Heap12<Integer> emptyMin;
	private Heap12<Integer> oneMin;
	private Heap12<Integer> severalMin;
	private Heap12<Integer> fullMin;
	private Heap12<Integer> emptyMax;
	private Heap12<Integer> oneMax;
	private Heap12<Integer> severalMax;
	private Heap12<Integer> fullMax;
	public Heap12Tester()
	{
		super();
	}

	/**
	 * Creates lists that are empty, have one element, and have several elements*/
	public void setUp()
	{
		emptyMin = new Heap12<Integer>();
		emptyMax = new Heap12<Integer>(true);
		oneMin = new Heap12<Integer>();
		oneMax = new Heap12<Integer>(true);
		severalMin = new Heap12<Integer>();
		severalMax = new Heap12<Integer>(true);
		fullMin = new Heap12<Integer>();
		fullMax = new Heap12<Integer>(true);
		oneMin.offer(1);
		oneMax.offer(1);
		for(int i = 0; i < 3; i++)
		{
			severalMin.offer(i);
		}
		for(int i = 2; i>=0; i--)
		{
			severalMax.offer(i);
		}
		for(int i = 0; i < 5; i++)
		{
			fullMin.offer(i);
		}
		for(int i = 4; i>=0; i--)
		{
			fullMax.offer(i);
		}
	}
	/**
	 * Tests if the size is correct
	 */
	public void testSize() {
		assertEquals(0,emptyMin.size());
		assertEquals(0,emptyMax.size());
		assertEquals(1,oneMin.size());
		assertEquals(1,oneMax.size());
		assertEquals(3,severalMin.size());
		assertEquals(3,severalMax.size());
		assertEquals(5,fullMin.size());
		assertEquals(5,fullMax.size());
	}

	/**
	 * Tests if the capacity is correct
	 */
	public void testCapacity() {
		assertEquals(5,emptyMin.capacity());
		assertEquals(5,emptyMax.capacity());
		assertEquals(5,oneMin.capacity());
		assertEquals(5,oneMax.capacity());
		assertEquals(5,severalMin.capacity());
		assertEquals(5,severalMax.capacity());
		assertEquals(5,fullMin.capacity());
		assertEquals(5,fullMax.capacity());
		fullMin.offer(5);
		fullMax.offer(5);
		assertEquals(10,fullMin.capacity());
		assertEquals(10,fullMax.capacity());
	}

	/**
	 * Tests if the constructor correctly sets max/minheaps
	 */
	public void testHeap12SetisMax() {
		assertTrue(!oneMin.isMax());
		assertTrue(oneMax.isMax());
		assertTrue(!severalMin.isMax());
		assertTrue(severalMax.isMax());
	}

	/**
	 * Tests if the correct capacity is set
	 */
	public void testHeap12SetCapacity() {
		Heap12<Integer> capacity10 = new Heap12<Integer>(10,false);
		assertEquals(10,capacity10.capacity());
	}


	/**
	 * Tests the methods used in the iterator
	 */
	public void testIterator() {
		Iterator<Integer> severalMinIter = severalMin.iterator();
		Iterator<Integer> severalMaxIter = severalMax.iterator();
		assertTrue(severalMinIter.hasNext());
		assertTrue(severalMaxIter.hasNext());
		severalMinIter.next();
		severalMinIter.next();
		severalMaxIter.next();
		severalMaxIter.next();
		assertEquals(new Integer(2), severalMinIter.next());
		assertEquals(new Integer(0), severalMaxIter.next());
		Iterator<Integer> fullMinIter = fullMin.iterator();
		Iterator<Integer> fullMaxIter = fullMax.iterator();
		fullMinIter.next();
		fullMinIter.remove();
		assertEquals(new Integer(3), fullMinIter.next());
		fullMaxIter.next();
		fullMaxIter.remove();
		assertEquals(new Integer(1), fullMaxIter.next());
		
	}

	/**
	 * Tests the peek method
	 */
	public void testPeek() {
		assertEquals(null,emptyMin.peek());
		assertEquals(null,emptyMax.peek());
		assertEquals(new Integer(1),oneMin.peek());
		assertEquals(new Integer(1),oneMax.peek());
		assertEquals(new Integer(0),severalMin.peek());
		assertEquals(new Integer(2),severalMax.peek());
		assertEquals(new Integer(0),fullMin.peek());
		assertEquals(new Integer(4),fullMax.peek());
	}

	/**
	 * Tests the poll method
	 */
	public void testPoll() {
		assertEquals(null,emptyMin.poll());
		assertEquals(null,emptyMax.poll());
		oneMin.poll();
		oneMax.poll();
		assertEquals(null,oneMin.peek());
		assertEquals(null,oneMax.peek());
		severalMin.poll();
		severalMax.poll();
		assertEquals(new Integer(1),severalMin.peek());
		assertEquals(new Integer(1),severalMax.peek());
	}

	/**
	 * Tests the offer method
	 */
	public void testOffer() {
		emptyMin.offer(1);
		emptyMax.offer(1);
		assertEquals(new Integer(1),emptyMin.peek());
		assertEquals(new Integer(1),emptyMax.peek());
		oneMin.offer(2);
		oneMax.offer(0);
		assertEquals(new Integer(1),oneMin.peek());
		assertEquals(new Integer(1),oneMax.peek());
		oneMin.offer(0);
		oneMax.offer(2);
		assertEquals(new Integer(0),oneMin.peek());
		assertEquals(new Integer(2),oneMax.peek());
		fullMin.offer(-1);
		fullMax.offer(5);
		assertEquals(new Integer(-1),fullMin.peek());
		assertEquals(new Integer(5),fullMax.peek());
	}
	
	/**
	 * Checks NoSuchElementException for the iterator
	 */
	public void testIteratorAllowNext()
	{
		Iterator<Integer> oneMinIter = oneMin.iterator();
		oneMinIter.next();
		try
		{
			oneMinIter.next();
		}
		catch(NoSuchElementException e)
		{
			
		}
	}
	
	/**
	 * Tests for IllegalStateException in the iterator
	 */
	public void testIteratorAllowRemove()
	{
		Iterator<Integer> severalMinIter = severalMin.iterator();
		try
		{
			severalMinIter.remove();
		}
		catch(IllegalStateException e)
		{
			
		}
	}
	
	/**
	 * Tests for NullPointerException in the offer method
	 */
	public void testOfferNullPointer()
	{
		try
		{
			oneMax.offer(null);
		}
		catch(NullPointerException e)
		{
			
		}
	}
	

}
