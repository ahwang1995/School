import junit.framework.* ;
import java.util.*;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/
/**
 *  Title: class MyLinkedListTester
 *  Description: JUnit test class for LinkedList class
 *  @author Andrew Hwang
 */
public class MyLinkedListTester extends TestCase
{
  private LinkedList<Integer> empty ;
  private LinkedList<Integer> one ;
  private LinkedList<Integer> several ;
  private LinkedList<String>  slist ;
  private LinkedList<Integer> several2;
  static final int DIM = 5;
  static final int FIBMAX = 30;

  public MyLinkedListTester()
  {
    super() ;
  }
  /**
   * Standard Test Fixture. An empty list, a list with one entry (0) and 
   * a list with several entries (0,1,2)
   */ 
  public void setUp()
  {
    empty = new LinkedList<Integer>();
    one = new LinkedList<Integer>();
    one.add(0,new Integer(0));
    several = new LinkedList<Integer>() ;
    // List: 1,2,3,...,Dim
    for (int i = DIM; i > 0; i--)
    	several.add(0,new Integer(i));
    
    several2 = new LinkedList<Integer>();
    for (int i = DIM; i > 0; i--)
    	several2.add(0,new Integer(i));
    // List: "First","Last"
    slist = new LinkedList<String>();
    slist.add(0,"First");
    slist.add(1,"Last");
  }
  /** Test if heads of the lists are correct */
  public void testGetHead()
  {
    assertEquals("Check 0",new Integer(0),one.get(0)) ;
    assertEquals("Check 0",new Integer(1),several.get(0)) ;
  }

  /** Test if size of lists are correct */
  public void testListSize()
  {
    assertEquals("Check Empty Size",0,empty.size()) ;
    assertEquals("Check One Size",1,one.size()) ;
    assertEquals("Check Several Size",DIM,several.size()) ;
  }

  /** Test setting a specific entry */
  public void testSet()
  {
    slist.set(1,"Final");
    assertEquals("Setting specific value", "Final",slist.get(1));
  }

  /** Test isEmpty */
  public void testEmpty()
  {
    assertTrue("empty is empty",empty.isEmpty()) ;
    assertTrue("one is not empty",!one.isEmpty()) ;
    assertTrue("several is not empty",!several.isEmpty()) ;
  }

  /** Test iterator on empty list and several list */
  public void testIterator()
  {
    int counter = 0 ;
    ListIterator<Integer> iter;
    for (iter = empty.listIterator() ; iter.hasNext(); )
    {
      fail("Iterating empty list and found element") ;
    }
    counter = 0 ;
    for (iter = several.listIterator() ; iter.hasNext(); iter.next())
	counter++;
    assertEquals("Iterator several count", counter, DIM);
  }

  /** Test out of bounds exception on get */
  public void testGetIOException()
  {
	try 
	{
		empty.get(0);
		fail("Should have generated an exception");
	}
	catch(IndexOutOfBoundsException e)
	{
		//  normal
	}
  }

  /** test Iterator Fibonacci */
  public void testIteratorFibonacci()
  {
	LinkedList<Integer> fib  = new LinkedList<Integer>();
	ListIterator<Integer> iter;
	// List: 0 1 1 2 3 5 8 13 ... 
	// Build the list with integers 1 .. FIBMAX
	int t, p = 0, q = 1;
	fib.add(0,p);
	fib.add(1,q);
	for (int k = 2; k <= FIBMAX; k++)
	{
		t = p+q;
		fib.add(k,t);
		p = q; q = t; 
	}
	// Now iterate through the list to near the middle, read the
	// previous two entries and verify the sum.
	iter = fib.listIterator();
	int sum = 0;
	for (int j = 1; j < FIBMAX/2; j++)
		sum = iter.next();
	iter.previous();
	assertEquals(iter.previous() + iter.previous(),sum);
	// Go forward with the list iterator
	assertEquals(iter.next() + iter.next(),sum);
  }
  /**test if iterator remove method*/
  public void testIteratorRemove()
  {
	  LinkedList<Integer> asdf = new LinkedList<Integer>();
	  ListIterator<Integer> iter;
	  for (int i = 5; i > 0; i--)
	  {
	    asdf.add(0,new Integer(i));
	  }
	  iter = asdf.listIterator();
	  iter.next();
	  iter.next();
	  iter.next();
	  iter.remove();
	  assertEquals(new Integer(4),iter.next());
	  iter.previous();
	  assertEquals(new Integer(2),iter.previous());
  }
  /**test if add changes list size*/
  public void testListSizeChange()
  {
	  assertEquals(1,one.size());
	  one.add(5);
	  assertEquals(2,one.size());
	  one.remove(1);
  }
  /**Test IOb exception for remove method*/
  public void testRemoveIOBException()
  {
	  try
	  {
		  several.remove(10);
	  }
	  catch(IndexOutOfBoundsException e)
	  {
		  
	  }
  }
  /**test IOB exception for add method*/
  public void testAddIOBException()
  {
	  try
	  {
		  empty.add(3,1);
		  fail("Should have generated an exception");
	  }
	  catch(IndexOutOfBoundsException e)
	  {
	  }
  }
  /**test IOB exception for set method*/
  public void testSetIOBException()
  {
	  try
	  {
		  empty.set(3,1);
		  fail("Should have generated an exception");
	  }
	  catch(IndexOutOfBoundsException e)
	  {
		  
	  }
  }
  /**test the values of the end of the list*/
  public void testGetTail()
  {
	  assertEquals("Check last", new Integer(0), one.get(one.size()-1));
	  assertEquals("Check last", new Integer(5), several.get(several.size()-1));
  }
  /**Test to see if the get method returns the correct values*/
  public void testGet()
  {
	  assertEquals("First",slist.get(0));
	  assertEquals("Last",slist.get(1));
	  assertEquals(new Integer(2), several.get(1));
  }
  /**test if the add method with no index parameter properly
   * adds to the end of the list*/
  public void testAddLast()
  {
	  slist.add("Hello");
	  assertEquals("add last","Hello", slist.get(2));
	  several.remove(2);
  }
  /**test the remove method*/
  public void testRemove()
  {
	  one.add(1);
	  one.remove(1);
	  assertEquals("Check if removed",1,one.size());
  }
  /**test the clear method*/
  public void testClear()
  {
	  several2.clear();
	  assertEquals("Check if cleared",0,several2.size());
  }
  /**Test the add method with a specified index*/
  public void testAddAt()
  {
	  several.add(2, 4);
	  assertEquals("check index added",new Integer(4),several.get(2));
	  assertEquals("check next index",new Integer(3),several.get(3));
	  assertEquals("check previous index",new Integer(2),several.get(1));
	  several.remove(2);
  }
}
